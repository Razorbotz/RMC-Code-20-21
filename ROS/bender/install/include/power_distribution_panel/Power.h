// Generated by gencpp from file power_distribution_panel/Power.msg
// DO NOT EDIT!


#ifndef POWER_DISTRIBUTION_PANEL_MESSAGE_POWER_H
#define POWER_DISTRIBUTION_PANEL_MESSAGE_POWER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace power_distribution_panel
{
template <class ContainerAllocator>
struct Power_
{
  typedef Power_<ContainerAllocator> Type;

  Power_()
    : voltage(0.0)
    , current0(0.0)
    , current1(0.0)
    , current2(0.0)
    , current3(0.0)
    , current4(0.0)
    , current5(0.0)
    , current6(0.0)
    , current7(0.0)
    , current8(0.0)
    , current9(0.0)
    , current10(0.0)
    , current11(0.0)
    , current12(0.0)
    , current13(0.0)
    , current14(0.0)
    , current15(0.0)  {
    }
  Power_(const ContainerAllocator& _alloc)
    : voltage(0.0)
    , current0(0.0)
    , current1(0.0)
    , current2(0.0)
    , current3(0.0)
    , current4(0.0)
    , current5(0.0)
    , current6(0.0)
    , current7(0.0)
    , current8(0.0)
    , current9(0.0)
    , current10(0.0)
    , current11(0.0)
    , current12(0.0)
    , current13(0.0)
    , current14(0.0)
    , current15(0.0)  {
  (void)_alloc;
    }



   typedef float _voltage_type;
  _voltage_type voltage;

   typedef float _current0_type;
  _current0_type current0;

   typedef float _current1_type;
  _current1_type current1;

   typedef float _current2_type;
  _current2_type current2;

   typedef float _current3_type;
  _current3_type current3;

   typedef float _current4_type;
  _current4_type current4;

   typedef float _current5_type;
  _current5_type current5;

   typedef float _current6_type;
  _current6_type current6;

   typedef float _current7_type;
  _current7_type current7;

   typedef float _current8_type;
  _current8_type current8;

   typedef float _current9_type;
  _current9_type current9;

   typedef float _current10_type;
  _current10_type current10;

   typedef float _current11_type;
  _current11_type current11;

   typedef float _current12_type;
  _current12_type current12;

   typedef float _current13_type;
  _current13_type current13;

   typedef float _current14_type;
  _current14_type current14;

   typedef float _current15_type;
  _current15_type current15;





  typedef boost::shared_ptr< ::power_distribution_panel::Power_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::power_distribution_panel::Power_<ContainerAllocator> const> ConstPtr;

}; // struct Power_

typedef ::power_distribution_panel::Power_<std::allocator<void> > Power;

typedef boost::shared_ptr< ::power_distribution_panel::Power > PowerPtr;
typedef boost::shared_ptr< ::power_distribution_panel::Power const> PowerConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::power_distribution_panel::Power_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::power_distribution_panel::Power_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace power_distribution_panel

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/lunar/share/std_msgs/cmake/../msg'], 'power_distribution_panel': ['/home/nvidia/SoftwareDevelopment/ROS/src/power_distribution_panel/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::power_distribution_panel::Power_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::power_distribution_panel::Power_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::power_distribution_panel::Power_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::power_distribution_panel::Power_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::power_distribution_panel::Power_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::power_distribution_panel::Power_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::power_distribution_panel::Power_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a5bf87df7460476e356f8a0cdbf06096";
  }

  static const char* value(const ::power_distribution_panel::Power_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa5bf87df7460476eULL;
  static const uint64_t static_value2 = 0x356f8a0cdbf06096ULL;
};

template<class ContainerAllocator>
struct DataType< ::power_distribution_panel::Power_<ContainerAllocator> >
{
  static const char* value()
  {
    return "power_distribution_panel/Power";
  }

  static const char* value(const ::power_distribution_panel::Power_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::power_distribution_panel::Power_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 voltage\n\
float32 current0\n\
float32 current1\n\
float32 current2\n\
float32 current3\n\
float32 current4\n\
float32 current5\n\
float32 current6\n\
float32 current7\n\
float32 current8\n\
float32 current9\n\
float32 current10\n\
float32 current11\n\
float32 current12\n\
float32 current13\n\
float32 current14 \n\
float32 current15\n\
";
  }

  static const char* value(const ::power_distribution_panel::Power_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::power_distribution_panel::Power_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.voltage);
      stream.next(m.current0);
      stream.next(m.current1);
      stream.next(m.current2);
      stream.next(m.current3);
      stream.next(m.current4);
      stream.next(m.current5);
      stream.next(m.current6);
      stream.next(m.current7);
      stream.next(m.current8);
      stream.next(m.current9);
      stream.next(m.current10);
      stream.next(m.current11);
      stream.next(m.current12);
      stream.next(m.current13);
      stream.next(m.current14);
      stream.next(m.current15);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Power_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::power_distribution_panel::Power_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::power_distribution_panel::Power_<ContainerAllocator>& v)
  {
    s << indent << "voltage: ";
    Printer<float>::stream(s, indent + "  ", v.voltage);
    s << indent << "current0: ";
    Printer<float>::stream(s, indent + "  ", v.current0);
    s << indent << "current1: ";
    Printer<float>::stream(s, indent + "  ", v.current1);
    s << indent << "current2: ";
    Printer<float>::stream(s, indent + "  ", v.current2);
    s << indent << "current3: ";
    Printer<float>::stream(s, indent + "  ", v.current3);
    s << indent << "current4: ";
    Printer<float>::stream(s, indent + "  ", v.current4);
    s << indent << "current5: ";
    Printer<float>::stream(s, indent + "  ", v.current5);
    s << indent << "current6: ";
    Printer<float>::stream(s, indent + "  ", v.current6);
    s << indent << "current7: ";
    Printer<float>::stream(s, indent + "  ", v.current7);
    s << indent << "current8: ";
    Printer<float>::stream(s, indent + "  ", v.current8);
    s << indent << "current9: ";
    Printer<float>::stream(s, indent + "  ", v.current9);
    s << indent << "current10: ";
    Printer<float>::stream(s, indent + "  ", v.current10);
    s << indent << "current11: ";
    Printer<float>::stream(s, indent + "  ", v.current11);
    s << indent << "current12: ";
    Printer<float>::stream(s, indent + "  ", v.current12);
    s << indent << "current13: ";
    Printer<float>::stream(s, indent + "  ", v.current13);
    s << indent << "current14: ";
    Printer<float>::stream(s, indent + "  ", v.current14);
    s << indent << "current15: ";
    Printer<float>::stream(s, indent + "  ", v.current15);
  }
};

} // namespace message_operations
} // namespace ros

#endif // POWER_DISTRIBUTION_PANEL_MESSAGE_POWER_H
