#!/usr/bin/env python
import math
import roslib; roslib.load_manifest('dla_weclewa')
import rospy

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry


def setvelocity():
	rospy.init_node('setvelocity')  # activating "setvelocity" node 
	pub = rospy.Publisher('/vel', Twist)  #setting publisher on /vel topic and type geometry_msgs::Twist
	v = Twist([0,0,0],[0,0,0])  #setting null values
	r = rospy.Rate(2.0) # set frequency to 2Hz


	while not rospy.is_shutdown():
	        t=rospy.get_time()     # getting time ellapsed since node has been turned on
	        
		v.linear[0]+=math.sin(3.14*t) #some fake data
		v.linear[1]+=0.05
		v.linear[2]+=math.cos(3.14*t)

		rospy.loginfo(v) # logging data
	        pub.publish(v) # publishing data
                r.sleep() # activating rate

if __name__ == '__main__':
    setvelocity()
