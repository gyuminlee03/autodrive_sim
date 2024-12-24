// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_H_
#define MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'walls'
#include "midterm_msgs/msg/detail/wall__struct.h"

// Struct defined in msg/WallList in the package midterm_msgs.
typedef struct midterm_msgs__msg__WallList
{
  midterm_msgs__msg__Wall__Sequence walls;
} midterm_msgs__msg__WallList;

// Struct for a sequence of midterm_msgs__msg__WallList.
typedef struct midterm_msgs__msg__WallList__Sequence
{
  midterm_msgs__msg__WallList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} midterm_msgs__msg__WallList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_H_
