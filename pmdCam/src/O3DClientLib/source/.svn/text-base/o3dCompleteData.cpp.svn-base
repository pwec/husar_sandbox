/* 
 * File:   o3dCompleteData.cpp
 * Author: Maciek
 * 
 * Created on 24 październik 2010, 10:25
 */

#include "o3dCompleteData.hpp"

#include "o3dCameraSettings.hpp"
#include "O3DClient.hpp"

#include <cstdio>
#include <cassert>
#include <fstream>

namespace o3d{

o3dCompleteData::o3dCompleteData()
{
    width = IMG_WIDTH;
    height = IMG_HEIGHT;

    _camera_settings = new o3dCameraSettings();

    for(int i=0; i<16; i++)
    {
        if(i/4==i%4)
            transformation_matrix[i] = 1.0;
        else
            transformation_matrix[i] = 0.0;
    }

//    _camera_position.x = 0.0;
//    _camera_position.y = 0.0;
//    _camera_position.z = 0.0;
//    _camera_position.rx = 0.0;
//    _camera_position.ry = 0.0;
//    _camera_position.rz = 0.0;
//
//    _camera_position_offset.x = 0.0;
//    _camera_position_offset.y = 0.0;
//    _camera_position_offset.z = 0.0;
//    _camera_position_offset.rx = 0.0;
//    _camera_position_offset.ry = 0.0;
//    _camera_position_offset.rz = 0.0;
}

o3dCompleteData::~o3dCompleteData()
{
    delete _camera_settings;
}

template<class T>
void copyData(T ldata[],const T rdata[],int size)
{
    for(int i=0;i<size;i++)
        ldata[i] = rdata[i];
}

const o3dCompleteData& o3dCompleteData::operator=(const o3dCompleteData& orig)
{
    copyData(data_d, orig.data_d, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_x, orig.data_x, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_y, orig.data_y, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_z, orig.data_z, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_e, orig.data_e, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_f, orig.data_f, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_g, orig.data_g, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_i, orig.data_i, IMG_HEIGHT*IMG_WIDTH);
    copyData(data_s, orig.data_s, IMG_HEIGHT*IMG_WIDTH);
    copyData(correct, orig.correct, IMG_HEIGHT*IMG_WIDTH);

    _correct_points_indices = orig._correct_points_indices;

    height = orig.height;
    width = orig.width;

    _time_stamp = orig._time_stamp;
}

float* o3dCompleteData::getData(o3dDataType data_type)
{
    switch(data_type)
    {
        case dtype_d : return &data_d[0];
        case dtype_e : return &data_e[0];
        case dtype_f : return &data_f[0];
        case dtype_g : return &data_g[0];
        case dtype_i : return &data_i[0];
        case dtype_s : return &data_s[0];
        case dtype_x : return &data_x[0];
        case dtype_y : return &data_y[0];
        case dtype_z : return &data_z[0];
        case dtype_undefined : return 0;
    }

    return 0;
}

int o3dCompleteData::getWidth()
{
    return width;
}

int o3dCompleteData::getHeight()
{
    return height;
}

o3dCameraSettings* o3dCompleteData::getCameraSettings()
{
    return _camera_settings;
}

unsigned long int  o3dCompleteData::getTimeStamp()
{
    return _time_stamp;
}

void o3dCompleteData::dataChanged()
{
    findCorrectPoints();

    #ifdef O3D_USE_BOOST
        _sig_data_changed();
    #endif
}

#ifdef O3D_USE_BOOST
boost::signals2::signal<void()>& o3dCompleteData::sigDataChanged()
{
    return _sig_data_changed;
}
#endif

bool o3dCompleteData::save(std::string fname)
{

    std::ofstream DataFile(fname.c_str(), std::ios_base::binary);

    if(!DataFile.good()) return false;

    DataFile.write(reinterpret_cast<char*>(data_d), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_e), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_f), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_g), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_i), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_s), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_x), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_y), IMG_SIZE);
    DataFile.write(reinterpret_cast<char*>(data_z), IMG_SIZE);

    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_delay_time), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_evaluation_time), sizeof(float));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_ifm_time), sizeof(float));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_illu_mode), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_integration_time_double), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_integration_time_single), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_mean_value_filter), sizeof(bool));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_median_filter), sizeof(bool));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_modulation_frequency), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_reset_duration), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_sampling_mode), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_trigger_mode), sizeof(int));
    DataFile.write(reinterpret_cast<char*>(&_camera_settings->_unambiguous_range), sizeof(int));

    DataFile.write(reinterpret_cast<char*>(transformation_matrix), sizeof(double)*16);

    DataFile.close();

    _filename = fname;

    return true;
}

bool o3dCompleteData::load(std::string fname)
{

    std::ifstream DataFile(fname.c_str(), std::ios::in | std::ios::binary);

    if(!DataFile.good()) return false;

    DataFile.read(reinterpret_cast<char*>(data_d), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_e), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_f), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_g), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_i), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_s), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_x), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_y), IMG_SIZE);
    DataFile.read(reinterpret_cast<char*>(data_z), IMG_SIZE);

    if(!DataFile.eof())
    {
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_delay_time), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_evaluation_time), sizeof(float));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_ifm_time), sizeof(float));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_illu_mode), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_integration_time_double), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_integration_time_single), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_mean_value_filter), sizeof(bool));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_median_filter), sizeof(bool));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_modulation_frequency), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_reset_duration), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_sampling_mode), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_trigger_mode), sizeof(int));
        DataFile.read(reinterpret_cast<char*>(&_camera_settings->_unambiguous_range), sizeof(int));
    }
    if(!DataFile.eof())
    {
        DataFile.read(reinterpret_cast<char*>(transformation_matrix), sizeof(double)*16);
    }

    DataFile.close();

    dataChanged();
    
    _filename = fname;

    return true;
}

std::string o3dCompleteData::getFileName()
{
    return _filename;
}

void o3dCompleteData::setValidImage(bool valid)
{
    _valid_image = valid;
}

bool o3dCompleteData::getValidImage()
{
    return _valid_image;
}

double* o3dCompleteData::getTransformationMatrix()
{
    return &transformation_matrix[0];
}

std::vector<int>& o3dCompleteData::getCorrectPointsIndices()
{
    return _correct_points_indices;
}

int o3dCompleteData::findCorrectPoints()
{
    _correct_points_indices.clear();

    int mi = 0, mj = 0;

    int k=0;
    for(int i=mi;i<getHeight()-mi;i++)
        for(int j=mj;j<getWidth()-mj;j++)
        {
            float d = getData(o3d::dtype_d)[i*getWidth()+j];

            if(d>0.0)
            {
                correct[i*getWidth()+j] = true;
                _correct_points_indices.push_back(i*getWidth()+j);
            }
            else
            {
                correct[i*getWidth()+j] = false;
            }
        }

    return _correct_points_indices.size();
}

bool* o3dCompleteData::getCorrectPointsTable()
{
    return &correct[0];
}

void o3dCompleteData::updateCorrectPoints()
{
    _correct_points_indices.clear();

    int mi = 0, mj = 0;

    int k=0;
    for(int i=mi;i<getHeight()-mi;i++)
        for(int j=mj;j<getWidth()-mj;j++)
        {
            bool c = getCorrectPointsTable()[i*getWidth()+j];

            if(c)
            {
                _correct_points_indices.push_back(i*getWidth()+j);
            }
        }

    _sig_data_changed();
}

}//namespace o3d
