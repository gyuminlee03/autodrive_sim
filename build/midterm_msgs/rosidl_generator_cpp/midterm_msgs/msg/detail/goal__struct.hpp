// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from midterm_msgs:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__GOAL__STRUCT_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__GOAL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__midterm_msgs__msg__Goal __attribute__((deprecated))
#else
# define DEPRECATED__midterm_msgs__msg__Goal __declspec(deprecated)
#endif

namespace midterm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Goal_
{
  using Type = Goal_<ContainerAllocator>;

  explicit Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    midterm_msgs::msg::Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const midterm_msgs::msg::Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<midterm_msgs::msg::Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<midterm_msgs::msg::Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<midterm_msgs::msg::Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<midterm_msgs::msg::Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__midterm_msgs__msg__Goal
    std::shared_ptr<midterm_msgs::msg::Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__midterm_msgs__msg__Goal
    std::shared_ptr<midterm_msgs::msg::Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Goal_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Goal_

// alias to use template instance with default allocator
using Goal =
  midterm_msgs::msg::Goal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__GOAL__STRUCT_HPP_