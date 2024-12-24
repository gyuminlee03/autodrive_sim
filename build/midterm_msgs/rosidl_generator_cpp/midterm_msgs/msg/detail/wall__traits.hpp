// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from midterm_msgs:msg/Wall.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL__TRAITS_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL__TRAITS_HPP_

#include "midterm_msgs/msg/detail/wall__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<midterm_msgs::msg::Wall>()
{
  return "midterm_msgs::msg::Wall";
}

template<>
inline const char * name<midterm_msgs::msg::Wall>()
{
  return "midterm_msgs/msg/Wall";
}

template<>
struct has_fixed_size<midterm_msgs::msg::Wall>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<midterm_msgs::msg::Wall>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<midterm_msgs::msg::Wall>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL__TRAITS_HPP_
