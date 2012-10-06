; Auto-generated. Do not edit!


(cl:in-package pmdCam-msg)


;//! \htmlinclude pmd_settings.msg.html

(cl:defclass <pmd_settings> (roslisp-msg-protocol:ros-message)
  ((ifm_time
    :reader ifm_time
    :initarg :ifm_time
    :type cl:float
    :initform 0.0)
   (modulation_frequency
    :reader modulation_frequency
    :initarg :modulation_frequency
    :type cl:integer
    :initform 0)
   (illu_mode
    :reader illu_mode
    :initarg :illu_mode
    :type cl:integer
    :initform 0)
   (reset_duration
    :reader reset_duration
    :initarg :reset_duration
    :type cl:integer
    :initform 0)
   (median_filter
    :reader median_filter
    :initarg :median_filter
    :type cl:boolean
    :initform cl:nil)
   (mean_filter
    :reader mean_filter
    :initarg :mean_filter
    :type cl:boolean
    :initform cl:nil)
   (trigger_mode
    :reader trigger_mode
    :initarg :trigger_mode
    :type cl:integer
    :initform 0)
   (sampling_mode
    :reader sampling_mode
    :initarg :sampling_mode
    :type cl:integer
    :initform 0)
   (integration_time_single
    :reader integration_time_single
    :initarg :integration_time_single
    :type cl:integer
    :initform 0)
   (integration_time_double
    :reader integration_time_double
    :initarg :integration_time_double
    :type cl:integer
    :initform 0)
   (delay_time
    :reader delay_time
    :initarg :delay_time
    :type cl:integer
    :initform 0)
   (unambiguous_range
    :reader unambiguous_range
    :initarg :unambiguous_range
    :type cl:float
    :initform 0.0)
   (evaluation_time
    :reader evaluation_time
    :initarg :evaluation_time
    :type cl:float
    :initform 0.0)
   (data_port
    :reader data_port
    :initarg :data_port
    :type cl:integer
    :initform 0)
   (ip
    :reader ip
    :initarg :ip
    :type cl:string
    :initform "")
   (xml_port
    :reader xml_port
    :initarg :xml_port
    :type cl:integer
    :initform 0))
)

