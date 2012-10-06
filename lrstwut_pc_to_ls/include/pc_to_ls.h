/*
 * @file pc_to_ls.cpp
 *
 * @Author: Łukasz Godziejewski (lgodziejewski@gmail.com)
 * @date   Sep 28, 2012
 * @brief  Declaration of ROS node core class for PointCloud to LaserScan conversion
 *
 * Detailed description of file.
 */

#ifndef PC_TO_LS_H_
#define PC_TO_LS_H_

//roscpp includes
#include "ros/ros.h"
#include "ros/time.h"

//msgs includes
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @class PcToLsCore
 * @brief Main class for the PointCloud to LAserScan conversion node
 */
class PcToLsCore
{
public:
  //! public constructor
	PcToLsCore(ros::NodeHandle *_n);
  //! public destructor
  virtual ~PcToLsCore();

  //! field for storing node frequency rate
  int rate_;

private:

  //!subscribers handle
  ros::Subscriber pointcloud2_sub_;

  //!publishers handle
  ros::Publisher laserscan_pub_;

  //!object of laserscan message
  sensor_msgs::LaserScan scan_;

  // handling incoming message
  void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg);

};

#endif /* PC_TO_LS_H_ */
