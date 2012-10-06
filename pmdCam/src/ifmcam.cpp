
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
    ros::init (argc, argv,"pmd_camera");
    ros::NodeHandle nh;
    ros::Rate loop_rate(30); // execute frequency
    ROS_INFO("IFMcam working...");

    o3dcam camera;

    // get new IFM sensor settings
    ros::Subscriber settings_sub;
    string settings_topic = "pmdcam_settings";
    settings_sub = nh.subscribe(settings_topic, 1, &o3dcam::cameraSettings_cb, &camera );

    // publish sensor data as images
    ros::Publisher sensor_pub;
    string sensor_topic = "pmdcam_images";
    sensor_pub = nh.advertise<pmdCam::image_box> (sensor_topic, 1);

    camera.connectToSensor();

    pmdCam::image_box imageBox;
    cv_bridge::CvImage img[2];
    img[0].encoding="32FC1";
    img[1].encoding="32FC1";

    namedWindow("gray", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);
    namedWindow("depth", CV_GUI_EXPANDED || CV_WINDOW_KEEPRATIO || CV_WINDOW_NORMAL);

    int counter = 0;
    while (ros::ok())
    {
        string msg;
        stringstream ss;
        ss << "IFMoffline || package No. :  " << counter;
        msg = ss.str();
        ss.flush();
        ROS_INFO("%s", msg.c_str());

        camera.readSensor();
        camera.obtainImages();

        img[0].image = camera.getGrayImage();
        img[1].image = camera.getDepthImage();

        img[0].toImageMsg(imageBox.img1);
        img[1].toImageMsg(imageBox.img2);
        sensor_pub.publish(imageBox);

        sensor_pub.publish(imageBox);
        imshow("gray", camera.getGrayImage());
        imshow("depth", camera.getDepthImage());
        waitKey(3);

        ros::spinOnce();
        loop_rate.sleep();
        ++counter;
    }

    // save sensor data to file
    if(argv[1] != NULL)
    {
        string filename = argv[1];
        camera.saveData(filename);
    }

    return 0;
}
