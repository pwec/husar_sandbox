/**
 * Perform operations on system data received from sensor ROS node.
 */

#include <ros/ros.h>
#include <cstdlib>
#include "systemController.hpp"

using namespace std;
using namespace pcl;

int main (int argc, char** argv)
{
    // Initialize ROS
    ros::init (argc, argv,"pmd_server");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10); // execute frequency

    ROS_INFO("pmdCamServer working...");

    SystemController systemController(nh);

    if( argv[1] != NULL)
    {
        string filename = argv[1];
        systemController.calibrateCamerasFromXMLfile(filename);
    }

    int counter = 0;
    while (ros::ok())
    {
        string msg;
        stringstream ss;
        ss << "pmdCamServer  || package No. :  " << counter;
        msg = ss.str();
        ss.flush();
        ROS_INFO("%s", msg.c_str());

        systemController.executeApp();

        ros::spinOnce();
        loop_rate.sleep();
        ++counter;
    }

    return 0;
}
