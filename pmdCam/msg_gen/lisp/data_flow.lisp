; Auto-generated. Do not edit!


(cl:in-package pmdCam-msg)


;//! \htmlinclude data_flow.msg.html

(cl:defclass <data_flow> (roslisp-msg-protocol:ros-message)
  ((calibration_in_progress
    :reader calibration_in_progress
    :initarg :calibration_in_progress
    :type cl:boolean
    :initform cl:nil)
   (accept_last_pair
    :reader accept_last_pair
    :initarg :accept_last_pair
    :type cl:boolean
    :initform cl:nil)
   (perform_calibration
    :reader perform_calibration
    :initarg :perform_calibration
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass data_flow (<data_flow>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <data_flow>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'data_flow)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pmdCam-msg:<data_flow> is deprecated: use pmdCam-msg:data_flow instead.")))

(cl:ensure-generic-function 'calibration_in_progress-val :lambda-list '(m))
(cl:defmethod calibration_in_progress-val ((m <data_flow>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:calibration_in_progress-val is deprecated.  Use pmdCam-msg:calibration_in_progress instead.")
  (calibration_in_progress m))

(cl:ensure-generic-function 'accept_last_pair-val :lambda-list '(m))
(cl:defmethod accept_last_pair-val ((m <data_flow>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:accept_last_pair-val is deprecated.  Use pmdCam-msg:accept_last_pair instead.")
  (accept_last_pair m))

(cl:ensure-generic-function 'perform_calibration-val :lambda-list '(m))
(cl:defmethod perform_calibration-val ((m <data_flow>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pmdCam-msg:perform_calibration-val is deprecated.  Use pmdCam-msg:perform_calibration instead.")
  (perform_calibration m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <data_flow>) ostream)
  "Serializes a message object of type '<data_flow>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'calibration_in_progress) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'accept_last_pair) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'perform_calibration) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <data_flow>) istream)
  "Deserializes a message object of type '<data_flow>"
    (cl:setf (cl:slot-value msg 'calibration_in_progress) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'accept_last_pair) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'perform_calibration) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<data_flow>)))
  "Returns string type for a message object of type '<data_flow>"
  "pmdCam/data_flow")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'data_flow)))
  "Returns string type for a message object of type 'data_flow"
  "pmdCam/data_flow")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<data_flow>)))
  "Returns md5sum for a message object of type '<data_flow>"
  "bfe76f62bc51cb5839a65353a5344d08")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'data_flow)))
  "Returns md5sum for a message object of type 'data_flow"
  "bfe76f62bc51cb5839a65353a5344d08")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<data_flow>)))
  "Returns full string definition for message of type '<data_flow>"
  (cl:format cl:nil "bool calibration_in_progress~%bool accept_last_pair~%bool perform_calibration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'data_flow)))
  "Returns full string definition for message of type 'data_flow"
  (cl:format cl:nil "bool calibration_in_progress~%bool accept_last_pair~%bool perform_calibration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <data_flow>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <data_flow>))
  "Converts a ROS message object to a list"
  (cl:list 'data_flow
    (cl:cons ':calibration_in_progress (calibration_in_progress msg))
    (cl:cons ':accept_last_pair (accept_last_pair msg))
    (cl:cons ':perform_calibration (perform_calibration msg))
))
