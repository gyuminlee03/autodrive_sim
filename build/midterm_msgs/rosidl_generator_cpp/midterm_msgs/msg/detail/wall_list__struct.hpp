// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_HPP_
#define MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'walls'
#include "midterm_msgs/msg/detail/wall__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__midterm_msgs__msg__WallList __attribute__((deprecated))
#else
# define DEPRECATED__midterm_msgs__msg__WallList __declspec(deprecated)
#endif

namespace midterm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WallList_
{
  using Type = WallList_<ContainerAllocator>;

  explicit WallList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit WallList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _walls_type =
    std::vector<midterm_msgs::msg::Wall_<ContainerAllocator>, typename ContainerAllocator::template rebind<midterm_msgs::msg::Wall_<ContainerAllocator>>::other>;
  _walls_type walls;

  // setters for named parameter idiom
  Type & set__walls(
    const std::vector<midterm_msgs::msg::Wall_<ContainerAllocator>, typename ContainerAllocator::template rebind<midterm_msgs::msg::Wall_<ContainerAllocator>>::other> & _arg)
  {
    this->walls = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    midterm_msgs::msg::WallList_<ContainerAllocator> *;
  using ConstRawPtr =
    const midterm_msgs::msg::WallList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<midterm_msgs::msg::WallList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<midterm_msgs::msg::WallList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::WallList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::WallList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      midterm_msgs::msg::WallList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<midterm_msgs::msg::WallList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<midterm_msgs::msg::WallList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<midterm_msgs::msg::WallList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__midterm_msgs__msg__WallList
    std::shared_ptr<midterm_msgs::msg::WallList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__midterm_msgs__msg__WallList
    std::shared_ptr<midterm_msgs::msg::WallList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WallList_ & other) const
  {
    if (this->walls != other.walls) {
      return false;
    }
    return true;
  }
  bool operator!=(const WallList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WallList_

// alias to use template instance with default allocator
using WallList =
  midterm_msgs::msg::WallList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace midterm_msgs

#endif  // MIDTERM_MSGS__MSG__DETAIL__WALL_LIST__STRUCT_HPP_
