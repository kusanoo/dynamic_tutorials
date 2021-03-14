cmake_minimum_required(VERSION 2.8.3)
project(dynamic_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
)

generate_dynamic_reconfigure_options(cfg/Tutorials.cfg)
add_executable(client src/client.cpp)
add_dependencies(client ${PROJECT_NAME}_gencfg)
target_link_libraries(client
  ${catkin_LIBRARIES}
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES dynamic_tutorials
#  CATKIN_DEPENDS dynamic_reconfigure roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

