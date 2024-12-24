// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from midterm_msgs:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__GOAL__TRAITS_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__GOAL__TRAITS_HPP_

#include "midterm_msgs/msg/detail/goal__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<midterm_msgs::msg::Goal>()
{
  return "midterm_msgs::msg::Goal";
}

template<>
inline const char * name<midterm_msgs::msg::Goal>()
{
  return "midterm_msgs/msg/Goal";
}

template<>
struct has_fixed_size<midterm_msgs::msg::Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<midterm_msgs::msg::Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<midterm_msgs::msg::Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIDTERM_MSGS__MSG__DETAIL__GOAL__TRAITS_HPP_
