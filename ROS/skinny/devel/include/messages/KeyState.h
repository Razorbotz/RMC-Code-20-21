// Generated by gencpp from file messages/KeyState.msg
// DO NOT EDIT!


#ifndef MESSAGES_MESSAGE_KEYSTATE_H
#define MESSAGES_MESSAGE_KEYSTATE_H


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
struct KeyState_
{
  typedef KeyState_<ContainerAllocator> Type;

  KeyState_()
    : key(0)
    , state(0)  {
    }
  KeyState_(const ContainerAllocator& _alloc)
    : key(0)
    , state(0)  {
  (void)_alloc;
    }



   typedef uint16_t _key_type;
  _key_type key;

   typedef uint8_t _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::messages::KeyState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::messages::KeyState_<ContainerAllocator> const> ConstPtr;

}; // struct KeyState_

typedef ::messages::KeyState_<std::allocator<void> > KeyState;

typedef boost::shared_ptr< ::messages::KeyState > KeyStatePtr;
typedef boost::shared_ptr< ::messages::KeyState const> KeyStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::messages::KeyState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::messages::KeyState_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::messages::KeyState_<ContainerAllocator1> & lhs, const ::messages::KeyState_<ContainerAllocator2> & rhs)
{
  return lhs.key == rhs.key &&
    lhs.state == rhs.state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::messages::KeyState_<ContainerAllocator1> & lhs, const ::messages::KeyState_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace messages

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::messages::KeyState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::messages::KeyState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::messages::KeyState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::messages::KeyState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::messages::KeyState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::messages::KeyState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::messages::KeyState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5b60023c4a21dcdf8c0309517484805f";
  }

  static const char* value(const ::messages::KeyState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5b60023c4a21dcdfULL;
  static const uint64_t static_value2 = 0x8c0309517484805fULL;
};

template<class ContainerAllocator>
struct DataType< ::messages::KeyState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "messages/KeyState";
  }

  static const char* value(const ::messages::KeyState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::messages::KeyState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint16 key\n"
"uint8 state\n"
;
  }

  static const char* value(const ::messages::KeyState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::messages::KeyState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.key);
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KeyState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::messages::KeyState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::messages::KeyState_<ContainerAllocator>& v)
  {
    s << indent << "key: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.key);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MESSAGES_MESSAGE_KEYSTATE_H