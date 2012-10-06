#include<pc_to_ls.h>

PcToLsCore::PcToLsCore(ros::NodeHandle *n)
{
  // Initialise node parameters from launch file or command line.
  // Use a private node handle so that multiple instances of the node can be run simultaneously
  // while using different parameters.
  ros::NodeHandle private_node_handle("~");
  //example of parameters handling
  private_node_handle.param("rate", rate_, int(1));

  //register publisher in ROS system
  laserscan_pub_ = n->advertise<sensor_msgs::LaserScan>("pmd_scan", 1000);

  //register subscriber in ROS system and allow to handle every received message by twistCallback function
  pointcloud2_sub_ = n->subscribe("pmd_cloud", 1, &PcToLsCore::cloudCallback, this);

  //initialization of variables
}

void PcToLsCore::cloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg)
{


  //publish LaserScan
	laserscan_pub_.publish(scan_);
}

PcToLsCore::~PcToLsCore()
{

}


//-----------------------------------------MAIN------------------------------------
int main(int argc, char **argv)
{
  //set up ROS.
  ros::init(argc, argv, "pc_to_ls");
  ros::NodeHandle n;

  //create your node core object - everything is initialized in class constructor...
  PcToLsCore *cam_core = new PcToLsCore(&n);
  //write anything on screen
  ROS_INFO("Initialized");

  //until you process and publish data only in callBacks you need this one line below (asynchronous processing)
  ros::spin();

  //however if you need 'infinite' loop processing comment line above and uncomment code below (synchronous processing)
  /*
   //frequency for main loop processing in Hz
   ros::Rate r(cam_core->rate_);

   // Main 'infinite' loop.
   while (n.ok())
   {
   //any functions to process data
   cam_core->process();

   ros::spinOnce();
   r.sleep();
   }
   */
  return 0;
}
