// Copyright 2020 The Kobi Company. All Rights Reserved.
// CONFIDENTIAL. AUTHORIZED USE ONLY. DO NOT REDISTRIBUTE.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreorder"
#pragma GCC diagnostic ignored "-Wswitch"
#include <rs_driver/api/lidar_driver.h>
#pragma GCC diagnostic pop


using namespace robosense::lidar;

struct PointXYZI  ///< user defined point type
{
  double x;
  double y;
  double z;
  double intensity;
};

/**
 * @description: The point cloud callback function. This funciton will be registered to lidar driver.
 *              When the point cloud message is ready, driver can send out message through this function.
 * @param msg  The lidar point cloud message.
 */
void pointcloudCallback(const PointcloudMsg<PointXYZI>& msg)
{
  /* Note: Please do not put time-consuming operations in the callback function! */
  /* Make a copy of the message and process it in another thread is recommended*/
  std::cout << "msg: " << msg.seq << " pointcloud size: " << msg.pointcloud_ptr->size() << std::endl;
}

/**
 * @description: The exception callback function. This function will be registered to lidar driver.
 * @param code The error code struct.
 */
void exceptionCallback(const Error& code)
{
  /* Note: Please do not put time-consuming operations in the callback function! */
  /* Make a copy of the error message and process it in another thread is recommended*/
  std::cout << "Error code : " << code.toString() << std::endl;
}

int main(int argc, char* argv[])
{
  std::cout << "\033[1m\033[35m"
            << "------------------------------------------------------" << std::endl;
  std::cout << "            RS_Driver Core Version: V " << RSLIDAR_VERSION_MAJOR << "." << RSLIDAR_VERSION_MINOR << "."
            << RSLIDAR_VERSION_PATCH << std::endl;
  std::cout << "\033[1m\033[35m"
            << "------------------------------------------------------"
            << "\033[0m" << std::endl;

  LidarDriver<PointXYZI> driver;  ///< Declare the driver object

  RSDriverParam param;                  ///< Creat a parameter object
  param.input_param.msop_port = 6699;   ///< Set the lidar msop port number the default 6699
  param.input_param.difop_port = 7788;  ///< Set the lidar difop port number the default 7788
  param.lidar_type = LidarType::RS16;   ///< Set the lidar type. Make sure this type is correct!
  param.print();

  driver.regExceptionCallback(exceptionCallback);   ///< Register the exception callback funtion into the driver
  driver.regRecvCallback(pointcloudCallback);  ///< Register the point cloud callback funtion into the driver
  if (!driver.init(param))                          ///< Call the init funtion and pass the parameter
  {
    std::cout << "Driver Initialize Error..." << std::endl;
    return 0;
  }
  driver.start();  ///< Call the start funtion. The driver thread will start.

  std::cout << "RoboSense Lidar-Driver Linux pcap demo start......" << std::endl;
  while (true)
  {
    sleep(1);
  }

  return 0;
}
