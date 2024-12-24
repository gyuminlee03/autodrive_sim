// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from midterm_msgs:msg/SimpleLidar.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_H_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'beams'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/SimpleLidar in the package midterm_msgs.
typedef struct midterm_msgs__msg__SimpleLidar
{
  rosidl_runtime_c__float__Sequence beams;
} midterm_msgs__msg__SimpleLidar;

// Struct for a sequence of midterm_msgs__msg__SimpleLidar.
typedef struct midterm_msgs__msg__SimpleLidar__Sequence
{
  midterm_msgs__msg__SimpleLidar * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} midterm_msgs__msg__SimpleLidar__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_H_
