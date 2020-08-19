// Copyright 2020 The Kobi Company. All Rights Reserved.
// CONFIDENTIAL. AUTHORIZED USE ONLY. DO NOT REDISTRIBUTE.
#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreorder"
#pragma GCC diagnostic ignored "-Wswitch"
#include <rs_driver/api/lidar_driver.h>
#pragma GCC diagnostic pop

namespace robosense {

inline lidar::RSDriverParam bPearlConfig() {
  lidar::RSDriverParam driver_param;
  driver_param.frame_id        = "rslidar";
  driver_param.lidar_type      = lidar::LidarType::RSBP;
  driver_param.use_lidar_clock = false;
  driver_param.wait_for_difop  = true;

  // Communication configuration.
  driver_param.input_param.device_ip  = "192.168.1.200";
  driver_param.input_param.msop_port  = 6699;
  driver_param.input_param.difop_port = 7788;

  // Decode lidar message configuration.
  driver_param.decoder_param.max_distance     = 30.0f;
  driver_param.decoder_param.min_distance     = 0.1f;
  driver_param.decoder_param.start_angle      = 0.0f;
  driver_param.decoder_param.end_angle        = 360.0f;
  driver_param.decoder_param.mode_split_frame = 1;
  driver_param.decoder_param.num_pkts_split   = 1;
  driver_param.decoder_param.cut_angle        = 0.0f;
  return std::move(driver_param);
};

}  // namespace robosense
