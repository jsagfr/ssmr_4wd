#include "ros/ros.h"
#include "ssmr_4wd/Motors.h"
#include "MotorCapeListener.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "beaglebone_motor_cape");
  ros::NodeHandle n;
  

  MotorCapeListener motor_cape{"/dev/i2c-2"};
  
  ros::Subscriber sub = n.subscribe("motors", 1000, &MotorCapeListener::callback, &motor_cape);
  ros::spin();

  return 0;
}
