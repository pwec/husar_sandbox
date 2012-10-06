#include "system3d.hpp"

System3d::System3d()
{
    scale = 3;

    // initiate Mat images
    //pmdGrayImage = Mat::zeros(scale*IMG_HEIGHT, scale*IMG_WIDTH, CV_32F);
    pmdGrayImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_32F);
    pmdDepthImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_32F);
    webcamImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8UC3);

    pmdChessImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8U);
    webcamChessImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8U);
    webcamImageTmp = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8UC3);

    pmdTmp = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8U);
    webTmp = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8UC3);

    undistortPMD = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_32F);
    undistortWebcam = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_8UC3);

    // calibration matrices
    offset = Mat::zeros(4,4,CV_64F);

    // cloud parameters
    cloud.width = scale*IMG_WIDTH;
    cloud.height = scale*IMG_HEIGHT;
    cloud.points.resize (cloud.width*cloud.height);

    cloud_width = cloud.width;
    cloud_height = cloud.height;

    // chessboard pattern points coordinate
    for (int i=0; i<4; i++)
        for (int j=0; j<3; j++)
            chessboardPointsWebcam.push_back(Point3f(i*0.0988, j*0.0994, 0)); // poziomo - 9.94 cm, pionowo - 9.88 cm

    /*
    for (int i=0; i<4; i++)
        for (int j=0; j<3; j++)
            chessboardPointsPMDcam.push_back(Point3f(i*0.0988*scale, j*0.0994*scale, 0));
    */

    calibrated = false;
    patternCount = 0;
}

System3d::~System3d()
{}

void System3d::setIFMcamImages(pmdCam::image_box msg)
{
    cout << "setting IFM camera images...\n";
    cv_bridge::CvImagePtr cv_ptr[2];
    cv_ptr[0] = cv_bridge::toCvCopy(msg.img1, sensor_msgs::image_encodings::TYPE_32FC1 );
    cv_ptr[1] = cv_bridge::toCvCopy(msg.img2, sensor_msgs::image_encodings::TYPE_32FC1 );

    Mat tmpGray, tmpGray2, tmpDepth;
    cv_ptr[0]->image.copyTo(tmpGray);
    cv_ptr[1]->image.copyTo(tmpDepth);

    normalize(tmpGray, tmpGray2, 1, 0, NORM_INF);
    resize(tmpGray2, pmdGrayImage, Size(scale*tmpGray.size().width, scale*tmpGray.size().height), 0, 0, INTER_CUBIC);
    resize(tmpDepth, pmdDepthImage, Size(scale*tmpDepth.size().width, scale*tmpDepth.size().height), 0, 0, INTER_CUBIC);
}

void System3d::setWebcamImage(sensor_msgs::Image msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    //webcamImageTmp = cv_ptr->image;
    Mat tmpImage, tmpImage2;
    transpose(cv_ptr->image, tmpImage2);
    flip(tmpImage2, tmpImage, 1);

    Size imgSize(8*IMG_HEIGHT, 8*IMG_WIDTH);

    //Rect area( imgSize.width, 0, imgSize.height);
    int rowStart = 50;
    int colStart = 0;
    Range row(rowStart, rowStart + imgSize.height);
    Range col(colStart, colStart + imgSize.width);

    webcamImageTmp = tmpImage(row, col);
}

bool System3d::isCalibrated()
{
    return calibrated;
}

void System3d::clearCalibrationData()
{
    calibrated = false;
    webcamPoints.clear();
    pmdPoints.clear();
    pmdCorners.clear();
    webcamCorners.clear();
}

PointCloud<PointXYZRGB> System3d::generateCloud()
{
    cloud.points.clear();
    // fill cloud with received data
    for(int j=0; j<cloud_height; j++)
    {
        for(int k=0; k<cloud_width; k++)
        {
            float x = k - cloud_width/2;
            float y = j - cloud_height/2;
            float z = pmdDepthImage.at<float>(k,j)*100; // mnożnik?
            float i = pmdGrayImage.at<float>(k,j)*255;

            uint8_t var = uint8_t(i);
            int32_t rgb = (var << 16) | (var << 8) | var;

            PointXYZRGB pt;
            pt.x = x;
            pt.y = y;
            pt.z = z;
            pt.rgb = *reinterpret_cast<float*>(&rgb);

            cloud.push_back(pt);
        }
    }
    return cloud;
}

