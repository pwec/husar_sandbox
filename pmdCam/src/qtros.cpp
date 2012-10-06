#include "qtros.h"
QtROS::QtROS(int argc, char *argv[], const char* node_name) {
  std::cout << "Initializing Node...\n";
  ros::init(argc, argv, node_name);
  n = new ros::NodeHandle;
  ROS_INFO("Connected to roscore");
  quitfromgui = false; }

void QtROS::quitNow(){ 
  quitfromgui = true; }

void QtROS::run(){ 
  ros::Rate r(30);
  while(ros::ok() && !quitfromgui) {
    ros::spinOnce(); 
    r.sleep();}
  if (!quitfromgui) {
    emit rosQuits();
    ROS_INFO("ROS-Node Terminated\n"); }}
