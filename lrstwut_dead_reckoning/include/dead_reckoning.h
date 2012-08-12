/**
 * @file   dead_reckoning.h
 * @Author Piotr Weclewski (weclewski.piotr@gmail.com)
 * @date   August, 2012
 * @brief  Declaration of ROS node core class for dead reckoning
 *
 * Detailed description of file.
 */

#ifndef DEADRECKONINGCORE_CORE_H_
#define DEADRECKONINGCORE_CORE_H_

//roscpp includes
#include "ros/ros.h"
#include "ros/time.h"

//msgs includes
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"

/**
 * @class DeadReckoningCore
 *
 * @brief This is example class for ROS node
 *
 * This class is a core class of node for subscribing velocities form robot and publishing dead reckoning position
 *
 * This is original description of this block - to get some knowledge about this type of documentation:
 * This comment block is @e required for all class declarations.
 * Please remove comments that are bracketed by [..]. These comments are there
 * to provide instructions to developers while writing their code.
 * Obvious member variables and functions, such as get and set routines and
 * default constructors and destructors, should not be documented as this
 * clutters the files. Use standard C++ comments for those comments you wish
 * Doxygen to ignore. If the class has many members - you may consider
 * providing separate public, protected, private sections for member functions
 * and member variables to improve readability. In addition it may be useful to
 * form member groups preceded by a header as shown below.
 *
 * Please note that the \$Header\$ keyword specified below is a RCS keyword,
 * and will inflate into the version, name, etc for this file.
 *
 * @author Piotr Weclewski
 *
 * $Header $
 */
class DeadReckoningCore
{
public:
  //! public constructor
  DeadReckoningCore(ros::NodeHandle *_n);
  //! public destructor
  virtual ~DeadReckoningCore();

  //! field for store node frequency rate
  int rate_;

private:

  //!time from last loop
  ros::Time last_time_;

  //!subscribers handle
  ros::Subscriber twist_sub_;

  //!publishers handle
  ros::Publisher odom_pub_;

  //!object of odometry message
  nav_msgs::Odometry odom_;

  /**
   * @name    twistCallback
   * @brief   Callback function for handling received Twist messages
   * @ingroup example
   *
   * This is only example description showing how to use eg. latex in documentation:
   * Here is an example of inserting a mathematical formula into the text:
   * The distance is computed as /f$\sqrt{ (x_2-x_1)^2 + (y_2 - y_1)^2 }/f$
   * If we wanted to insert the formula centered on a separate line:
   * /f[
   * \sqrt{ (x_2-x_1)^2 + (y_2 - y_1)^2 }
   * /f]
   * Please note that all formulas must be valid LaTeX math-mode commands.
   * Additionally, to be processed by Doxygen, the machine used must have
   * LaTeX installed. Please see the Doxygen manual for more information
   * about installing LaTeX locally.
   *
   * @param [in] msg received message constant pointer
   *
   * @retval none
   *
   * Example Usage:
   * @code
   *    twist_sub_ = n->subscribe("vels", 1, &DeadReckoningCore::twistCallback, this);//in this case it is not necessary for callBacks
   * @endcode
   */
  void twistCallback(const geometry_msgs::TwistConstPtr& msg);

};

#endif /* DEADRECKONINGCORE_CORE_H_ */
