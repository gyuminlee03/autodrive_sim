// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__BUILDER_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__BUILDER_HPP_

#include "midterm_msgs/msg/detail/wall_list__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace midterm_msgs
{

namespace msg
{

namespace builder
{

class Init_WallList_walls
{
public:
  Init_WallList_walls()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::midterm_msgs::msg::WallList walls(::midterm_msgs::msg::WallList::_walls_type arg)
  {
    msg_.walls = std::move(arg);
    return std::move(msg_);
  }

private:
  ::midterm_msgs::msg::WallList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::midterm_msgs::msg::WallList>()
{
  return midterm_msgs::msg::builder::Init_WallList_walls();
}

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__BUILDER_HPP_
