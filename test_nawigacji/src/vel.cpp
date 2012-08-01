#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

/*
#####################Funny velocity generator######################
*/

int main(int argc, char** argv){
	ros::init(argc, argv, "vel");
	ros::NodeHandle n;
	ros::Publisher v_pub = n.advertise<geometry_msgs::Twist>("vel", 50);
	
	ros::Time current_time, last_time;
  	current_time = ros::Time::now();
  	last_time = ros::Time::now();
	
	geometry_msgs::Twist v;   //initial velocity
	v.linear.x=v.linear.y=v.linear.z=v.angular.x=v.angular.y=v.angular.z=0.0; //stupid, but works
	
	



	ros::Rate r(1.0);	

	while(ros::ok()){
		ros::spinOnce();      
    		current_time = ros::Time::now();
		float t = (current_time - last_time).toSec();
		v.linear.x= 2*exp(-t); //some values
		v.linear.y= exp(-t);
		v.linear.z= cos(t);

	
		v_pub.publish(v);
		ROS_INFO("Velocity sent");
		r.sleep();
 		}

	return 0;
}
