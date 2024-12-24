// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from midterm_msgs:msg/SimpleGPS.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__STRUCT_H_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SimpleGPS in the package midterm_msgs.
typedef struct midterm_msgs__msg__SimpleGPS
{
  float x;
  float y;
  float yaw;
} midterm_msgs__msg__SimpleGPS;

// Struct for a sequence of midterm_msgs__msg__SimpleGPS.
typedef struct midterm_msgs__msg__SimpleGPS__Sequence
{
  midterm_msgs__msg__SimpleGPS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} midterm_msgs__msg__SimpleGPS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_GPS__STRUCT_H_