PointCloud<PointXYZRGB> System3d::generateColorCloud()
{
    Mat webSizeMatched;
    int scale = 3;
    resize(webcamImageTmp, webSizeMatched, Size(scale*IMG_HEIGHT, scale*IMG_WIDTH), 0, 0, INTER_CUBIC);

    cloud.points.clear();
    // fill cloud with received data
    for(int j=0; j<cloud_height; j++)
    {
        for(int k=0; k<cloud_width; k++)
        {
            float x = k - cloud_width/2;
            float y = j - cloud_height/2;
            float z = pmdDepthImage.at<float>(k,j)*100; // mnożnik?
            //float i = pmdGrayImage.at<float>(k,j)*255;

            uint8_t r = webSizeMatched.at<cv::Vec3b>(k,j)[0];
            uint8_t g = webSizeMatched.at<cv::Vec3b>(k,j)[1];
            uint8_t b = webSizeMatched.at<cv::Vec3b>(k,j)[2];
            int32_t rgb = (r << 16) | (g << 8) | b;

            PointXYZRGB pt;
            pt.x = x;
            pt.y = y;
            pt.z = z;
            pt.rgb = *reinterpret_cast<float*>(&rgb);

            cloud.push_back(pt);
        }
    }
    return cloud;
}

void System3d::calibrateCamerasFromXMLfile(string filename)
{
    readCalibrationXML(filename);
    calibrateCameras();
}

void System3d::saveCalibrationXML(string filename)
{
    if(filename.length() > 5)
    {
        if( filename.substr(filename.length()-4) == ".xml" )
        {
            FileStorage xmlfile(filename, FileStorage::WRITE);

            xmlfile << "chessboard_pattern_parameters" << "{" << "horizontal" << 0.0988 << "vertical" << 0.0994 << "}" ;

            if( pmdPoints.size() == webcamPoints.size() )
            {
                xmlfile << "detected_corners" << "[";
                for(int i=0; i<pmdPoints.size(); i++)
                {
                    xmlfile << "{" << "IFMcam_corners" << "[" << pmdPoints[i] << "]";
                    xmlfile << "webcam_corners" << "[" << webcamPoints[i] << "]" << "}";

                }
                xmlfile << "]";
            }

            xmlfile.release();
        }
        else cout << "Error: wrong file name\n";
    }
    else cout << "Error: wrong file name\n";
}

void System3d::readCalibrationXML(string filename)
{
    if(filename.length() > 5)
    {
        if( filename.substr(filename.length()-4) == ".xml" )
        {
            pmdPoints.clear();
            webcamPoints.clear();
            patternCount = 0;

            cout << "opening file \"" << filename << "\" in progress...";
            FileStorage xmlfile(filename, FileStorage::READ);

            FileNode chessboardNode = xmlfile["chessboard_pattern_parameters"];
            float vertical = (float)chessboardNode["vertical"];
            float horizontal = (float)chessboardNode["horizontal"];

            FileNode IFMcamNode = xmlfile["detected_corners"];
            FileNodeIterator it = IFMcamNode.begin(), it_end = IFMcamNode.end();
            int idx = 0;

            // iterate through a sequence using FileNodeIterator
            for( ; it != it_end; ++it, idx++ )
            {
                vector<Point2f> pts_pmd;
                (*it)["IFMcam_corners"] >> pts_pmd;
                pmdPoints.push_back(pts_pmd);

                vector<Point2f> pts_web;
                (*it)["webcam_corners"] >> pts_web;
                webcamPoints.push_back(pts_web);
            }
            xmlfile.release();

            patternCount = idx;

            // write points coordinates
            cout << "\n*****************************************************\n";
            for(int k=0; k<pmdPoints.size(); k++)
            {
                cout << "pmd feature #" << k << ": ";
                cout << "\n( ";
                for(int i=0; i<pmdPoints[k].size(); i++)
                {
                    cout << pmdPoints[k][i].x << " " << pmdPoints[k][i].y << " || ";
                }
                cout << ")\n";
            }

            // write points coordinates
            cout << "\n*****************************************************\n";
            for(int k=0; k<webcamPoints.size(); k++)
            {
                cout << "web feature #" << k << ": ";
                cout << "\n( ";
                for(int i=0; i<webcamPoints[k].size(); i++)
                {
                    cout << webcamPoints[k][i].x << " " << webcamPoints[k][i].y << " || ";
                }
                cout << ")\n";
            }
        }
        else cout << "Error: wrong file name\n";
    }
    else cout << "Error: wrong file name\n";
}

