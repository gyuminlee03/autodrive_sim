// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from midterm_msgs:msg/Wall.idl
// generated code does not contain a copyright notice
#include "midterm_msgs/msg/detail/wall__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "midterm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "midterm_msgs/msg/detail/wall__struct.h"
#include "midterm_msgs/msg/detail/wall__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Wall__ros_msg_type = midterm_msgs__msg__Wall;

static bool _Wall__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Wall__ros_msg_type * ros_message = static_cast<const _Wall__ros_msg_type *>(untyped_ros_message);
  // Field name: bl_x
  {
    cdr << ros_message->bl_x;
  }

  // Field name: bl_y
  {
    cdr << ros_message->bl_y;
  }

  // Field name: size_x
  {
    cdr << ros_message->size_x;
  }

  // Field name: size_y
  {
    cdr << ros_message->size_y;
  }

  return true;
}

static bool _Wall__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Wall__ros_msg_type * ros_message = static_cast<_Wall__ros_msg_type *>(untyped_ros_message);
  // Field name: bl_x
  {
    cdr >> ros_message->bl_x;
  }

  // Field name: bl_y
  {
    cdr >> ros_message->bl_y;
  }

  // Field name: size_x
  {
    cdr >> ros_message->size_x;
  }

  // Field name: size_y
  {
    cdr >> ros_message->size_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_midterm_msgs
size_t get_serialized_size_midterm_msgs__msg__Wall(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Wall__ros_msg_type * ros_message = static_cast<const _Wall__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name bl_x
  {
    size_t item_size = sizeof(ros_message->bl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bl_y
  {
    size_t item_size = sizeof(ros_message->bl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name size_x
  {
    size_t item_size = sizeof(ros_message->size_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name size_y
  {
    size_t item_size = sizeof(ros_message->size_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Wall__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_midterm_msgs__msg__Wall(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_midterm_msgs
size_t max_serialized_size_midterm_msgs__msg__Wall(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: bl_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bl_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: size_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: size_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Wall__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_midterm_msgs__msg__Wall(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Wall = {
  "midterm_msgs::msg",
  "Wall",
  _Wall__cdr_serialize,
  _Wall__cdr_deserialize,
  _Wall__get_serialized_size,
  _Wall__max_serialized_size
};

static rosidl_message_type_support_t _Wall__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Wall,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, midterm_msgs, msg, Wall)() {
  return &_Wall__type_support;
}

#if defined(__cplusplus)
}
#endif
