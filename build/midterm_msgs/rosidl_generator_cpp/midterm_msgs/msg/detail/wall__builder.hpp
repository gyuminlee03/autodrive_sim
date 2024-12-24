// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/Wall.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL__BUILDER_HPP_

#include "midterm_msgs/msg/detail/wall__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_Wall_size_y
{
public:
  explicit Init_Wall_size_y(::midterm_msgs::msg::Wall & msg)
  : msg_(msg)
  {}
  ::midterm_msgs::msg::Wall size_y(::midterm_msgs::msg::Wall::_size_y_type arg)
  {
    msg_.size_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::Wall msg_;
};

class Init_Wall_size_x
{
public:
  explicit Init_Wall_size_x(::midterm_msgs::msg::Wall & msg)
  : msg_(msg)
  {}
  Init_Wall_size_y size_x(::midterm_msgs::msg::Wall::_size_x_type arg)
  {
    msg_.size_x = std::move(arg);
    return Init_Wall_size_y(msg_);
  }

private:
  ::midterm_msgs::msg::Wall msg_;
};

class Init_Wall_bl_y
{
public:
  explicit Init_Wall_bl_y(::midterm_msgs::msg::Wall & msg)
  : msg_(msg)
  {}
  Init_Wall_size_x bl_y(::midterm_msgs::msg::Wall::_bl_y_type arg)
  {
    msg_.bl_y = std::move(arg);
    return Init_Wall_size_x(msg_);
  }

private:
  ::midterm_msgs::msg::Wall msg_;
};

class Init_Wall_bl_x
{
public:
  Init_Wall_bl_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Wall_bl_y bl_x(::midterm_msgs::msg::Wall::_bl_x_type arg)
  {
    msg_.bl_x = std::move(arg);
    return Init_Wall_bl_y(msg_);
  }

private:
  ::midterm_msgs::msg::Wall msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::Wall>()
{
  return midterm_msgs::msg::builder::Init_Wall_bl_x();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL__BUILDER_HPP_
