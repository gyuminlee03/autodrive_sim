// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from midterm_msgs:msg/SimpleGPS.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "midterm_msgs/msg/detail/simple_gps__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace midterm_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SimpleGPS_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) midterm_msgs::msg::SimpleGPS(_init);
}

void SimpleGPS_fini_function(void * message_memory)
{
  auto typed_message = static_cast<midterm_msgs::msg::SimpleGPS *>(message_memory);
  typed_message->~SimpleGPS();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SimpleGPS_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs::msg::SimpleGPS, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs::msg::SimpleGPS, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "yaw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs::msg::SimpleGPS, yaw),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SimpleGPS_message_members = {
  "midterm_msgs::msg",  // message namespace
  "SimpleGPS",  // message name
  3,  // number of fields
  sizeof(midterm_msgs::msg::SimpleGPS),
  SimpleGPS_message_member_array,  // message members
  SimpleGPS_init_function,  // function to initialize message memory (memory has to be allocated)
  SimpleGPS_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SimpleGPS_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SimpleGPS_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace midterm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<midterm_msgs::msg::SimpleGPS>()
{
  return &::midterm_msgs::msg::rosidl_typesupport_introspection_cpp::SimpleGPS_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, midterm_msgs, msg, SimpleGPS)() {
  return &::midterm_msgs::msg::rosidl_typesupport_introspection_cpp::SimpleGPS_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
