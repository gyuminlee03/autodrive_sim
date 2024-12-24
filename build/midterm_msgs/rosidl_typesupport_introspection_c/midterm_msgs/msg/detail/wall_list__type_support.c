// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "midterm_msgs/msg/detail/wall_list__rosidl_typesupport_introspection_c.h"
#include "midterm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "midterm_msgs/msg/detail/wall_list__functions.h"
#include "midterm_msgs/msg/detail/wall_list__struct.h"


// Include directives for member types
// Member `walls`
#include "midterm_msgs/msg/wall.h"
// Member `walls`
#include "midterm_msgs/msg/detail/wall__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void WallList__rosidl_typesupport_introspection_c__WallList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  midterm_msgs__msg__WallList__init(message_memory);
}

void WallList__rosidl_typesupport_introspection_c__WallList_fini_function(void * message_memory)
{
  midterm_msgs__msg__WallList__fini(message_memory);
}

size_t WallList__rosidl_typesupport_introspection_c__size_function__Wall__walls(
  const void * untyped_member)
{
  const midterm_msgs__msg__Wall__Sequence * member =
    (const midterm_msgs__msg__Wall__Sequence *)(untyped_member);
  return member->size;
}

const void * WallList__rosidl_typesupport_introspection_c__get_const_function__Wall__walls(
  const void * untyped_member, size_t index)
{
  const midterm_msgs__msg__Wall__Sequence * member =
    (const midterm_msgs__msg__Wall__Sequence *)(untyped_member);
  return &member->data[index];
}

void * WallList__rosidl_typesupport_introspection_c__get_function__Wall__walls(
  void * untyped_member, size_t index)
{
  midterm_msgs__msg__Wall__Sequence * member =
    (midterm_msgs__msg__Wall__Sequence *)(untyped_member);
  return &member->data[index];
}

bool WallList__rosidl_typesupport_introspection_c__resize_function__Wall__walls(
  void * untyped_member, size_t size)
{
  midterm_msgs__msg__Wall__Sequence * member =
    (midterm_msgs__msg__Wall__Sequence *)(untyped_member);
  midterm_msgs__msg__Wall__Sequence__fini(member);
  return midterm_msgs__msg__Wall__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember WallList__rosidl_typesupport_introspection_c__WallList_message_member_array[1] = {
  {
    "walls",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs__msg__WallList, walls),  // bytes offset in struct
    NULL,  // default value
    WallList__rosidl_typesupport_introspection_c__size_function__Wall__walls,  // size() function pointer
    WallList__rosidl_typesupport_introspection_c__get_const_function__Wall__walls,  // get_const(index) function pointer
    WallList__rosidl_typesupport_introspection_c__get_function__Wall__walls,  // get(index) function pointer
    WallList__rosidl_typesupport_introspection_c__resize_function__Wall__walls  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers WallList__rosidl_typesupport_introspection_c__WallList_message_members = {
  "midterm_msgs__msg",  // message namespace
  "WallList",  // message name
  1,  // number of fields
  sizeof(midterm_msgs__msg__WallList),
  WallList__rosidl_typesupport_introspection_c__WallList_message_member_array,  // message members
  WallList__rosidl_typesupport_introspection_c__WallList_init_function,  // function to initialize message memory (memory has to be allocated)
  WallList__rosidl_typesupport_introspection_c__WallList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t WallList__rosidl_typesupport_introspection_c__WallList_message_type_support_handle = {
  0,
  &WallList__rosidl_typesupport_introspection_c__WallList_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_midterm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, midterm_msgs, msg, WallList)() {
  WallList__rosidl_typesupport_introspection_c__WallList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, midterm_msgs, msg, Wall)();
  if (!WallList__rosidl_typesupport_introspection_c__WallList_message_type_support_handle.typesupport_identifier) {
    WallList__rosidl_typesupport_introspection_c__WallList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &WallList__rosidl_typesupport_introspection_c__WallList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
