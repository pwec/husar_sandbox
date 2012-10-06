/* 
 * File:   o3dCompleteData.hpp
 * Author: Maciek
 *
 * Created on 24 październik 2010, 10:25
 */

#ifndef _O3DCOMPLETEDATA_HPP
#define	_O3DCOMPLETEDATA_HPP

#include "o3dConfig.h"

#include <string>
#include <vector>

#ifdef O3D_USE_BOOST

#include <boost/signals2.hpp>

#endif

#include "o3dDataTypes.hpp"

namespace o3d{

class o3dClient;
class o3dCameraSettings;

//struct o3dPosition{
//    double x,y,z,rx,ry,rz;
//};

class o3dCompleteData
{
public:
    o3dCompleteData();
    virtual ~o3dCompleteData();

    const o3dCompleteData& operator=(const o3dCompleteData& orig);

    float* getData(o3dDataType data_type);

    bool save(std::string fname);
    bool load(std::string fname);

    std::string getFileName();

    void dataChanged();

#ifdef O3D_USE_BOOST
    boost::signals2::signal<void()>& sigDataChanged();
#endif
    

    int getWidth();
    int getHeight();

    o3dCameraSettings* getCameraSettings();

    unsigned long int  getTimeStamp();

    void setValidImage(bool valid);
    bool getValidImage();

    double* getTransformationMatrix();

    std::vector<int>& getCorrectPointsIndices();

    int findCorrectPoints();

    bool* getCorrectPointsTable();
    void updateCorrectPoints();

private:
    float data_d[IMG_HEIGHT*IMG_WIDTH];
    float data_i[IMG_HEIGHT*IMG_WIDTH];
    float data_s[IMG_HEIGHT*IMG_WIDTH];
    float data_e[IMG_HEIGHT*IMG_WIDTH];
    float data_f[IMG_HEIGHT*IMG_WIDTH];
    float data_g[IMG_HEIGHT*IMG_WIDTH];
    float data_x[IMG_HEIGHT*IMG_WIDTH];
    float data_y[IMG_HEIGHT*IMG_WIDTH];
    float data_z[IMG_HEIGHT*IMG_WIDTH];
    bool correct[IMG_HEIGHT*IMG_WIDTH];
    int width;
    int height;

    double transformation_matrix[16];

    std::vector<int> _correct_points_indices;

#ifdef O3D_USE_BOOST
    boost::signals2::signal<void()> _sig_data_changed;
#endif

    o3dCameraSettings* _camera_settings;

    friend class o3dClient;

    unsigned long int   _time_stamp;    
    bool                _valid_image;

    std::string _filename;

};
}//namespace o3d
#endif	/* _O3DCOMPLETEDATA_HPP */

