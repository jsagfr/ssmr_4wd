#include "ros/ros.h"
#include "ssmr_4wd/Motors.h"
#include "MotorCapeListener.h"

MotorCapeListener::MotorCapeListener(const std::string& i2cPath):
  motor_cape(i2cPath)
{
  motor_cape.setDCMotorFrequency(1000);

  motor_cape.setChannel1(ChannelType::DcDc);
  motor_cape.setChannel2(ChannelType::DcDc);


  auto channelDcDc1 = static_cast<ChannelDcDc*>(motor_cape.getChannel1());
  auto channelDcDc2 = static_cast<ChannelDcDc*>(motor_cape.getChannel2());

  motor1A = dynamic_cast<DCMotor*>(channelDcDc1->getMotorA());
  motor1B = dynamic_cast<DCMotor*>(channelDcDc1->getMotorB());
  motor2A = dynamic_cast<DCMotor*>(channelDcDc2->getMotorA());
  motor2B = dynamic_cast<DCMotor*>(channelDcDc2->getMotorB());
  if (!motor1A || !motor1B || !motor2A || !motor2B) {
    // TODO: Throw an error!!!
  }
}

void MotorCapeListener::callback(const ssmr_4wd::Motors::ConstPtr& msg)
{
  motor1A->power(msg->front_left);
  motor2A->power(msg->front_right);
  motor1B->power(msg->rear_left);
  motor2B->power(msg->rear_right);
  ROS_INFO("Motors front: [%f  %f]", msg->front_left, msg->front_right);
  ROS_INFO("Motors rear : [%f  %f]", msg->rear_left, msg->rear_right);
  
}