void System3d::acceptChessboardImages()
{
    string info;
    stringstream ss;
    ss << "pmdCamServer || acceptImages " <<  ros::Time::now();
    info = ss.str();
    ss.flush();
    ROS_INFO("%s", info.c_str());

    if( !( pmdCorners.empty() && webcamCorners.empty() ))
    {
        /*
        vector<Point2f> pmdCornersTrue;
        for(int i=0; i<pmdCorners.size(); i++)
            pmdCornersTrue.push_back( Point2f( pmdCorners[i].x*scale, pmdCorners[i].y*scale ) );

        pmdPoints.push_back(pmdCornersTrue);
        */

        pmdPoints.push_back(pmdCorners);
        webcamPoints.push_back(webcamCorners);

        string file;
        stringstream ss1;

        ss1 << "pmd_img/pmd" << patternCount << ".png";
        file = ss1.str();
        ss1.flush();
        imwrite(file, pmdTmp);

        stringstream ss2;
        ss2 << "web_img/web" << patternCount << ".png";
        file = ss2.str();
        ss2.flush();
        imwrite(file, webTmp);

        patternCount++;
    }
}

vector<Point2f> System3d::findChessboard(Mat image)
{
    Size patternSize(3,4);
    vector<Point2f> corners;
    bool found = findChessboardCorners(image, patternSize,
            corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS | CALIB_CB_FAST_CHECK);
    if(found)
    {
        cornerSubPix(image, corners, Size(11, 11), Size(-1, -1),
                TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));

        drawChessboardCorners(image, patternSize, Mat(corners), found);
    }
    return corners;
}

void System3d::collectPoints()
{
    vector<Point2f> corners_pmd, corners_webcam;
    Mat tmp;
    Mat pmdChessTmp, webcamChessTmp;

    // find chessboard on webcam image
    webcamImage = webcamImageTmp;
    webTmp = webcamImage;
    cvtColor(webcamImage, webcamChessTmp, CV_RGB2GRAY);
    corners_webcam = findChessboard(webcamChessTmp);

    // find chessboard on pmdcam image
    pmdGrayImage.convertTo(pmdChessTmp, CV_8U, 255);
    pmdChessTmp.copyTo(pmdTmp);
    GaussianBlur(pmdChessTmp, tmp, Size(0,0), 3);
    addWeighted(pmdChessTmp, 1.2, tmp, -0.2, 0, pmdChessTmp);
    corners_pmd = findChessboard(pmdChessTmp);

    // if chessboard found on both images
    // save images with chessboard and add points coordinates do vector
    if(!corners_pmd.empty() && !corners_webcam.empty())
    {
        cout << "collect pmd & web: " << patternCount << "\n";

        pmdChessImage = pmdChessTmp;
        webcamChessImage = webcamChessTmp;

        webcamCorners = corners_webcam;
        pmdCorners = corners_pmd;
    }
}


void showMat(Mat img)
{
    for(int row=0; row<img.size().height; row++)
    {
        for(int col=0; col<img.size().width; col++)
            cout << img.at<double>(row, col) << "\t\t\t";
        cout << "\n";
    }
    cout << "\n";
}

