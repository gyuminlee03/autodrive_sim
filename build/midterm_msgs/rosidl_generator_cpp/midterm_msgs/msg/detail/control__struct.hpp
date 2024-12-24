// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from midterm_msgs:msg/Control.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__midterm_msgs__msg__Control __attribute__((deprecated))
#else
# define DEPRECATED__midterm_msgs__msg__Control __declspec(deprecated)
#endif

namespace midterm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Control_
{
  using Type = Control_<ContainerAllocator>;

  explicit Control_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel = 0.0f;
      this->steering = 0.0f;
    }
  }

  explicit Control_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel = 0.0f;
      this->steering = 0.0f;
    }
  }

  // field types and members
  using _accel_type =
    float;
  _accel_type accel;
  using _steering_type =
    float;
  _steering_type steering;

  // setters for named parameter idiom
  Type & set__accel(
    const float & _arg)
  {
    this->accel = _arg;
    return *this;
  }
  Type & set__steering(
    const float & _arg)
  {
    this->steering = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    midterm_msgs::msg::Control_<ContainerAllocator> *;
  using ConstRawPtr =
    const midterm_msgs::msg::Control_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<midterm_msgs::msg::Control_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<midterm_msgs::msg::Control_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Control_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Control_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::Control_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::Control_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<midterm_msgs::msg::Control_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<midterm_msgs::msg::Control_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__midterm_msgs__msg__Control
    std::shared_ptr<midterm_msgs::msg::Control_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__midterm_msgs__msg__Control
    std::shared_ptr<midterm_msgs::msg::Control_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_ & other) const
  {
    if (this->accel != other.accel) {
      return false;
    }
    if (this->steering != other.steering) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_

// alias to use template instance with default allocator
using Control =
  midterm_msgs::msg::Control_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__CONTROL__STRUCT_HPP_
