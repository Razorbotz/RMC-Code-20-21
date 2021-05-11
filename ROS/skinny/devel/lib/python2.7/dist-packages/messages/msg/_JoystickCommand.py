# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from messages/JoystickCommand.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class JoystickCommand(genpy.Message):
  _md5sum = "90a76c8abd6ced46c905e85492d19a7f"
  _type = "messages/JoystickCommand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int8 number
int8 element
float32 value
"""
  __slots__ = ['number','element','value']
  _slot_types = ['int8','int8','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       number,element,value

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(JoystickCommand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.number is None:
        self.number = 0
      if self.element is None:
        self.element = 0
      if self.value is None:
        self.value = 0.
    else:
      self.number = 0
      self.element = 0
      self.value = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2bf().pack(_x.number, _x.element, _x.value))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 6
      (_x.number, _x.element, _x.value,) = _get_struct_2bf().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2bf().pack(_x.number, _x.element, _x.value))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 6
      (_x.number, _x.element, _x.value,) = _get_struct_2bf().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2bf = None
def _get_struct_2bf():
    global _struct_2bf
    if _struct_2bf is None:
        _struct_2bf = struct.Struct("<2bf")
    return _struct_2bf