(cl:defclass pmd_settings (<pmd_settings>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pmd_settings>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pmd_settings)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pmdCam-msg:<pmd_settings> is deprecated: use pmdCam-msg:pmd_settings instead.")))

(cl:ensure-generic-function 'ifm_time-val :lambda-list '(m))
(cl:defmethod ifm_time-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:ifm_time-val is deprecated.  Use pmdCam-msg:ifm_time instead.")
  (ifm_time m))

(cl:ensure-generic-function 'modulation_frequency-val :lambda-list '(m))
(cl:defmethod modulation_frequency-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:modulation_frequency-val is deprecated.  Use pmdCam-msg:modulation_frequency instead.")
  (modulation_frequency m))

(cl:ensure-generic-function 'illu_mode-val :lambda-list '(m))
(cl:defmethod illu_mode-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:illu_mode-val is deprecated.  Use pmdCam-msg:illu_mode instead.")
  (illu_mode m))

(cl:ensure-generic-function 'reset_duration-val :lambda-list '(m))
(cl:defmethod reset_duration-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:reset_duration-val is deprecated.  Use pmdCam-msg:reset_duration instead.")
  (reset_duration m))

(cl:ensure-generic-function 'median_filter-val :lambda-list '(m))
(cl:defmethod median_filter-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:median_filter-val is deprecated.  Use pmdCam-msg:median_filter instead.")
  (median_filter m))

(cl:ensure-generic-function 'mean_filter-val :lambda-list '(m))
(cl:defmethod mean_filter-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:mean_filter-val is deprecated.  Use pmdCam-msg:mean_filter instead.")
  (mean_filter m))

(cl:ensure-generic-function 'trigger_mode-val :lambda-list '(m))
(cl:defmethod trigger_mode-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:trigger_mode-val is deprecated.  Use pmdCam-msg:trigger_mode instead.")
  (trigger_mode m))

(cl:ensure-generic-function 'sampling_mode-val :lambda-list '(m))
(cl:defmethod sampling_mode-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:sampling_mode-val is deprecated.  Use pmdCam-msg:sampling_mode instead.")
  (sampling_mode m))

(cl:ensure-generic-function 'integration_time_single-val :lambda-list '(m))
(cl:defmethod integration_time_single-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:integration_time_single-val is deprecated.  Use pmdCam-msg:integration_time_single instead.")
  (integration_time_single m))

(cl:ensure-generic-function 'integration_time_double-val :lambda-list '(m))
(cl:defmethod integration_time_double-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:integration_time_double-val is deprecated.  Use pmdCam-msg:integration_time_double instead.")
  (integration_time_double m))

(cl:ensure-generic-function 'delay_time-val :lambda-list '(m))
(cl:defmethod delay_time-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:delay_time-val is deprecated.  Use pmdCam-msg:delay_time instead.")
  (delay_time m))

(cl:ensure-generic-function 'unambiguous_range-val :lambda-list '(m))
(cl:defmethod unambiguous_range-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:unambiguous_range-val is deprecated.  Use pmdCam-msg:unambiguous_range instead.")
  (unambiguous_range m))

(cl:ensure-generic-function 'evaluation_time-val :lambda-list '(m))
(cl:defmethod evaluation_time-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:evaluation_time-val is deprecated.  Use pmdCam-msg:evaluation_time instead.")
  (evaluation_time m))

(cl:ensure-generic-function 'data_port-val :lambda-list '(m))
(cl:defmethod data_port-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:data_port-val is deprecated.  Use pmdCam-msg:data_port instead.")
  (data_port m))

(cl:ensure-generic-function 'ip-val :lambda-list '(m))
(cl:defmethod ip-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:ip-val is deprecated.  Use pmdCam-msg:ip instead.")
  (ip m))

(cl:ensure-generic-function 'xml_port-val :lambda-list '(m))
(cl:defmethod xml_port-val ((m <pmd_settings>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:xml_port-val is deprecated.  Use pmdCam-msg:xml_port instead.")
  (xml_port m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pmd_settings>) ostream)
  "Serializes a message object of type '<pmd_settings>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ifm_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'modulation_frequency)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'illu_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'reset_duration)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'median_filter) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'mean_filter) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'trigger_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'sampling_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'integration_time_single)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'integration_time_double)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'delay_time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'unambiguous_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'evaluation_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'data_port)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'ip))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'ip))
  (cl:let* ((signed (cl:slot-value msg 'xml_port)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pmd_settings>) istream)
  "Deserializes a message object of type '<pmd_settings>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ifm_time) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'modulation_frequency) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'illu_mode) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reset_duration) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:setf (cl:slot-value msg 'median_filter) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'mean_filter) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger_mode) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sampling_mode) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'integration_time_single) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'integration_time_double) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'delay_time) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'unambiguous_range) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'evaluation_time) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'data_port) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ip) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'ip) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'xml_port) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pmd_settings>)))
  "Returns string type for a message object of type '<pmd_settings>"
  "pmdCam/pmd_settings")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pmd_settings)))
  "Returns string type for a message object of type 'pmd_settings"
  "pmdCam/pmd_settings")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pmd_settings>)))
  "Returns md5sum for a message object of type '<pmd_settings>"
  "54f29591c8c2bec4e19f7c643b221d48")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pmd_settings)))
  "Returns md5sum for a message object of type 'pmd_settings"
  "54f29591c8c2bec4e19f7c643b221d48")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pmd_settings>)))
  "Returns full string definition for message of type '<pmd_settings>"
  (cl:format cl:nil "float32 ifm_time~%int64 modulation_frequency~%int64 illu_mode~%int64 reset_duration~%bool median_filter~%bool mean_filter~%int64 trigger_mode~%int64 sampling_mode~%int64 integration_time_single~%int64 integration_time_double~%int64 delay_time~%float32 unambiguous_range~%float32 evaluation_time~%int64 data_port~%string ip~%int64 xml_port~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pmd_settings)))
  "Returns full string definition for message of type 'pmd_settings"
  (cl:format cl:nil "float32 ifm_time~%int64 modulation_frequency~%int64 illu_mode~%int64 reset_duration~%bool median_filter~%bool mean_filter~%int64 trigger_mode~%int64 sampling_mode~%int64 integration_time_single~%int64 integration_time_double~%int64 delay_time~%float32 unambiguous_range~%float32 evaluation_time~%int64 data_port~%string ip~%int64 xml_port~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pmd_settings>))
  (cl:+ 0
     4
     8
     8
     8
     1
     1
     8
     8
     8
     8
     8
     4
     4
     8
     4 (cl:length (cl:slot-value msg 'ip))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pmd_settings>))
  "Converts a ROS message object to a list"
  (cl:list 'pmd_settings
    (cl:cons ':ifm_time (ifm_time msg))
    (cl:cons ':modulation_frequency (modulation_frequency msg))
    (cl:cons ':illu_mode (illu_mode msg))
    (cl:cons ':reset_duration (reset_duration msg))
    (cl:cons ':median_filter (median_filter msg))
    (cl:cons ':mean_filter (mean_filter msg))
    (cl:cons ':trigger_mode (trigger_mode msg))
    (cl:cons ':sampling_mode (sampling_mode msg))
    (cl:cons ':integration_time_single (integration_time_single msg))
    (cl:cons ':integration_time_double (integration_time_double msg))
    (cl:cons ':delay_time (delay_time msg))
    (cl:cons ':unambiguous_range (unambiguous_range msg))
    (cl:cons ':evaluation_time (evaluation_time msg))
    (cl:cons ':data_port (data_port msg))
    (cl:cons ':ip (ip msg))
    (cl:cons ':xml_port (xml_port msg))
))
