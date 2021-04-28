#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Node2");

  
  ros::NodeHandle n;

  //making Node2 publisher of autonomy  
  ros::Publisher autonomy_pub = n.advertise<std_msgs::String>("autonomy", 1000);

  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {
    
    std_msgs::String msg;

    msg.data = "Fueled by Autonomy";

    ROS_INFO("%s", msg.data.c_str());

    //Publishing
    autonomy_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
