#!/usr/bin/env python
import roslib; roslib.load_manifest('dla_weclewa')
import rospy

def calkowanie_program():
    rospy.init_node('calkowanie_program')
    info = rospy.Subscriber('/vel', geometry_msgs::Twist)
    pub = rospy.Publisher('/odom', Integer)
    while not rospy.is_shutdown():
        time=rospy.get_time()
        pozycja=(info.data[0]*time
        rospy.loginfo(pozycja) 
        pub.publish(Integer(pozycja))
        rospy.sleep(1.0)    

if __name__ == '__main__':
    calkowanie_program()
