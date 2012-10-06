
#include "o3dcam.hpp"

o3dcam::o3dcam()
{
    // initiate Mat images
    pmdGrayImage = Mat::zeros(IMG_HEIGHT, IMG_WIDTH, CV_32F);
    pmdDepthImage = Mat::zeros(IMG_HEIGHT, IMG_WIDTH, CV_32F);

    _sensorData = new o3dCompleteData;

    connectionStatus=-1;
    client.cleanupSensor();
}

o3dcam::~o3dcam()
{
    client.cleanupSensor();
    delete _sensorData;
}


void o3dcam::connectToSensor()
{
    connectionStatus = client.setupSensor();
    if(connectionStatus==0) cout << "sensor connected\n";
}

void o3dcam::readSensor()
{
    if(connectionStatus==0)
    {
        client.readData();
        _sensorData = client.getCompleteData();
        cout << "data read\n";
    }
}

void o3dcam::readFile(string filename)
{
    if(filename.length() > 5)
    {
        if( filename.substr(filename.length()-5) == ".pmdc" )
        {
            //_sensorData = readDataFromFile(filename);
            bool opened = _sensorData->load(filename);
            if(opened) cout << filename << " opened\n";
            else cout << "Error: błędna nazwa pliku\n";
        }
        else cout << "Error: błędna nazwa pliku\n";
    }
}

bool o3dcam::saveData(string filename)
{
    if(connectionStatus!=0)
    {
        if(filename.length() > 5)
        {
            if(filename.substr(filename.length()-5) == ".pmdc")
            {
                //bool saved = client.getCompleteData()->save(filename);
                bool saved = _sensorData->save(filename);

                if(saved) cout << "sensor data \"" << filename  <<"\" saved\n";
                else cout << "Error: saving failed\n";
                return saved;
            }
            else cout << "Error: błędna nazwa pliku/n";
        }
        else cout << "Error: błędna nazwa pliku/n";
    }
    else cout << "Error: nothing to save\n";

    return false;
}

Mat o3dcam::getDepthImage()
{
    return pmdDepthImage;
}

Mat o3dcam::getGrayImage()
{
    return pmdGrayImage;
}

void o3dcam::obtainImages()
{
    getPMDCameraImage(_sensorData, dtype_d, &pmdDepthImage);
    getPMDCameraImage(_sensorData, dtype_i, &pmdGrayImage);
}

void o3dcam::getPMDCameraImage(o3dCompleteData *_data, o3dDataType type, Mat *_image)
{
    float *_rawImageData;
    _rawImageData = NULL;
    _rawImageData = _data->getData(type);
    // fill maxtrix with data received from PMD camera
    Mat tmpImage = Mat::zeros(IMG_HEIGHT, IMG_WIDTH, CV_32F); // Mat::zeros(int rows, int cols, int type)
    for (int i = 0; i < IMG_HEIGHT * IMG_WIDTH; i++) {
        float val = *(_rawImageData + i);
        //if (val < 0) val = 0;
        tmpImage.at<float>(0, i) = val; // WTF ?
    }

    Mat tmpImage2;
    //normalize(tmpImage, tmpImage2, 1, 0, NORM_INF);
    //transpose(tmpImage2, *_image);
    transpose(tmpImage, *_image);
}

void o3dcam::cameraSettings_cb(pmdCam::pmd_settings msg)
{
    string info;
    stringstream ss;
    ss << "pmdCamServer || new camera settings " <<  ros::Time::now();
    info = ss.str();
    ss.flush();
    ROS_INFO("%s", info.c_str());
    setCamSettings(msg);
}


void o3dcam::setCamSettings(pmdCam::pmd_settings settings_msg)
{
    // TODO: need connected camera?
    o3dCameraSettings *pmdcam;
    pmdcam = client.getCameraSettings();

    pmdcam->setDataPort(settings_msg.data_port);
    pmdcam->setIP(settings_msg.ip);
    pmdcam->setXmlPort(settings_msg.xml_port);
    pmdcam->setTriggerMode(settings_msg.trigger_mode);
    pmdcam->setMedianFilter(settings_msg.median_filter);
    pmdcam->setMeanValueFilter(settings_msg.mean_filter);
    pmdcam->setModulationFrequency(settings_msg.data_port);
    pmdcam->setIlluMode(settings_msg.illu_mode);
    pmdcam->setResetDuration(settings_msg.reset_duration);
    pmdcam->setSamplingMode(settings_msg.sampling_mode);
    pmdcam->setIntegrationTimeSingle(settings_msg.integration_time_single);
    pmdcam->setIntegrationTimeDouble(settings_msg.integration_time_double);
    pmdcam->setIfmTime(settings_msg.ifm_time);
    pmdcam->setDelayTime(settings_msg.delay_time);
    pmdcam->setUnambiguousRange(settings_msg.unambiguous_range);

    client.cleanupSensor();
    connectionStatus = client.setupSensor();

    /*
    _data_port    = 50002;
    _ip    = "192.168.0.63"; //Adres fabryczny
    _xml_port = 8080; //Port fabryczny
    _trigger_mode    = 3; //SW
    _median_filter = 0;
    _mean_filter = 0;
    _modulation_frequency  = 0;
    _illu_mode = 0;
    _reset_duration = 20;
    _sampling_mode = 0; //Single
    _integration_time_single = 125;
    _integration_time_double = 2000;
    _ifm_time      = 100;
    _delay_time = 100;

    _unambiguous_range = 0.0;
      */
}
