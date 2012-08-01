#!/usr/bin/env python
import math
import roslib; roslib.load_manifest('setvelocity')
import rospy

def setvelocity():
	rospy.init_node('setvelocity')  
	pub = rospy.Publisher('/vel', geometry_msgs::Twist)  #publisher
	v = geometry_msgs::Twist([0,0,0],[0,0,0])  
	r.rospy.Rate(2.0) //2Hz


	while not rospy.is_shutdown():
	        t=rospy.get_time()     #time
	        
		v.linear.x+=exp(-t) #some fake data
		v.linear.y+=0.05
		v.linear.z+=cos(3.14*t)
		v.angular.z+=0	
		rospy.loginfo(v)
	        pub.publish(v)
	        rospy.spin()

if __name__ == '__main__':
    setvelocity()
