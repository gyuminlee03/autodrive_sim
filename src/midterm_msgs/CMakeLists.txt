cmake_minimum_required(VERSION 3.8)
project(midterm_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

################################################################################
# Find and load build settings from external packages
################################################################################
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

################################################################################
# Declare ROS messages, services and actions
################################################################################
set(msg_files
  "msg/Wall.msg"
  "msg/Goal.msg"
  "msg/SimpleGPS.msg"
  "msg/SimpleLidar.msg"
  "msg/WallList.msg"
  "msg/Control.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES builtin_interfaces
)

################################################################################
# Macro for ament package
################################################################################
ament_export_dependencies(rosidl_default_runtime)
ament_package()