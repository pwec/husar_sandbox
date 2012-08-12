#include"dead_reckoning.h"

//-----------------------------------------MAIN----------------------------------
int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "daed_reckoning");
  ros::NodeHandle n;

  // Create a new NodeExample object.
  DeadReckoningCore *cam_core = new   DeadReckoningCore(&n);

  ros::Rate r(cam_core->rate_);

  ros::spin();

/*
  // Main loop.
  while (n.ok())
  {
	  cam_core->process();
	  //ros::spinOnce();
	  r.sleep();
  }
*/

  return 0;
}

