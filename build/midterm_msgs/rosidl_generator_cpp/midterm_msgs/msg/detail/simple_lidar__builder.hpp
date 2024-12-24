// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/SimpleLidar.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__BUILDER_HPP_

#include "midterm_msgs/msg/detail/simple_lidar__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_SimpleLidar_beams
{
public:
  Init_SimpleLidar_beams()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::midterm_msgs::msg::SimpleLidar beams(::midterm_msgs::msg::SimpleLidar::_beams_type arg)
  {
    msg_.beams = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::SimpleLidar msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::SimpleLidar>()
{
  return midterm_msgs::msg::builder::Init_SimpleLidar_beams();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__BUILDER_HPP_
