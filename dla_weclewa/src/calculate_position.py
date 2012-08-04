#!/usr/bin/env python
import roslib; roslib.load_manifest('dla_weclewa')
import rospy

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

def callback(data):
    
        current_time=rospy.get_time()    # getting time elapsed since the start of node
        dtime = current_time-base_time    # calculating time elapsed since last measurement
        
        #import velocities
        vx=data.data.linear[0]
        vy=data.data.linear[1]
        vz=data.data.linear[2]
                

        # here is a section measuring the deltas of each position

        dx = vx * dtime
        dy = vy * dtime
        dz = vz * dtime

        # calculate current position
        x += dx
        y += dy
        z += dz
        
        pos = Odometry()
        pos.pose.pose.position.x = x
        pos.pose.pose.position.y = y
        pos.pose.pose.position.z = z
        pos.pose.pose.orientation = 0

        #publish current position
        rospy.loginfo(pos) 
        pub.publish(Odometry(pos))

        t1=t2    # setting new base time 

def calculate_position():
    rospy.init_node('calculate_position')  # setting node name
    pub = rospy.Publisher('/odom', Odometry)    # publishing on /odom topic
    
    base_time = 0    #setting base time and position values
    x = 0
    y = 0
    z = 0
    while not rospy.is_shutdown():        
        info = rospy.Subscriber('/vel', Twist, callback)    #set subscriber and action

if __name__ == '__main__':
    calculate_position()
