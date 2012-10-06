/**
 * Perform operation on static data file.
 */

#include <ros/ros.h>
#include <cstdlib>

#include "o3dcam.hpp"
#include "pmdCam/pmd_settings.h"
#include "pmdCam/image_box.h"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main (int argc, char** argv)
{
    // Initialize ROS
    ros::init (argc, argv,"IFM_camera");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1); // execute frequency
    ROS_INFO("IFMcam working...");

    o3dcam camera;

    /*
    // get new IFM sensor settings
    ros::Subscriber settings_sub;
    string settings_topic = "pmdcam_settings";
    settings_sub = nh.subscribe(settings_topic, 1, &o3dcam::cameraSettings_cb, &camera );
    */

    // publish sensor data as images
    ros::Publisher sensor_pub;
    string sensor_topic = "pmdcam_images";
    sensor_pub = nh.advertise<pmdCam::image_box> (sensor_topic, 1);

    Mat gray, depth;
    pmdCam::image_box imageBox;
    cv_bridge::CvImage img[2];

    namedWindow("gray", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("depth", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);

    if( argv[1] != NULL)
    {
        string filename = argv[1];
        camera.readFile(filename);
        camera.obtainImages();
        depth = camera.getDepthImage();
        gray = camera.getGrayImage();

        img[0].image = gray;
        img[1].image = depth;

        img[0].encoding="32FC1";
        img[0].toImageMsg(imageBox.img1);
        img[1].encoding="32FC1";
        img[1].toImageMsg(imageBox.img2);
        sensor_pub.publish(imageBox);
    }
    else cout << "No specified file to read from \nClosing app...\n";

    int counter = 0;
    while (ros::ok() && argv[1]!=NULL)
    {
        string msg;
        stringstream ss;
        ss << "IFMoffline || package No. :  " << counter;
        msg = ss.str();
        ss.flush();
        ROS_INFO("%s", msg.c_str());

        sensor_pub.publish(imageBox);
        imshow("gray", gray);
        imshow("depth", depth);
        waitKey(3);

        ros::spinOnce();
        loop_rate.sleep();
        ++counter;
    }
    return 0;
}
