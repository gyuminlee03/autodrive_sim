// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from midterm_msgs:msg/Wall.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "midterm_msgs/msg/detail/wall__rosidl_typesupport_introspection_c.h"
#include "midterm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "midterm_msgs/msg/detail/wall__functions.h"
#include "midterm_msgs/msg/detail/wall__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Wall__rosidl_typesupport_introspection_c__Wall_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  midterm_msgs__msg__Wall__init(message_memory);
}

void Wall__rosidl_typesupport_introspection_c__Wall_fini_function(void * message_memory)
{
  midterm_msgs__msg__Wall__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Wall__rosidl_typesupport_introspection_c__Wall_message_member_array[4] = {
  {
    "bl_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs__msg__Wall, bl_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bl_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs__msg__Wall, bl_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs__msg__Wall, size_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs__msg__Wall, size_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Wall__rosidl_typesupport_introspection_c__Wall_message_members = {
  "midterm_msgs__msg",  // message namespace
  "Wall",  // message name
  4,  // number of fields
  sizeof(midterm_msgs__msg__Wall),
  Wall__rosidl_typesupport_introspection_c__Wall_message_member_array,  // message members
  Wall__rosidl_typesupport_introspection_c__Wall_init_function,  // function to initialize message memory (memory has to be allocated)
  Wall__rosidl_typesupport_introspection_c__Wall_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Wall__rosidl_typesupport_introspection_c__Wall_message_type_support_handle = {
  0,
  &Wall__rosidl_typesupport_introspection_c__Wall_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_midterm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, midterm_msgs, msg, Wall)() {
  if (!Wall__rosidl_typesupport_introspection_c__Wall_message_type_support_handle.typesupport_identifier) {
    Wall__rosidl_typesupport_introspection_c__Wall_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Wall__rosidl_typesupport_introspection_c__Wall_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
