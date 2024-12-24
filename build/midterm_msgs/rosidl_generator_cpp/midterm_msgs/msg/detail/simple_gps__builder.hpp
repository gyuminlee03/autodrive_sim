// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/SimpleGPS.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__BUILDER_HPP_

#include "midterm_msgs/msg/detail/simple_gps__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_SimpleGPS_yaw
{
public:
  explicit Init_SimpleGPS_yaw(::midterm_msgs::msg::SimpleGPS & msg)
  : msg_(msg)
  {}
  ::midterm_msgs::msg::SimpleGPS yaw(::midterm_msgs::msg::SimpleGPS::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::SimpleGPS msg_;
};

class Init_SimpleGPS_y
{
public:
  explicit Init_SimpleGPS_y(::midterm_msgs::msg::SimpleGPS & msg)
  : msg_(msg)
  {}
  Init_SimpleGPS_yaw y(::midterm_msgs::msg::SimpleGPS::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SimpleGPS_yaw(msg_);
  }

private:
  ::midterm_msgs::msg::SimpleGPS msg_;
};

class Init_SimpleGPS_x
{
public:
  Init_SimpleGPS_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleGPS_y x(::midterm_msgs::msg::SimpleGPS::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SimpleGPS_y(msg_);
  }

private:
  ::midterm_msgs::msg::SimpleGPS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::SimpleGPS>()
{
  return midterm_msgs::msg::builder::Init_SimpleGPS_x();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__BUILDER_HPP_
