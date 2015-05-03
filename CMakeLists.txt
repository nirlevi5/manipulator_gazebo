cmake_minimum_required(VERSION 2.8.3)
project(manipulator_gazebo)


find_package(catkin REQUIRED COMPONENTS
  actionlib
  control_msgs
  roscpp
  gazebo_ros
)

catkin_package(
    DEPENDS 
    CATKIN_DEPENDS 
    INCLUDE_DIRS 
    LIBRARIES 
)


