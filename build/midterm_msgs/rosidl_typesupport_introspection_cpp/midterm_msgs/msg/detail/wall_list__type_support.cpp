// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "midterm_msgs/msg/detail/wall_list__struct.hpp"
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

void WallList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) midterm_msgs::msg::WallList(_init);
}

void WallList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<midterm_msgs::msg::WallList *>(message_memory);
  typed_message->~WallList();
}

size_t size_function__WallList__walls(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<midterm_msgs::msg::Wall> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WallList__walls(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<midterm_msgs::msg::Wall> *>(untyped_member);
  return &member[index];
}

void * get_function__WallList__walls(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<midterm_msgs::msg::Wall> *>(untyped_member);
  return &member[index];
}

void resize_function__WallList__walls(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<midterm_msgs::msg::Wall> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WallList_message_member_array[1] = {
  {
    "walls",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<midterm_msgs::msg::Wall>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(midterm_msgs::msg::WallList, walls),  // bytes offset in struct
    nullptr,  // default value
    size_function__WallList__walls,  // size() function pointer
    get_const_function__WallList__walls,  // get_const(index) function pointer
    get_function__WallList__walls,  // get(index) function pointer
    resize_function__WallList__walls  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WallList_message_members = {
  "midterm_msgs::msg",  // message namespace
  "WallList",  // message name
  1,  // number of fields
  sizeof(midterm_msgs::msg::WallList),
  WallList_message_member_array,  // message members
  WallList_init_function,  // function to initialize message memory (memory has to be allocated)
  WallList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WallList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WallList_message_members,
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
get_message_type_support_handle<midterm_msgs::msg::WallList>()
{
  return &::midterm_msgs::msg::rosidl_typesupport_introspection_cpp::WallList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, midterm_msgs, msg, WallList)() {
  return &::midterm_msgs::msg::rosidl_typesupport_introspection_cpp::WallList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
