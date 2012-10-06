
#include "systemController.hpp"

SystemController::SystemController(ros::NodeHandle &nh)
{
    funcPointer = &SystemController::generatePointCloud;
    //funcPointer = &SystemController::generateCalibratedPointCloud;

    string cloud_topic = "pmd_cloud";
    cloud_pub = nh.advertise<sensor_msgs::PointCloud2> (cloud_topic, 1);

    transform.setOrigin( tf::Vector3(0, 0, 0) );
    transform.setRotation( tf::Quaternion(0, 0, 0) );

    string sensor_topic = "pmdcam_images";
    sensor_sub = nh.subscribe(sensor_topic, 1, &System3d::setIFMcamImages, &system3d );

    string image_topic = "system3d_images";
    img_pub = nh.advertise<pmdCam::image_box> (image_topic, 1);

    string calib_image_topic = "system3d_calibration_images";
    calib_img_pub = nh.advertise<pmdCam::image_box> (calib_image_topic, 1);

    string webcam_topic = "usb_cam/image_raw";
    webcam_sub = nh.subscribe(webcam_topic, 1, &System3d::setWebcamImage, &system3d );

    string data_flow_topic = "system3d_data_flow";
    data_flow_sub = nh.subscribe(data_flow_topic, 1, &SystemController::dataFlowController, this );
}

SystemController::~SystemController()
{}

void SystemController::dataFlowController(pmdCam::data_flow data_flow)
{
    if(data_flow.calibration_in_progress == true)
    {
        if(data_flow.accept_last_pair == true)
        {
            cout << "acceptChessboardImages\n";
            system3d.acceptChessboardImages();
        }
        else
        {
            cout << "calibration_in_progress\n";
            funcPointer = &SystemController::calibrationInProgress;
        }
    }
    else if(data_flow.perform_calibration == true)
    {
        cout << "calibrateCameras\n";
        system3d.calibrateCameras();
        if(system3d.isCalibrated()) funcPointer = &SystemController::generateCalibratedPointCloud;
        else funcPointer = &SystemController::generatePointCloud;
    }
    else
    {
        cout << "abort calibration\n";
        system3d.clearCalibrationData();
        funcPointer = &SystemController::generatePointCloud;
    }
}

void SystemController::executeApp()
{
    (this->*funcPointer)();
    publishSystemImages();
    //showSystemImages();
}

void SystemController::calibrationInProgress()
{
    cout << "calibrationInProgress\n";
    system3d.collectPoints();
    publishSystemCalibrationImages();
}

void SystemController::generateCalibratedPointCloud()
{
    cout << "generateCalibratedPointCloud\n";

    //system3d.executeCalibratedSystem();

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "pmd_cloud_frame"));

    toROSMsg(system3d.generateColorCloud(), cloud_msg);
    cloud_msg.header.frame_id = "pmd_cloud_frame";
    cloud_msg.header.stamp = ros::Time::now();
    cloud_pub.publish(cloud_msg);
}

void SystemController::generatePointCloud()
{
    cout << "generatePointCloud\n";

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "pmd_cloud_frame"));

    toROSMsg(system3d.generateCloud(), cloud_msg);
    cloud_msg.header.frame_id = "pmd_cloud_frame";
    cloud_msg.header.stamp = ros::Time::now();
    cloud_pub.publish(cloud_msg);
}

void SystemController::publishSystemImages()
{
    cout << "publishSystemImages\n";

    pmdCam::image_box imageBox;
    cv_bridge::CvImage img[3];
    img[0].encoding = "bgr8";
    for(int i=1; i<3; i++) img[i].encoding = "mono8";

    Mat pmdColorImage, pmdDepthColorImage, tmpImg, tmpWeb;
    system3d.pmdGrayImage.convertTo(pmdColorImage, CV_8U, 255);
    normalize(system3d.pmdDepthImage, tmpImg, 1, 0, NORM_INF);
    tmpImg.convertTo(pmdDepthColorImage, CV_8U, 255);

    int scale = 3;
    resize(system3d.webcamImageTmp, tmpWeb, Size(scale*IMG_HEIGHT, scale*IMG_WIDTH), 0, 0, INTER_CUBIC);

    img[0].image = tmpWeb;
    img[1].image = pmdColorImage;
    img[2].image = pmdDepthColorImage;

    img[0].toImageMsg(imageBox.img1);
    img[1].toImageMsg(imageBox.img2);
    img[2].toImageMsg(imageBox.img3);

    img_pub.publish(imageBox);

    //cv::imwrite("web1.png", system3d.webcamImageTmp);
}

void SystemController::publishSystemCalibrationImages()
{
    pmdCam::image_box calibrationImageBox;
    cv_bridge::CvImage calibImg[4];
    for(int i=0; i<4; i++) calibImg[i].encoding = "mono8";

    Mat webcamGrayImage, tmpImg;
    cvtColor(system3d.webcamImage, tmpImg, CV_RGB2GRAY);
    int scale = 3;
    resize(system3d.webcamImageTmp, webcamGrayImage, Size(scale*IMG_HEIGHT, scale*IMG_WIDTH), 0, 0, INTER_CUBIC);
    //resize(tmpGray2, pmdGrayImage, Size(scale*tmpGray.size().width, scale*tmpGray.size().height), 0, 0, INTER_CUBIC);
    Mat pmdGray;
    system3d.pmdGrayImage.convertTo(pmdGray, CV_8U, 255);

    calibImg[0].image = pmdGray;
    calibImg[1].image = system3d.pmdChessImage;
    calibImg[2].image = webcamGrayImage;
    calibImg[3].image = system3d.webcamChessImage;

    calibImg[0].toImageMsg(calibrationImageBox.img1);
    calibImg[1].toImageMsg(calibrationImageBox.img2);
    calibImg[2].toImageMsg(calibrationImageBox.img3);
    calibImg[3].toImageMsg(calibrationImageBox.img4);

    calib_img_pub.publish(calibrationImageBox);
}

void SystemController::showSystemImages()
{
    namedWindow("gray-img", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("depth-img", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("webcam-img", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("webcam-chessboard", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("pmdcam-chessboard", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("webcam-undistort", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("pmdcam-undistort", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);

    imshow("gray-img", system3d.pmdGrayImage);
    imshow("depth-img", system3d.pmdDepthImage);
    imshow("webcam-img", system3d.webcamImageTmp);
    imshow("webcam-chessboard", system3d.webcamChessImage);
    imshow("pmdcam-chessboard", system3d.pmdChessImage);

    if(system3d.isCalibrated())
    {
        namedWindow("webcam-undistort", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
        namedWindow("pmdcam-undistort", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
        imshow("webcam-undistort", system3d.undistortWebcam);
        imshow("pmdcam-undistort", system3d.undistortPMD);
    }

    waitKey(3);
}

void SystemController::calibrateCamerasFromXMLfile(string filename)
{
    system3d.calibrateCamerasFromXMLfile(filename);
    if(system3d.isCalibrated()) funcPointer = &SystemController::generateCalibratedPointCloud;
    else funcPointer = &SystemController::generatePointCloud;
}
