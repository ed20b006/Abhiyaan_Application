#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "iostream"
float turtle1_x, turtle1_y, turtle2_x, turtle2_y;

void turtle1_pose(const turtlesim::Pose::ConstPtr& pos)
{
  //getting x,y from topic turtle1/pose
  turtle1_x = pos->x;
  turtle1_y = pos->y;
}

void turtle2_pose(const turtlesim::Pose::ConstPtr& pos)
{
  //getting x,y from topic turtle2/pose
  turtle2_x = pos->x;
  turtle2_y = pos->y;
}

int main(int argc, char **argv)
{
  float minDis = 0, dis = 0, safeDisY = 0, velocity = 0;
  std::cout << "Enter min distance : "; // getting min distance for overtaking
  std::cin >> minDis;
  std::cout << "Enter safe distance in y axis : "; //safe distance for overtake
  std::cin >> safeDisY;
  std::cout << "Velocity : "; //velocity of turtle
  std::cin >> velocity;
  ros::init(argc, argv, "Overtake");

  ros::NodeHandle n;
  //creating variables for publishing velocity of turtle
  ros::Publisher turtle2_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 100);
  
  //creating variables for subscribing to get turtle 1 & 2 postion
  ros::Subscriber turtel1_pose_sub = n.subscribe<turtlesim::Pose>("/turtle1/pose", 100, turtle1_pose);
  ros::Subscriber turtel2_pose_sub = n.subscribe<turtlesim::Pose>("/turtle2/pose", 100, turtle2_pose);

 

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    
    geometry_msgs::Twist vel;
    dis = abs(turtle1_x - turtle2_x);
    
    if(abs(turtle2_x - turtle1_x) < minDis && turtle2_y < turtle1_y + safeDisY)
    {
      vel.linear.x = 0.1;
      vel.linear.y = velocity;
    }else if(turtle2_y > turtle1_y && abs(turtle2_x - turtle1_x) > minDis)
    {
      vel.linear.x = 0.1;
      vel.linear.y = -velocity;
    }else
    {
      vel.linear.x = velocity;
      vel.linear.y = 0.0;
    }
    

    
    vel.linear.z = 0.0;
    vel.angular.x = 0.0;
    vel.angular.y = 0.0;
    vel.angular.z = 0.0;
  
    turtle2_vel_pub.publish(vel);
    

    ros::spinOnce();

    loop_rate.sleep();
  }

}


