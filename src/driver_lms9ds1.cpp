#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

float delta() {
  return 2.0 * static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 1.0;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu>("imu/data", 1000);

  ros::Rate loop_rate(96);

  sensor_msgs::Imu msg;
  
  while (ros::ok())
  {
    msg.header.stamp = ros::Time::now();
    msg.header.seq++;
    
    msg.orientation.x += delta();
    msg.orientation.y += delta();
    msg.orientation.z += delta();
    msg.orientation.w += delta();
    // msg.orientation_covariance += delta() / 100.0;

    msg.angular_velocity.x += delta();
    msg.angular_velocity.y += delta();
    msg.angular_velocity.z += delta();
    // msg.angular_velocity_covariance += delta() / 100.0;

    msg.linear_acceleration.x += delta();
    msg.linear_acceleration.y += delta();
    msg.linear_acceleration.z += delta();
    // msg.linear_acceleration_covariance += delta() / 100.0;

    // ROS_INFO_STREAM("IMU: " << msg);

    imu_pub.publish(msg);

    // ros::spin();
    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
