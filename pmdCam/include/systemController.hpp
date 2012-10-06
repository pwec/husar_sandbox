#ifndef SystemController_H
#define	SystemController_H

#include "pmdCam/pmd_settings.h"
#include "pmdCam/image_box.h"
#include "pmdCam/data_flow.h"

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
//#include "std_msgs/Empty.h"
//#include <visualization_msgs/Marker.h>
#include <tf/transform_broadcaster.h>

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

#include "system3d.hpp"

#include <cstdlib>
#include <vector>
#include <string>

#include "system3d.hpp"

using namespace std;
using namespace pcl;

/**
  * @class SystemController
  * @brief Bridge between ROS and System3d model.
  */
class SystemController {

public:
    /**
      * Constructor.
      */
    SystemController(ros::NodeHandle &nh);
    ~SystemController();

    /**
     * Subscriber to system data control signal.
     * @param msg
     */
    void dataFlowController(pmdCam::data_flow data_flow);

    /**
      * Class main function.
      */
    void executeApp();

    /**
      * Pointer to currently executed class working function.
      */
    void (SystemController::*funcPointer)();

    /**
      * Search for chessboard on images and publish calibration images.
      */
    void calibrationInProgress();

    /**
      * Computes and generates point cloud from calibrated system.
      */
    void generateCalibratedPointCloud();

    /**
      * Computes and generates point cloud.
      */
    void generatePointCloud();

    /**
      * Show all useful system images.
      */
    void showSystemImages();

    /**
      * Perform calibration based on file. Execute calibrated point cloud if possible.
      */
    void calibrateCamerasFromXMLfile(string filename);

private:
    /**
      * Publish system images to ROS.
      */
    void publishSystemImages();

    /**
      * Publish system calibration images to ROS.
      */
    void publishSystemCalibrationImages();

private:
    System3d system3d;

    sensor_msgs::PointCloud2 cloud_msg;
    tf::TransformBroadcaster br;
    tf::Transform transform;

    ros::Publisher cloud_pub;
    ros::Publisher img_pub;
    ros::Publisher calib_img_pub;

    ros::Subscriber data_flow_sub;
    ros::Subscriber sensor_sub;
    ros::Subscriber webcam_sub;
};

#endif	/* SystemController_HPP */

