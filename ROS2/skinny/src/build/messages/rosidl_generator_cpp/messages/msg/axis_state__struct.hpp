// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/AxisState.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__AXIS_STATE__STRUCT_HPP_
#define MESSAGES__MSG__AXIS_STATE__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__messages__msg__AxisState __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__AxisState __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AxisState_
{
  using Type = AxisState_<ContainerAllocator>;

  explicit AxisState_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->joystick = 0;
      this->axis = 0;
      this->state = 0.0f;
    }
  }

  explicit AxisState_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->joystick = 0;
      this->axis = 0;
      this->state = 0.0f;
    }
  }

  // field types and members
  using _joystick_type =
    uint8_t;
  _joystick_type joystick;
  using _axis_type =
    uint8_t;
  _axis_type axis;
  using _state_type =
    float;
  _state_type state;

  // setters for named parameter idiom
  Type & set__joystick(
    const uint8_t & _arg)
  {
    this->joystick = _arg;
    return *this;
  }
  Type & set__axis(
    const uint8_t & _arg)
  {
    this->axis = _arg;
    return *this;
  }
  Type & set__state(
    const float & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::AxisState_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::AxisState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::AxisState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::AxisState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::AxisState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::AxisState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::AxisState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::AxisState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::AxisState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::AxisState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__AxisState
    std::shared_ptr<messages::msg::AxisState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__AxisState
    std::shared_ptr<messages::msg::AxisState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AxisState_ & other) const
  {
    if (this->joystick != other.joystick) {
      return false;
    }
    if (this->axis != other.axis) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const AxisState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AxisState_

// alias to use template instance with default allocator
using AxisState =
  messages::msg::AxisState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__AXIS_STATE__STRUCT_HPP_
