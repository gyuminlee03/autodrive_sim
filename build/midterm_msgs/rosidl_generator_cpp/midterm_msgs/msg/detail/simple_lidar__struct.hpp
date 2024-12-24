// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from midterm_msgs:msg/SimpleLidar.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__midterm_msgs__msg__SimpleLidar __attribute__((deprecated))
#else
# define DEPRECATED__midterm_msgs__msg__SimpleLidar __declspec(deprecated)
#endif

namespace midterm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SimpleLidar_
{
  using Type = SimpleLidar_<ContainerAllocator>;

  explicit SimpleLidar_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SimpleLidar_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _beams_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _beams_type beams;

  // setters for named parameter idiom
  Type & set__beams(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->beams = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    midterm_msgs::msg::SimpleLidar_<ContainerAllocator> *;
  using ConstRawPtr =
    const midterm_msgs::msg::SimpleLidar_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::SimpleLidar_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::SimpleLidar_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__midterm_msgs__msg__SimpleLidar
    std::shared_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__midterm_msgs__msg__SimpleLidar
    std::shared_ptr<midterm_msgs::msg::SimpleLidar_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SimpleLidar_ & other) const
  {
    if (this->beams != other.beams) {
      return false;
    }
    return true;
  }
  bool operator!=(const SimpleLidar_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SimpleLidar_

// alias to use template instance with default allocator
using SimpleLidar =
  midterm_msgs::msg::SimpleLidar_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__STRUCT_HPP_
