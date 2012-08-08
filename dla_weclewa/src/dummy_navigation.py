#!/usr/bin/env python
import roslib; roslib.load_manifest('nawigacja')
import rospy

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
#from navigation import dummy_sensor

pub = rospy.Publisher('/odom', Odometry) # publishing on /odom topic
base_time= current_time=0.0
_x=_y=_z=0.0
pos = Odometry()


def callback(data):
    	global base_time
	global current_time
	global pos
	global _x
	global _y
	global _z
        # getting time elapsed since the start of node
	current_time=rospy.get_time()
        dtime = current_time-base_time # calculating time elapsed since last measurement
	rospy.loginfo(dtime)        

        #import velocities
        vx=data.linear.x
        vy=data.linear.y
        vz=data.linear.z
                
	# here is a section measuring the deltas of each position
        dx = vx * dtime
        dy = vy * dtime
        dz = vz * dtime

        # calculate current position
        _x += dx
        _y += dy
        _z += dz
        
        
        pos.pose.pose.position.x = _x
        pos.pose.pose.position.y = _y
        pos.pose.pose.position.z = _z
        pos.pose.pose.orientation.w = 0.0

        #publish current position
        rospy.loginfo(pos)
        pub.publish(pos)
	base_time = current_time

def calculate_position():
	global base_time	
	rospy.init_node('dummy_navigation') # setting node name
    	base_time = rospy.get_time() #setting base time and position values
	r = rospy.Rate(0.5)
	
	while not rospy.is_shutdown():
	        info = rospy.Subscriber('/vel', Twist, callback) #set subscriber and action
		r.sleep()

if __name__ == '__main__':
    	calculate_position()
  
	
