/* 
 * File:   o3dCameraSettings.cpp
 * Author: Maciek
 * 
 * Created on 3 listopad 2010, 10:52
 */

#include "o3dCameraSettings.hpp"

#include "communication/structs.h"
#include "O3DClient.hpp"

using namespace o3d;

o3dCameraSettings::o3dCameraSettings()
{
    _data_port    = 50002;    
    _ip    = "192.168.0.63"; //Adres fabryczny
    _xml_port = 8080; //Port fabryczny
    _trigger_mode    = 3; //SW
    _median_filter = 0;
    _mean_value_filter = 0;
    _modulation_frequency  = 0;
    _illu_mode = 0;
    _reset_duration = 20;
    _sampling_mode = 0; //Single
    _integration_time_single = 125;
    _integration_time_double = 2000;
    _ifm_time      = 100;
    _delay_time = 100;

    _unambiguous_range = 0.0;
}


o3dCameraSettings::~o3dCameraSettings()
{

}

const o3dCameraSettings& o3dCameraSettings::operator=(const o3dCameraSettings& orig)
{
    _ifm_time = orig._ifm_time;
    _modulation_frequency = orig._modulation_frequency;
    _illu_mode = orig._illu_mode;
    _reset_duration = orig._reset_duration;
    _median_filter = orig._median_filter;
    _mean_value_filter = orig._mean_value_filter;
    _trigger_mode = orig._trigger_mode;
    _sampling_mode = orig._sampling_mode;
    _integration_time_single = orig._integration_time_single;
    _integration_time_double = orig._integration_time_double;
    _delay_time = orig._delay_time;
    _unambiguous_range = orig._unambiguous_range;
    _evaluation_time = orig._evaluation_time;
    _data_port = orig._data_port;
    _ip = orig._ip;
    _xml_port = orig._xml_port;
}


void o3dCameraSettings::setFrontendData(T_FrontendData *frontend_data)
{
    _ifm_time = frontend_data->i_ifmTime;
    _modulation_frequency = frontend_data->i_modulationFrequency;
    _illu_mode = frontend_data->i_illuMode;
    _reset_duration = frontend_data->i_resetDuration;
    _sampling_mode = frontend_data->i_samplingMode;
    _integration_time_single = frontend_data->i_integrationTimeSingle;
    _integration_time_double = frontend_data->i_integrationTimeDouble;    
}

void o3dCameraSettings::getFrontendData(T_FrontendData *frontend_data)
{
    frontend_data->i_ifmTime   = _ifm_time;
    frontend_data->i_modulationFrequency  = _modulation_frequency;
    frontend_data->i_illuMode  = _illu_mode;
    frontend_data->i_resetDuration  = _reset_duration;
    frontend_data->i_samplingMode  = _sampling_mode;
    frontend_data->i_integrationTimeSingle  = _integration_time_single;
    frontend_data->i_integrationTimeDouble  = _integration_time_double;   
}

void o3dCameraSettings::setImageHeader(ImageHeaderInformation *header)
{
    _ifm_time = header->IfmTime;
    _modulation_frequency = header->FrequencyMode;
    _illu_mode = header->IlluMode;    
    _median_filter = header->MedianFilter;
    _mean_value_filter = header->MeanFilter;
    _trigger_mode = header->CurrentTriggerMode;
    _sampling_mode = header->SamplingMode;
    //There is some bug on the camera sight
    _integration_time_single = header->IntegrationTime_Exp1;
    //There is some bug on the camera sight
    _integration_time_double = header->IntegrationTime_Exp0;
    _unambiguous_range = header->UnambiguousRange;
    _evaluation_time = header->EvaluationTime;
}

void o3dCameraSettings::getImageHeader(ImageHeaderInformation *header)
{
    header->IfmTime =  _ifm_time;
    header->FrequencyMode  = _modulation_frequency;
    header->IlluMode  = _illu_mode;    
    header->MedianFilter  = _median_filter;
    header->MeanFilter  = _mean_value_filter;
    header->CurrentTriggerMode  = _trigger_mode;
    header->SamplingMode  = _sampling_mode;
    //There is some bug on the camera sight
    header->IntegrationTime_Exp1  = _integration_time_single;
    //There is some bug on the camera sight
    header->IntegrationTime_Exp0  = _integration_time_double;
    header->UnambiguousRange  = _unambiguous_range;
    header->EvaluationTime  = _evaluation_time;
}

void o3dCameraSettings::setModulationFrequency(int f)
{
    _modulation_frequency=f;
}

int o3dCameraSettings::getModulationFrequency()
{
    return _modulation_frequency;
}

void o3dCameraSettings::setIlluMode(int illu_mode)
{
    _illu_mode=illu_mode;
}

int o3dCameraSettings::getIlluMode()
{
    return _illu_mode;
}

void o3dCameraSettings::setResetDuration(int rd)
{
    _reset_duration=rd;
}

int o3dCameraSettings::getResetDuration()
{
    return _reset_duration;
}

void o3dCameraSettings::setMedianFilter(bool status)
{
    _median_filter = (int)status;
}

bool o3dCameraSettings::getMedianFilter()
{
    return (bool)_median_filter;
}

void o3dCameraSettings::setMeanValueFilter(bool status)
{
    _mean_value_filter =(int)status;
}

bool o3dCameraSettings::getMeanValueFilter()
{
    return (bool)_mean_value_filter;
}

void o3dCameraSettings::setTriggerMode(int mode)
{
    _trigger_mode=mode;
}

int o3dCameraSettings::getTriggerMode()
{
    return _trigger_mode;
}

void o3dCameraSettings::setIP(std::string IP)
{
    _ip=IP;
}

std::string o3dCameraSettings::getIP()
{
    return _ip;
}

void o3dCameraSettings::setXmlPort(int port)
{
    _xml_port=port;
}

int o3dCameraSettings::getXmlPort()
{
    return _xml_port;
}

void o3dCameraSettings::setDataPort(int port)
{
    _data_port=port;
}

int o3dCameraSettings::getDataPort()
{
    return _data_port;
}

void o3dCameraSettings::setSamplingMode(int mode)
{
    _sampling_mode=mode;
}

int o3dCameraSettings::getSamplingMode()
{
    return _sampling_mode;
}

void o3dCameraSettings::setIntegrationTimeSingle(int time)
{
    _integration_time_single = time;
}

int o3dCameraSettings::getIntegrationTimeSingle()
{
    return _integration_time_single;
}

void o3dCameraSettings::setIntegrationTimeDouble(int time)
{
    _integration_time_double = time;
}

int o3dCameraSettings::getIntegrationTimeDouble()
{
    return _integration_time_double;
}

void o3dCameraSettings::setDelayTime(int time)
{
    _ifm_time = time;
}

int o3dCameraSettings::getDelayTime()
{
    return _ifm_time;
}


void o3dCameraSettings::setEvaluationTime(float time)
{
    _evaluation_time = time;
}

float o3dCameraSettings::getEvaluationTime()
{
    return _evaluation_time;
}

void o3dCameraSettings::setIfmTime(float time)
{
    _ifm_time = time;
}

float o3dCameraSettings::getIfmTime()
{
    return _ifm_time;
}

void o3dCameraSettings::setUnambiguousRange(float range)
{
    _unambiguous_range = range;
}

float o3dCameraSettings::getUnambiguousRange()
{
    return _unambiguous_range;
}