void System3d::calibrateCameras()
{
    cout << "collected calibration images: " << patternCount <<"\n";
    //chessboardPattern.assign(patternCount, chessboardPoints);

    if(patternCount>0)
    {
        vector <vector <Point3f> > chessboarPatternWebcam (patternCount, chessboardPointsWebcam);
        vector <vector <Point3f> > chessboarPatternPMDcam (patternCount, chessboardPointsWebcam /*chessboardPointsPMDcam*/);

        double webCalibVal =  calibrateCamera(chessboarPatternWebcam, webcamPoints, webcamImage.size(),
                                              cameraMatrix1, distCoeffs1, rvecs1, tvecs1);
        cout << "webCalibVal: " << webCalibVal << "\n";

        double pmdCalibVal =  calibrateCamera(chessboarPatternPMDcam, pmdPoints, /*Size(IMG_HEIGHT, IMG_WIDTH)*/ pmdGrayImage.size(),
                                              cameraMatrix2, distCoeffs2, rvecs2, tvecs2);
        cout << "pmdCalibVal: " << pmdCalibVal << "\n";

        calculateOffset(rvecs1, tvecs1, rvecs2, tvecs2, offset);
        //calculateOffset(rvecs2, tvecs2, rvecs1, tvecs1, offset);

        cout << "offset matrix:\n\n";
        showMat(offset);

        cout << "CameraMatrix1:\n\n";
        showMat(cameraMatrix1);

        calibrated = true;
    }
}

void System3d::executeCalibratedSystem()
{
    // check variable calibrated
    // obtain undistorted IFMcam and webcam images
    undistort(pmdGrayImage, undistortPMD, cameraMatrix2, distCoeffs2);
    undistort(webcamImage, undistortWebcam, cameraMatrix1, distCoeffs1);

    cout.setf(ios::fixed);
    cout.precision(4);

    Mat matrix = Mat::zeros(4,1,CV_64F);
    Mat u = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_64F);
    Mat v = u; //Mat::zeros(IMG_WIDTH, IMG_HEIGHT, CV_64F);
    for(int x=0; x<u.size().height; x++)
    {
        matrix.at<double>(0,0) = x;
        for(int y=0; y<u.size().width; y++)
        {
            matrix.at<float>(1,0) = y;
            double depth = double(cloud.at(x,y).z);
            matrix.at<double>(2,0) = depth;
            Mat matrix2 = offset*matrix;
            double div = matrix2.at<double>(2,0);
            Mat matrix3 = matrix2/div;
            Mat matrix4 = matrix3.rowRange(0,3);
            Mat matrix5 = cameraMatrix1*matrix4;

            double tmpVal = matrix5.at<double>(0,0);
            u.at<double>(x,y) = tmpVal;
            tmpVal = matrix5.at<double>(1,0);
            v.at<double>(x,y) = tmpVal;
        }
    }

    /*
    //Mat img = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_64F);
    combinedImage = Mat::zeros(scale*IMG_WIDTH, scale*IMG_HEIGHT, CV_16U);
    for(int x=0; x<cloud_width; x++)
    {
        for(int y=0; y<cloud_height; y++)
        {
            int val;
            int X = int(u.at<double>(x,y));
            int Y = int(v.at<double>(x,y));
            if(X<0 || X>cloud_width || Y<0 || Y>cloud_height) val = 255;
            else val = webcamImage.at<uchar>(X,Y);
            //int val = web.at<int>(x,y);
            combinedImage.at<uchar>(y,x) = val;// = val;
        }
    }
    */
}

/*
void System3d::offlineChessboardImages(int val)
{
    for(int i=0; i<val; i++)
    {
        cout << "file: " << i << "\n";
        string file;
        stringstream ss;
        ss << "pmd_img/pmd" << i << ".png";
        file = ss.str();
        ss.flush();
        Mat tmp;
        pmdGrayImage = imread(file,0);
        //tmp = imread(file,0);
       // tmp.convertTo(pmdGrayImage, CV_32F, 1/255);
        pmdGrayImage.convertTo(tmp, CV_32F);
        normalize(tmp, pmdGrayImage, 1, 0, NORM_INF);

        stringstream ss2;
        ss2 << "web_img/web" << i << ".png";
        file = ss2.str();
        ss2.flush();
        webcamImageTmp = imread(file,-1);

        collectPoints();
        acceptChessboardImages();
    }
    //calibrateCameras();
}
*/

//******************************************************************************

/*
 * File:   CameraOffset.cpp
 * Author: maciek
 *
 * Created on 15 lipiec 2011, 15:42
 */

