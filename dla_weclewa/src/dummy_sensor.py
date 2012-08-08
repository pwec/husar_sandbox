#!/usr/bin/env python

import roslib; roslib.load_manifest('nawigacja')
import rospy

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

import math

class DummySensor:
	"""
	Sends some fake velocity...
	"""
	def __init__(self):
		self.v = Twist() #initialized with zeros anyway
		self.pub = pub = rospy.Publisher('/vel', Twist) #setting publisher on /vel
		
	
	def publicVelocity(self) :
		t = rospy.get_time()
		self.v.linear.x = math.sin(t)
		self.v.linear.y = 0.0
		self.v.linear.z = math.cos(3*t)
		rospy.loginfo(self.v)
		self.pub.publish(self.v)
		r.sleep()

if __name__ == '__main__':
	rospy.init_node('dummy_sensor')
	r = rospy.Rate(0.5)
	sens = DummySensor()
	while not rospy.is_shutdown():		
		sens.publicVelocity()
		r.sleep()
	
