cmake_minimum_required(VERSION 3.9)
project(robosense)

find_package(catkin REQUIRED COMPONENTS)

find_package(Boost COMPONENTS system REQUIRED)
find_package(pcap REQUIRED)

catkin_package(
  INCLUDE_DIRS inc
  CATKIN_DEPENDS ncc
  DEPENDS pcap
)

include_directories(
  inc
  rs_driver/src
  ${catkin_INCLUDE_DIRS}
  ${pcap_INCLUDE_DIRS}
)

add_executable(demo src/demo.cpp)
target_link_libraries(demo ${catkin_LIBRARIES} ${Boost_LIBRARIES} pcap pthread)

install(DIRECTORY inc/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY rs_driver/src/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}/../
   FILES_MATCHING PATTERN "*.h*"
)

install(TARGETS demo
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