void System3d::calculateOffset(std::vector<cv::Mat>& camera1_matrices,
        std::vector<cv::Mat>& camera2_matrices, cv::Mat& offset)
{
    cout << "calculate offset\n";

    assert(camera1_matrices.size() == camera2_matrices.size());

    offset = cv::Mat::zeros(4,4,CV_64F);

    cv::Mat inv_camera2(4,4,CV_64F);

    cv::Mat transformation = cv::Mat::zeros(4,4,CV_64F);

    for(int i=0; i<camera1_matrices.size(); i++)
    {
        cv::invert(camera2_matrices[i],inv_camera2);

        transformation = inv_camera2 * camera1_matrices[i];
//        transformation = camera2_matrices[i] * camera1_matrices[i];
//        showMat(camera1_matrices[i]);
//        cout << "\n";
//        showMat(camera2_matrices[i]);
//        cout << "\n";
//                showMat(inv_camera2);
//                cout << "\n";

//            showMat(transformation);
//            cout << "\n";

        offset += transformation;

//        showMat(offset);
//        cout << "\n";
    }

    offset /= camera1_matrices.size();

    cv::Mat rotation_matrix(3,3,CV_64F);

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            rotation_matrix.at<double>(i,j) = offset.at<double>(i,j);

    showMat(rotation_matrix);

    cv::SVD svd(rotation_matrix);

    svd.w = cv::Mat::eye(3,3,CV_64F);

    rotation_matrix = svd.u * svd.w * svd.vt;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            offset.at<double>(i,j) = rotation_matrix.at<double>(i,j);

        offset.at<double>(3,i) = 0.0;
    }

    offset.at<double>(3,3) = 1.0;
}

void System3d::rodriguesTo4x4Matrix(cv::Mat& rvec, cv::Mat& tvec, cv::Mat& transformation ) // need transpose?
{
    cv::Mat rotation(3,3,CV_64F);

    //cv::Mat inv_camera_matrix(3,3,CV_64F);

    cv::Rodrigues(rvec,rotation);

    cv::Mat rotZPI = cv::Mat::eye(4,4,CV_64F);
    rotZPI.at<double>(0,0) = -1.0;
    rotZPI.at<double>(1,1) = -1.0;

    for(int k=0;k<3;k++)
    {
        for(int l=0;l<3;l++)
            transformation.at<double>(k,l) = rotation.at<double>(k,l);

        transformation.at<double>(k,3) = tvec.at<double>(0,k);

        transformation.at<double>(3,k) = 0.0;
    }

    transformation.at<double>(3,3) = 1.0;

    transformation = rotZPI * transformation;
//    transformation.inv();
        //showMat(transformation);

/*
    cout << "transformation\n";
    for(int row=0; row<transformation.size().width; row++)
    {
        for(int col=0; col<transformation.size().height; col++)
            cout << transformation.at<double>(row, col) << "\t\t\t";
        cout << "\n";
    }
*/

}

void System3d::calculateOffset(std::vector<cv::Mat>& rvecs1,
                    std::vector<cv::Mat>& tvecs1,
                    std::vector<cv::Mat>& rvecs2,
                    std::vector<cv::Mat>& tvecs2,
                    cv::Mat& offset )
{

    std::vector<cv::Mat> camera1_matrices;
    std::vector<cv::Mat> camera2_matrices;

    for(int i=0; i<rvecs1.size(); i++)
    {
        Mat tmp1 = Mat::zeros(4,4, CV_64F);
        Mat tmp2 = Mat::zeros(4,4, CV_64F);
        camera1_matrices.push_back(tmp1);
        camera2_matrices.push_back(tmp2);

        //cout << "rodriguesTo4x4Matrix 1 loop: " << i << "\n";
        rodriguesTo4x4Matrix(rvecs1[i],tvecs1[i],camera1_matrices[i]);
        //cout << "rodriguesTo4x4Matrix 2 loop: " << i << "\n";
        rodriguesTo4x4Matrix(rvecs2[i],tvecs2[i],camera2_matrices[i]);
    }

    calculateOffset(camera1_matrices, camera2_matrices, offset);
}
