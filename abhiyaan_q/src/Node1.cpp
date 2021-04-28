#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Node1");

  
  ros::NodeHandle n;

  //makeing Node1 publisher to topic team_abhiyaan
  ros::Publisher team_abhiyaan_pub = n.advertise<std_msgs::String>("team_abhiyaan", 1000);

  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {
    
    std_msgs::String msg;

    msg.data = "Team Abiyaan";

    ROS_INFO("%s", msg.data.c_str());

   //Publishing 
    team_abhiyaan_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
