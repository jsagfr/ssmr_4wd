#include "ros/ros.h"
#include "ssmr_4wd/Motors.h"
#include "MotorBridgeCape.h"
#include <string>

class MotorCapeListener
{
public:
  MotorCapeListener(const std::string& i2cPath);
  void callback(const ssmr_4wd::Motors::ConstPtr& msg);

private:
  MotorBridgeCape motor_cape;
  DCMotor* motor1A;
  DCMotor* motor2A;
  DCMotor* motor1B;
  DCMotor* motor2B;
};

