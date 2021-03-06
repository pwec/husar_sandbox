#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

/*
#####################Odometry######################
*/



void msgCallback(const geometry_msgs::Twist& msg){
    std::cout << "Callback" << std::endl;
 }



int main(int argc, char** argv){
	ros::init(argc, argv, "odom");
	ros::NodeHandle n;
	ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50); 
	ros::Subscriber odom_sub;
	tf::TransformBroadcaster odom_broadcaster; 

	geometry_msgs::Twist *v = new geometry_msgs::Twist();

	geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);
    	geometry_msgs::TransformStamped odom_trans;
	

	ROS_INFO("Initial position set");

	ros::Time current_time, last_time;
	current_time = ros::Time::now();
	last_time = ros::Time::now();
	ros::Rate r(1.0);

	while(ros::ok()){
		ros::spinOnce();   
		ROS_INFO("Velocity received");          // check for incoming messages
		current_time = ros::Time::now();
		odom_sub = n.subscribe("vel", 50, msgCallback); 

    		//compute odometry in a typical way given the velocities of the robot
		//as i understood, angular.z means what it meant in mechanics :P
		

		  double dt = (current_time - last_time).toSec();
    		  double delta_x = (v->linear.x * cos(odom_quat.w) - v->linear.y * sin(odom_quat.w)) * dt;
    		  double delta_y = (v->linear.x * sin(odom_quat.w) + v->linear.y * cos(odom_quat.w)) * dt;
   		  double delta_th = v->angular.z * dt;
    
    

    		odom_trans.header.stamp = current_time;
    		odom_trans.header.frame_id = "odom";
    		odom_trans.child_frame_id = "base_link";

    		odom_trans.transform.translation.x = x;
    		odom_trans.transform.translation.y = y;
    		odom_trans.transform.translation.z = 0.0;
    		odom_trans.transform.rotation = odom_quat;

    //send the transform
    	odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    	nav_msgs::Odometry odom;
    	odom.header.stamp = current_time;
    	odom.header.frame_id = "odom";

    	//set the position
    	odom.pose.pose.position.x = x;
    	odom.pose.pose.position.y = y;
    	odom.pose.pose.position.z = z;
    	odom.pose.pose.orientation = odom_quat;

    	//set the velocity
    	odom.child_frame_id = "base_link";
    	odom.twist.twist.linear.x = vx;
    	odom.twist.twist.linear.y = vy;
    	odom.twist.twist.angular.z = vth;

		
		ROS_INFO("Position calculated");
			
		odom_pub.publish(p);
		}
  return 0;
}

