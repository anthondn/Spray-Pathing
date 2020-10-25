#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Int32.h>

ros::Publisher pub_laser;

void clbk_laser(const sensor_msgs::LaserScan::ConstPtr &msg) {
  ROS_INFO("Here is Laser Scan Subscribe");

  pub_laser.publish(*msg);

}

int main(int argc, char **argv) {

  ros::init(argc, argv, "laser_node");

  ros::NodeHandle n;

  ros::Subscriber sub_laser = n.subscribe("/scan", 1, clbk_laser);

  pub_laser = n.advertise<sensor_msgs::LaserScan>("mylaser_topic", 1);

  ros::spin();
}