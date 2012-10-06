/* 
 * File:   o3dCameraSettings.hpp
 * Author: Maciek
 *
 * Created on 3 listopad 2010, 10:52
 */

#ifndef O3DCAMERASETTINGS_HPP
#define	O3DCAMERASETTINGS_HPP

#include <string>



namespace o3d{

    class T_FrontendData;
    class ImageHeaderInformation;
    class o3dClient;
    class o3dCompleteData;

class o3dCameraSettings {
public:
    o3dCameraSettings();

    virtual ~o3dCameraSettings();

    const o3dCameraSettings& operator=(const o3dCameraSettings& orig);

    void setFrontendData(T_FrontendData *frontend_data);
    void getFrontendData(T_FrontendData *frontend_data);

    void setImageHeader(ImageHeaderInformation *header);
    void getImageHeader(ImageHeaderInformation *header);

    void setModulationFrequency(int f);
    int getModulationFrequency();

    void setIlluMode(int illu_mode);
    int getIlluMode();

    void setResetDuration(int rd);
    int getResetDuration();

    void setMedianFilter(bool status);
    bool getMedianFilter();

    void setMeanValueFilter(bool status);
    bool getMeanValueFilter();

    void setTriggerMode(int mode);
    int getTriggerMode();

    void setIP(std::string IP);
    std::string getIP();

    void setXmlPort(int port);
    int getXmlPort();

    void setDataPort(int port);
    int getDataPort();

    void setSamplingMode(int mode);
    int getSamplingMode();

    void setIntegrationTimeSingle(int time);
    int getIntegrationTimeSingle();

    void setIntegrationTimeDouble(int time);
    int getIntegrationTimeDouble();

    void setDelayTime(int time);
    int getDelayTime();

    void setEvaluationTime(float time);
    float getEvaluationTime();

    void setIfmTime(float time);
    float getIfmTime();

    void setUnambiguousRange(float range);
    float getUnambiguousRange();

private:

    float               _ifm_time;
    int                 _modulation_frequency;
    int                 _illu_mode;
    int                 _reset_duration;
    bool                _median_filter;
    bool                _mean_value_filter;
    int                 _trigger_mode;
    int                 _sampling_mode;
    int                 _integration_time_single;
    int                 _integration_time_double;
    int                 _delay_time;
    float               _unambiguous_range;
    float               _evaluation_time;
    int                 _data_port;
    std::string         _ip;
    int                 _xml_port;

    friend class o3dClient;
    friend class o3dCompleteData;
};
}//namespace o3d

#endif	/* O3DCAMERASETTINGS_HPP */

