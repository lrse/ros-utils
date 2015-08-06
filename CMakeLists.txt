cmake_minimum_required(VERSION 2.8.3)
project(ros_utils)

find_package(catkin REQUIRED COMPONENTS roscpp cmake_modules geometry_msgs nav_msgs)
catkin_package(CATKIN_DEPENDS roscpp geometry_msgs nav_msgs )

ADD_EXECUTABLE(pose_to_path src/pose_to_path.cpp)
TARGET_LINK_LIBRARIES(pose_to_path ${catkin_LIBRARIES})

ADD_EXECUTABLE(odom_to_pose src/odom_to_pose.cpp)
TARGET_LINK_LIBRARIES(odom_to_pose ${catkin_LIBRARIES})
