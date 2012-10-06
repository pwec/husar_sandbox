#ifndef System3d_H
#define	System3d_H

#include "pmdCam/pmd_settings.h"
#include "pmdCam/image_box.h"
#include "pmdCam/data_flow.h"


#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/image_encodings.h>
//#include "std_msgs/Empty.h"
//#include <visualization_msgs/Marker.h>
//#include <tf/transform_broadcaster.h>

// PCL specific includes
#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
//#include <pcl/filters/radius_outlier_removal.h>

// OpenCV includes
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/calib3d/calib3d.hpp"

#include <cstdlib>
#include <vector>
#include <string>

#include <cassert> // makro sprawdzające

using namespace std;
using namespace cv;
using namespace pcl;

#define IMG_WIDTH 64
#define IMG_HEIGHT 50

/**
  * @class System3d
  * @brief IFM camera and webcamera model class.
  */
class System3d {

public:
    System3d();
    ~System3d();

    /**
     * Main class action method.
     * Reads data from IFM camera, receives signals, converts data to PCL and ROS format
     */
    void executeCalibratedSystem();

    /**
     * Callback to new IFM camera matrices.
     * @param msg ROS message from IFMcam node
     */
    void setIFMcamImages(pmdCam::image_box msg);

    /**
     * Callback to new webcamera image.
     * @param msg ROS image message from webcamera node
     */
    void setWebcamImage(sensor_msgs::Image msg);

    /**
      * Generate point cloud based on system data.
      * @return ROS point cloud data
      */
    PointCloud<PointXYZRGB> generateCloud();

    /**
      * Generate point cloud based on dual camera system data.
      * @return ROS point cloud data
      */
    PointCloud<PointXYZRGB> generateColorCloud();

    /**
     * Save calibration data to file.
     * @param filename data file (need *.xml extension)
     */
    void saveCalibrationXML(string filename = "xmldata.xml");

    /**
     * Read calibration data from file.
     * @param filename data file (need *.xml extension)
     */
    void calibrateCamerasFromXMLfile(string filename = "xmldata.xml");

    /**
     * Search for chessboard pattern on images.
     */
    void collectPoints();

    /**
      * System state indicator.
      */
    bool isCalibrated();

    /**
      * Clear all calibration data vectors.
      */
    void clearCalibrationData();

    /**
      * Accept temporary chessboard points coordinates and add them to the main vector.
      */
    void acceptChessboardImages();

    /**
     * Cameras calibration procedure.
     */
    void calibrateCameras();

public:
    Mat pmdGrayImage, pmdDepthImage, webcamImage, webcamImageTmp;
    Mat pmdChessImage, webcamChessImage;
    Mat pmdTmp, webTmp;
    Mat undistortPMD, undistortWebcam;

    int patternCount;

private:
    int scale;
    PointCloud<PointXYZRGB> cloud;
    bool calibrated;

    /**
      * List of chessboard corners coordinates in webcam view.
      */
    vector<vector<Point2f> > webcamPoints;

    /**
      * List of chessboard corners coordinates in IFMcam view.
      */
    vector<vector<Point2f> > pmdPoints;

    vector<Point2f> pmdCorners, webcamCorners;
    vector<Point3f> chessboardPointsWebcam;
    vector<Point3f> chessboardPointsPMDcam;

    /**
      * Auxiliary variable useful in cloud generation.
      */
    int cloud_width;
    int cloud_height;

    /**
      * Calibration data.
      */
    Mat cameraMatrix1, distCoeffs1;
    vector<Mat> rvecs1, tvecs1;
    Mat cameraMatrix2, distCoeffs2;
    vector<Mat> rvecs2, tvecs2;
    Mat offset;

private:

    /**
     * Read calibration data from file.
     * @param filename data file (need *.xml extension)
     */
    void readCalibrationXML(string filename = "xmldata.xml");

    /**
     * Search for chessboard on the image.
     * @param image input image(need to be CV_8U)
     * @return vector of found point coordinates.
     */
    vector<Point2f> findChessboard(Mat image);

    // @author M. Przybylski
    void calculateOffset(std::vector<cv::Mat>& camera1_matrices,
            std::vector<cv::Mat>& camera2_matrices, cv::Mat& offset);

    // @author M. Przybylski
    void calculateOffset(std::vector<cv::Mat>& rvecs1,
                        std::vector<cv::Mat>& tvecs1,
                        std::vector<cv::Mat>& rvecs2,
                        std::vector<cv::Mat>& tvecs2,
                        cv::Mat& offset );

    // @author M. Przybylski
    void rodriguesTo4x4Matrix(cv::Mat& rvec, cv::Mat& tvec, cv::Mat& transformation);
};

#endif	/* System3d_HPP */

