// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from midterm_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_
#define MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Control in the package midterm_msgs.
typedef struct midterm_msgs__msg__Control
{
  float accel;
  float steering;
} midterm_msgs__msg__Control;

// Struct for a sequence of midterm_msgs__msg__Control.
typedef struct midterm_msgs__msg__Control__Sequence
{
  midterm_msgs__msg__Control * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} midterm_msgs__msg__Control__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_H_
