// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__TRAITS_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__TRAITS_HPP_

#include "midterm_msgs/msg/detail/wall_list__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<midterm_msgs::msg::WallList>()
{
  return "midterm_msgs::msg::WallList";
}

template<>
inline const char * name<midterm_msgs::msg::WallList>()
{
  return "midterm_msgs/msg/WallList";
}

template<>
struct has_fixed_size<midterm_msgs::msg::WallList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<midterm_msgs::msg::WallList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<midterm_msgs::msg::WallList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__TRAITS_HPP_
