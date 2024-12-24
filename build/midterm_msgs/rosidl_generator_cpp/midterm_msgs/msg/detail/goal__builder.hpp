// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__GOAL__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__GOAL__BUILDER_HPP_

#include "midterm_msgs/msg/detail/goal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_Goal_y
{
public:
  explicit Init_Goal_y(::midterm_msgs::msg::Goal & msg)
  : msg_(msg)
  {}
  ::midterm_msgs::msg::Goal y(::midterm_msgs::msg::Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::Goal msg_;
};

class Init_Goal_x
{
public:
  Init_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Goal_y x(::midterm_msgs::msg::Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Goal_y(msg_);
  }

private:
  ::midterm_msgs::msg::Goal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::Goal>()
{
  return midterm_msgs::msg::builder::Init_Goal_x();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__GOAL__BUILDER_HPP_
