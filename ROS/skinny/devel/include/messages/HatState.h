// Generated by gencpp from file messages/HatState.msg
// DO NOT EDIT!


#ifndef MESSAGES_MESSAGE_HATSTATE_H
#define MESSAGES_MESSAGE_HATSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace messages
{
template <class ContainerAllocator>
struct HatState_
{
  typedef HatState_<ContainerAllocator> Type;

  HatState_()
    : joystick(0)
    , hat(0)
    , state(0)  {
    }
  HatState_(const ContainerAllocator& _alloc)
    : joystick(0)
    , hat(0)
    , state(0)  {
  (void)_alloc;
    }



   typedef uint8_t _joystick_type;
  _joystick_type joystick;

   typedef uint8_t _hat_type;
  _hat_type hat;

   typedef uint8_t _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::messages::HatState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::messages::HatState_<ContainerAllocator> const> ConstPtr;

}; // struct HatState_

typedef ::messages::HatState_<std::allocator<void> > HatState;

typedef boost::shared_ptr< ::messages::HatState > HatStatePtr;
typedef boost::shared_ptr< ::messages::HatState const> HatStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::messages::HatState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::messages::HatState_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::messages::HatState_<ContainerAllocator1> & lhs, const ::messages::HatState_<ContainerAllocator2> & rhs)
{
  return lhs.joystick == rhs.joystick &&
    lhs.hat == rhs.hat &&
    lhs.state == rhs.state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::messages::HatState_<ContainerAllocator1> & lhs, const ::messages::HatState_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace messages

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::messages::HatState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::messages::HatState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::messages::HatState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::messages::HatState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::messages::HatState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::messages::HatState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::messages::HatState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b0f14c98250145be7590c9d7a97bb21b";
  }

  static const char* value(const ::messages::HatState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb0f14c98250145beULL;
  static const uint64_t static_value2 = 0x7590c9d7a97bb21bULL;
};

template<class ContainerAllocator>
struct DataType< ::messages::HatState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "messages/HatState";
  }

  static const char* value(const ::messages::HatState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::messages::HatState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 joystick\n"
"uint8 hat\n"
"uint8 state\n"
;
  }

  static const char* value(const ::messages::HatState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::messages::HatState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joystick);
      stream.next(m.hat);
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HatState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::messages::HatState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::messages::HatState_<ContainerAllocator>& v)
  {
    s << indent << "joystick: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.joystick);
    s << indent << "hat: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hat);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MESSAGES_MESSAGE_HATSTATE_H
