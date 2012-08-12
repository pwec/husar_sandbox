#include<dead_reckoning.h>

DeadReckoningCore::DeadReckoningCore(ros::NodeHandle *n)
{
  // Initialise node parameters from launch file or command line.
  // Use a private nsode handle so that multiple instances of the node can be run simultaneously
  // while using different parameters.
  ros::NodeHandle private_node_handle("~");
  //example of parameters handling
  private_node_handle.param("rate", rate_, int(1));

  //register publisher in ROS system
  odom_pub_ = n->advertise<nav_msgs::Odometry>("odom", 1000);

  //register subscriber in ROS system and allow to handle every received message by twistCallback function
  twist_sub_ = n->subscribe("vels", 1, &DeadReckoningCore::twistCallback, this);

  //initialization of variables
  odom_.pose.pose.position.x = 0.0;
  odom_.pose.pose.position.y = 0.0;
  odom_.pose.pose.position.z = 0.0;

  last_time_ = ros::Time::now();
}

DeadReckoningCore::~DeadReckoningCore()
{

}

void DeadReckoningCore::twistCallback(const geometry_msgs::TwistConstPtr& msg)
{
  //compute period for integral time
  double dt = (ros::Time::now() - last_time_).toSec();
  last_time_ = ros::Time::now();

  //velocities intergal over time
  odom_.pose.pose.position.x += msg->linear.x*dt;
  odom_.pose.pose.position.y += msg->linear.y*dt;
  odom_.pose.pose.position.z += msg->linear.z*dt;

  //publish odometry
  odom_pub_.publish(odom_);
}

//-----------------------------------------MAIN------------------------------------
int main(int argc, char **argv)
{
  //set up ROS.
  ros::init(argc, argv, "daed_reckoning");
  ros::NodeHandle n;

  //create your node core object - everything is initialized in class constructor...
  DeadReckoningCore *cam_core = new DeadReckoningCore(&n);
  //write anything on screen
  ROS_INFO("Initialized");

  //until you process and publish data only in callBacks you need this one line below (asynchronous processing)
  ros::spin();

  //however if you need 'infinite' loop processing comment line above and uncomment code below (synchronous processing)
  /*
   //frequency for main loop processing in Hz
   ros::Rate r(cam_core->rate_);

   // Main 'infinite' loop.
   while (n.ok())
   {
   //any functions to process data
   cam_core->process();

   ros::spinOnce();
   r.sleep();
   }
   */
  return 0;
}

