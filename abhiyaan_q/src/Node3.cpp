#include "ros/ros.h"
#include "std_msgs/String.h"
#include <bits/stdc++.h>


std::string str = "";

void Msg_1_callback(const std_msgs::String::ConstPtr& msg)
{
  //getting message from team_abiyaan
  str = msg->data;
}

void Msg_2_callback(const std_msgs::String::ConstPtr& msg)
{
  //getting message from autonomy
  str = str + " : "+ msg->data;
  ROS_INFO("[%s]", str.c_str());
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Node3");

  
  ros::NodeHandle n;

  //Subscribing to team_abiyaan and autonomy
  ros::Subscriber team_abhiyaan_sub = n.subscribe("team_abhiyaan", 1000, Msg_1_callback);
  ros::Subscriber autonomy_sub = n.subscribe("autonomy", 1000, Msg_2_callback);
  

 
  ros::spin();

  return 0;
}
