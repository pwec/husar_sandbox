/*
----------------------------------------------------------------------------
File:				structs.h
Author:				TO-ce
Language:			C/C++
Version:			$Revision: 8441 $
Created:			2005/02/09
Last Change:		$Date: 2008-08-20 10:04:23 +0200 (Mi, 20 Aug 2008) $
Copyright:			2008 ifm electronic GmbH
Documentation:		---
Description:
					Structs for the communication sensor-Control Panel
	
----------------------------------------------------------------------------
*/

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdlib.h>
#define HEADER_VERSION					0.001

namespace o3d{

namespace IMAGE_HEADER
{
    enum ImageTypes
    {
         INVALID_IMAGE = 0,
         DISTANCE_IMAGE ,
         INTERNAL_DATA_A,
         AMPLITUDE_IMAGE,
         INTERNAL_DATA_B,
         NORMAL_X_IMAGE,
         NORMAL_Y_IMAGE,
         NORMAL_Z_IMAGE,
         KARTESIAN_X_IMAGE,
         KARTESIAN_Y_IMAGE,
         KARTESIAN_Z_IMAGE,
         INTERNAL_DATA_C,
         SEGMENTATION_IMAGE
    };
};  

typedef struct TimeStamp
{
    float Seconds;
    float Useconds;
}T_TIMESTAMP;

typedef struct ImageHeaderInformation {
    /** @brief Imagedata size in Bytes without header */
    float                       DataSize;
	/** @brief Size of the header */
    float                       HeaderSize;
	/** @brief type of image cf. IMAGE_HEADER::ImageTypes */
    float                       ImageType;
	/** @brief consecutive version number */
    float			Version;
	/** @brief single or double integration */
    float                       SamplingMode;
	/** @brief illu status 0,1,2,3 bit coded */
    float                       IlluMode;
	/** @brief frequency mode cf. ModulationFrequency */
    float                       FrequencyMode;   
	/** @brief unambiguous range of current frequency */
    float                       UnambiguousRange;  
	/** @brief time needed by image evaluation [ms] */
    float                       EvaluationTime;       
	/** @brief first integration time single sampling mode [ms] */
    float                       IntegrationTime_Exp0;
	/** @brief second integration time double sampling mode [ms] */
    float                       IntegrationTime_Exp1;
	/** @brief timestamp */
    T_TIMESTAMP                 TimeStamp;
    float			MedianFilter;
    float			MeanFilter;
    float			internal_a1;
    float			internal_a2;
    float                       internal_a3;
    float                       internal_a4;
	/** @brief displays if image is valid or not */
    float                       ValidImage;
    float                       ErrorCode;
    float                       internal_b1;
    float                       internal_b2;
    float                       internal_b3;
    float                       CurrentTriggerMode;
    float                       internal_c1;
    float                       internal_c2;
    float                       internal_c3;
    float                       internal_c4;
    float                       IfmTime;
    float                       internal_d1;
    float                       internal_d2;
    float                       internal_d3;
    float       		internal_d4;
    float       		internal_d5;
    float       		internal_d6;
    float       		internal_d7;
    float                       internal_d8;
    float       		internal_d9;
    float       		internal_d10;
    float       		internal_d11;
    float       		internal_d12;
    float       		internal_d13;
    float       		internal_d14;
    float       		internal_d15;
    float       		internal_d16;
    float       		internal_d17;
    float       		internal_d18;
    float       		internal_d19;
    float       		internal_d20;
    float       		internal_d21;
    float       		internal_d22;
    float       		internal_d23;
    float       		internal_d24;
    float       		internal_d25;
    float       		internal_d26;
    float       		internal_d27;
    float                       internal_d28;
    float                       internal_d29;
    float                       internal_d30;
    float                       internal_d31;
    float                       internal_d32;
    float                       internal_d33;
    float                       internal_d34;
    float                       internal_d35;
    float                       internal_d36;
    float                       internal_d37;
    float                       internal_d38;
    float                       internal_d39;
    float                       internal_d40;
    float                       internal_d41;
    float                       internal_d42;
    float                       internal_d43;
    float                       internal_d44;
    float                       internal_d45;
    float                       internal_d46;
    float                       internal_d47;
    float                       internal_d48;
    float                       internal_d49;
    float                       internal_d50;
    float                       internal_d51;
    float                       internal_d52;
    float                       internal_d53;
    float                       internal_d54;
    float                       internal_d55;
    float                       internal_d56;
    float                       internal_d57;
    float                       internal_d58;
    float                       internal_d59;
    float                       internal_d60;
    float                       internal_d61;
    float                       internal_d62;
    float                       internal_d63;
    float                       internal_d64;
} T_IMAGEHEADER;

/** @brief Frontend configuration data for the Sensor */
typedef struct T_FrontendData
{
	/** @brief cf. ModulationFrequency [0,1,2] default = 0 */
    int i_modulationFrequency;           
	/** @brief single or double sampling */
    int i_samplingMode;
	/** @brief 0 = all Illus of, 1 = illu a on, 2 = illu b off, 3 = a and b on default = 1 */
    int i_illuMode;                      
    /** @brief first integration time [ms] (single sampling mode) */
	int i_integrationTimeSingle;
    /** @brief second integration time [ms] (double sampling mode) */
	int i_integrationTimeDouble;
	/** @brief reset duration [ms] default = 20 */ 
    int i_resetDuration;
	/** @brief inter frame mute time duration [ms] default = 20 [0...10000] */ 
    int i_ifmTime;			 
}T_FrontendData, *PT_FrontendData;

#define CALCULATE_EXP_TIME_VALUES       10
const int INT_TIME_VALS_1[CALCULATE_EXP_TIME_VALUES] = {50,80,130,210,345,560,920,1480,2410,3920};
const int INT_TIME_VALS_2[CALCULATE_EXP_TIME_VALUES] = {65,100,165,270,440,715,1160,1890,3075,5000};
const int ALL_INT_TIMES[CALCULATE_EXP_TIME_VALUES*2] = {50,65,80,100,130,165,210,270,345,440,560,715,920,1160,1480,1890,2410,3075,3920,5000};

}//namespace O3D
/*-------------------------------------------------------------------*/
#endif // _STRUCTS_H_
