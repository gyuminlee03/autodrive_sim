// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from midterm_msgs:msg/Wall.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL__STRUCT_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__midterm_msgs__msg__Wall __attribute__((deprecated))
#else
# define DEPRECATED__midterm_msgs__msg__Wall __declspec(deprecated)
#endif

namespace midterm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Wall_
{
  using Type = Wall_<ContainerAllocator>;

  explicit Wall_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bl_x = 0.0f;
      this->bl_y = 0.0f;
      this->size_x = 0.0f;
      this->size_y = 0.0f;
    }
  }

  explicit Wall_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bl_x = 0.0f;
      this->bl_y = 0.0f;
      this->size_x = 0.0f;
      this->size_y = 0.0f;
    }
  }

  // field types and members
  using _bl_x_type =
    float;
  _bl_x_type bl_x;
  using _bl_y_type =
    float;
  _bl_y_type bl_y;
  using _size_x_type =
    float;
  _size_x_type size_x;
  using _size_y_type =
    float;
  _size_y_type size_y;

  // setters for named parameter idiom
  Type & set__bl_x(
    const float & _arg)
  {
    this->bl_x = _arg;
    return *this;
  }
  Type & set__bl_y(
    const float & _arg)
  {
    this->bl_y = _arg;
    return *this;
  }
  Type & set__size_x(
    const float & _arg)
  {
    this->size_x = _arg;
    return *this;
  }
  Type & set__size_y(
    const float & _arg)
  {
    this->size_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    midterm_msgs::msg::Wall_<ContainerAllocator> *;
  using ConstRawPtr =
    const midterm_msgs::msg::Wall_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<midterm_msgs::msg::Wall_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<midterm_msgs::msg::Wall_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Wall_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Wall_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Wall_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Wall_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<midterm_msgs::msg::Wall_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<midterm_msgs::msg::Wall_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__midterm_msgs__msg__Wall
    std::shared_ptr<midterm_msgs::msg::Wall_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__midterm_msgs__msg__Wall
    std::shared_ptr<midterm_msgs::msg::Wall_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Wall_ & other) const
  {
    if (this->bl_x != other.bl_x) {
      return false;
    }
    if (this->bl_y != other.bl_y) {
      return false;
    }
    if (this->size_x != other.size_x) {
      return false;
    }
    if (this->size_y != other.size_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Wall_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Wall_

// alias to use template instance with default allocator
using Wall =
  midterm_msgs::msg::Wall_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL__STRUCT_HPP_
