"""autogenerated by genmsg_py from pmd_settings.msg. Do not edit."""
import roslib.message
import struct


class pmd_settings(roslib.message.Message):
  _md5sum = "54f29591c8c2bec4e19f7c643b221d48"
  _type = "pmdCam/pmd_settings"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32 ifm_time
int64 modulation_frequency
int64 illu_mode
int64 reset_duration
bool median_filter
bool mean_filter
int64 trigger_mode
int64 sampling_mode
int64 integration_time_single
int64 integration_time_double
int64 delay_time
float32 unambiguous_range
float32 evaluation_time
int64 data_port
string ip
int64 xml_port


"""
  __slots__ = ['ifm_time','modulation_frequency','illu_mode','reset_duration','median_filter','mean_filter','trigger_mode','sampling_mode','integration_time_single','integration_time_double','delay_time','unambiguous_range','evaluation_time','data_port','ip','xml_port']
  _slot_types = ['float32','int64','int64','int64','bool','bool','int64','int64','int64','int64','int64','float32','float32','int64','string','int64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       ifm_time,modulation_frequency,illu_mode,reset_duration,median_filter,mean_filter,trigger_mode,sampling_mode,integration_time_single,integration_time_double,delay_time,unambiguous_range,evaluation_time,data_port,ip,xml_port
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(pmd_settings, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.ifm_time is None:
        self.ifm_time = 0.
      if self.modulation_frequency is None:
        self.modulation_frequency = 0
      if self.illu_mode is None:
        self.illu_mode = 0
      if self.reset_duration is None:
        self.reset_duration = 0
      if self.median_filter is None:
        self.median_filter = False
      if self.mean_filter is None:
        self.mean_filter = False
      if self.trigger_mode is None:
        self.trigger_mode = 0
      if self.sampling_mode is None:
        self.sampling_mode = 0
      if self.integration_time_single is None:
        self.integration_time_single = 0
      if self.integration_time_double is None:
        self.integration_time_double = 0
      if self.delay_time is None:
        self.delay_time = 0
      if self.unambiguous_range is None:
        self.unambiguous_range = 0.
      if self.evaluation_time is None:
        self.evaluation_time = 0.
      if self.data_port is None:
        self.data_port = 0
      if self.ip is None:
        self.ip = ''
      if self.xml_port is None:
        self.xml_port = 0
    else:
      self.ifm_time = 0.
      self.modulation_frequency = 0
      self.illu_mode = 0
      self.reset_duration = 0
      self.median_filter = False
      self.mean_filter = False
      self.trigger_mode = 0
      self.sampling_mode = 0
      self.integration_time_single = 0
      self.integration_time_double = 0
      self.delay_time = 0
      self.unambiguous_range = 0.
      self.evaluation_time = 0.
      self.data_port = 0
      self.ip = ''
      self.xml_port = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_f3q2B5q2fq.pack(_x.ifm_time, _x.modulation_frequency, _x.illu_mode, _x.reset_duration, _x.median_filter, _x.mean_filter, _x.trigger_mode, _x.sampling_mode, _x.integration_time_single, _x.integration_time_double, _x.delay_time, _x.unambiguous_range, _x.evaluation_time, _x.data_port))
      _x = self.ip
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_q.pack(self.xml_port))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      _x = self
      start = end
      end += 86
      (_x.ifm_time, _x.modulation_frequency, _x.illu_mode, _x.reset_duration, _x.median_filter, _x.mean_filter, _x.trigger_mode, _x.sampling_mode, _x.integration_time_single, _x.integration_time_double, _x.delay_time, _x.unambiguous_range, _x.evaluation_time, _x.data_port,) = _struct_f3q2B5q2fq.unpack(str[start:end])
      self.median_filter = bool(self.median_filter)
      self.mean_filter = bool(self.mean_filter)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.ip = str[start:end]
      start = end
      end += 8
      (self.xml_port,) = _struct_q.unpack(str[start:end])
      return self
    except struct.error as e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_f3q2B5q2fq.pack(_x.ifm_time, _x.modulation_frequency, _x.illu_mode, _x.reset_duration, _x.median_filter, _x.mean_filter, _x.trigger_mode, _x.sampling_mode, _x.integration_time_single, _x.integration_time_double, _x.delay_time, _x.unambiguous_range, _x.evaluation_time, _x.data_port))
      _x = self.ip
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_q.pack(self.xml_port))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 86
      (_x.ifm_time, _x.modulation_frequency, _x.illu_mode, _x.reset_duration, _x.median_filter, _x.mean_filter, _x.trigger_mode, _x.sampling_mode, _x.integration_time_single, _x.integration_time_double, _x.delay_time, _x.unambiguous_range, _x.evaluation_time, _x.data_port,) = _struct_f3q2B5q2fq.unpack(str[start:end])
      self.median_filter = bool(self.median_filter)
      self.mean_filter = bool(self.mean_filter)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.ip = str[start:end]
      start = end
      end += 8
      (self.xml_port,) = _struct_q.unpack(str[start:end])
      return self
    except struct.error as e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_q = struct.Struct("<q")
_struct_f3q2B5q2fq = struct.Struct("<f3q2B5q2fq")
