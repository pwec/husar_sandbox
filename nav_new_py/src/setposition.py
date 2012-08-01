#!/usr/bin/env python
import roslib; roslib.load_manifest('setposition')
import rospy

def setposition():
	rospy.init_node('setposition')
	sub = rospy.Subscriber('/vel', geometry_msgs::Twist)  #subscriber
	pub = rospy.Publisher('/odom', nav_msgs::Odometry)  #publisher

	r.rospy.Rate(2.0) 	#2Hz - sending freq 
	t1 = rospy.get_time()

	while not rospy.is_shutdown():
	             //time
		t2 = rospy.get_time()
		dt = t1-t2
	        pos=nav_msgs::Odometry()
		#integration process
		v=sub.data[0]		#velo from subscriber
		pos.pose.position.x+=v.linear.x*dt #I assumed that we're interested in position...
		pos.pose.position.y+=v.linear.y*dt
		pos.pose.position.z+=v.linear.z*dt
		pos.pose.orientation.w+=v.angular.z*dt	
		rospy.loginfo(pos)
	        pub.publish(pos)
	        rospy.spin()
		
		t1=t2

if __name__ == '__main__':
    setposition()
