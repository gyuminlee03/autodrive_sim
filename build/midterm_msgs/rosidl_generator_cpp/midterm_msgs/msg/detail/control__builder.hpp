// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_

#include "midterm_msgs/msg/detail/control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_Control_steering
{
public:
  explicit Init_Control_steering(::midterm_msgs::msg::Control & msg)
  : msg_(msg)
  {}
  ::midterm_msgs::msg::Control steering(::midterm_msgs::msg::Control::_steering_type arg)
  {
    msg_.steering = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::Control msg_;
};

class Init_Control_accel
{
public:
  Init_Control_accel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Control_steering accel(::midterm_msgs::msg::Control::_accel_type arg)
  {
    msg_.accel = std::move(arg);
    return Init_Control_steering(msg_);
  }

private:
  ::midterm_msgs::msg::Control msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::Control>()
{
  return midterm_msgs::msg::builder::Init_Control_accel();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__CONTROL__BUILDER_HPP_
