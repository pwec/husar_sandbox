/*
----------------------------------------------------------------------------
    File:          CPcomm3dErrors.h
    Author:        deegech/TOE/ifm
    Creation date: 31-Jan-2008
    Version:       $Rev: 11832 $
    Last change:   $Date: 2009-01-15 13:26:14 +0100 (Do, 15 Jan 2009) $
    Description:
     Declaration of the errors.

    Copyright (C) 2008 ifm electronic GmbH, deegech/TOE/ifm
    See accompanied file licence.txt for license information.
----------------------------------------------------------------------------
*/
/* $Id: CPcomm3dErrors.h 11832 2009-01-15 12:26:14Z deegech $ */

#ifndef _CPCOMM3DERRORS_H_
#define _CPCOMM3DERRORS_H_


#define CPCOMM3D_NO_ERRORS                          0

#define CPCOMM3D_ERR_NO_MEM                         -1


#define CPCOMM3D_FIRST_ERROR_ID                     -100
#define CPCOMM3D_SENSOR_ERR_NO_MEM                  -101
#define CPCOMM3D_SENSOR_ALREADY_CONNECTED           -102
#define CPCOMM3D_NO_IMG_AVAILABLE                   -103
#define CPCOMM3D_COMM_NOT_WORKING                   -104
#define CPCOMM3D_TIMEOUT                            -105

#define CPCOMM3D_STARTING_LIVE_IMAGE                -600
#define CPCOMM3D_LIVE_IMAGE_NOT_STARTED             -601
#define CPCOMM3D_GETTING_LIVE_IMAGE                 -602
#define CPCOMM3D_SOCKET_LIVE_IMAGE                  -603
#define CPCOMM3D_LIVE_IMAGE_IS_RUNNING              -604

#define CPCOMM3D_NOT_PRODUCT_LIST                   -701
#define CPCOMM3D_COULD_NOT_GET_PRODUCTS             -702
#define CPCOMM3D_NOT_PRODUCT_IT                     -703

#define CPCOMM3D_OPENING_FILE                       -900
#define CPCOMM3D_DIR_NOT_FOUND                      -901

#define CPCOMM3D_SENSOR_ERROR_GENERAL               -4000
#define CPCOMM3D_SENSOR_ERROR_SHORT_CIRCUIT         -4001
#define CPCOMM3D_SENSOR_ERROR_OVER_TEMP             -4002
#define CPCOMM3D_SENSOR_ERROR_HARDWARE              -4003

#define CPCOMM3D_NO_VALID_IMAGE                     -7001
#define CPCOMM3D_NO_CONNECTION                      -7012
#define CPCOMM3D_INVALID_PARAM_NAME                 -7101
#define CPCOMM3D_INVALID_PARAM_ID                   -7102
#define CPCOMM3D_SENSOR_INVALID_PARAM               -7200
#define CPCOMM3D_SENSOR_SP1_EQUAL_SP2               -7201
#define CPCOMM3D_SENSOR_SP2_EQUAL_SP1               -7202
#define CPCOMM3D_SENSOR_SP1_TOO_SMALL               -7203
#define CPCOMM3D_SENSOR_SP1_TOO_BIG                 -7204
#define CPCOMM3D_SENSOR_SP2_TOO_SMALL               -7205
#define CPCOMM3D_SENSOR_SP2_TOO_BIG                 -7206
#define CPCOMM3D_SENSOR_ANALOG_STARTPOINT_TOO_BIG   -7207
#define CPCOMM3D_SENSOR_ANALOG_ENDPOINT_TOO_SMALL   -7208
#define CPCOMM3D_SENSOR_XMLRPC_PORT_RESERVED        -7209
#define CPCOMM3D_SENSOR_IN_DHCP_MODE                -7210
#define CPCOMM3D_SENSOR_WRITING_DHCP_CMD            -7211
#define CPCOMM3D_SENSOR_OUTPUT1_MAY_FLUTTER         -7213
#define CPCOMM3D_SENSOR_OUTPUT2_MAY_FLUTTER         -7214
#define CPCOMM3D_SENSOR_PRODUCT_NOT_OPENED          -7300
#define CPCOMM3D_SENSOR_NO_SW_TRIGGER_MODE          -7400
#define CPCOMM3D_SENSOR_INVALID_TRIGGER_MODE        -7500
#define CPCOMM3D_SENSOR_INVALID_NAME                -7600
#define CPCOMM3D_SENSOR_INVALID_LOCATION            -7601
#define CPCOMM3D_SENSOR_INVALID_IP                  -7602
#define CPCOMM3D_SENSOR_INVALID_NETMASK             -7603
#define CPCOMM3D_SENSOR_INVALID_GATEWAY             -7604
#define CPCOMM3D_SENSOR_INVALID_XMLRPC_PORT         -7605
#define CPCOMM3D_SENSOR_INVALID_UDP_PORT            -7606
#define CPCOMM3D_SENSOR_INVALID_EXT_SWITCH_PARM     -7607
#define CPCOMM3D_SENSOR_INVALID_DEBOUNCED_TRIGGER   -7608
#define CPCOMM3D_SENSOR_INVALID_LASER_MODE          -7609
#define CPCOMM3D_SENSOR_INVALID_MAC_ADDRESS         -7610
#define CPCOMM3D_SENSOR_INVALID_SW_VERSION          -7611
#define CPCOMM3D_SENSOR_INVALID_VIDEO_PORT          -7612
#define CPCOMM3D_SENSOR_PRODUCTNAME_IN_USE          -7700
#define CPCOMM3D_SENSOR_NO_MEMORY_FOR_UPLOAD        -7800
#define CPCOMM3D_SENSOR_IMAGE_SOURCE_NOT_CHANGED    -7900


#define CPCOMM3D_SENSOR_DOWNLOAD_ERRORS                         -8000
#define CPCOMM3D_SENSOR_DOWNLOAD_INVALID_PRODUCT_NAME           -8001
#define CPCOMM3D_SENSOR_DOWNLOAD_NO_PRODUCT_SPECIFIC_DATA       -8002
#define CPCOMM3D_SENSOR_DOWNLOAD_CREATING_TAR_FILE              -8003

#define CPCOMM3D_SENSOR_UPLOAD_ERRORS                           -9000
#define CPCOMM3D_SENSOR_UPLOAD_PRODUCT_EXISTS                   -9001
#define CPCOMM3D_SENSOR_UPLOAD_DATABASE_NOT_COMPATIBLE          -9002
#define CPCOMM3D_SENSOR_UPLOAD_DATABASE_INCORRECT_FILESIZE      -9003
#define CPCOMM3D_SENSOR_UPLOAD_DATABASE_DIFFERENT_CRC32         -9004

/*-------------------------------------------------------------------*/
#endif // _CPCOMM3DERRORS_H_
