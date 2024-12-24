// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from midterm_msgs:msg/SimpleGPS.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__TRAITS_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__TRAITS_HPP_

#include "midterm_msgs/msg/detail/simple_gps__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<midterm_msgs::msg::SimpleGPS>()
{
  return "midterm_msgs::msg::SimpleGPS";
}

template<>
inline const char * name<midterm_msgs::msg::SimpleGPS>()
{
  return "midterm_msgs/msg/SimpleGPS";
}

template<>
struct has_fixed_size<midterm_msgs::msg::SimpleGPS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<midterm_msgs::msg::SimpleGPS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<midterm_msgs::msg::SimpleGPS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__TRAITS_HPP_
