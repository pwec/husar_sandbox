#ifndef o3dcam_H
#define	o3dcam_H

#include "O3DClient.hpp"
#include "o3dCompleteData.hpp"
#include "o3dCameraSettings.hpp"
#include "pmdCam/pmd_settings.h"

// OpenCV includes
#include <opencv2/imgproc/imgproc.hpp>

#include <cstdlib>
#include <string>

using namespace std;
using namespace cv;
using namespace o3d;

/**
  * @class o3dcam
  * @brief IFM sensor class.
  */
class o3dcam {
public:
    /**
      * Constructor.
    */
    o3dcam();
    ~o3dcam();

    /**
     * Connect o3dcam object to IFM camera through TCP/IP
     */
    void connectToSensor();

    /**
     * Save sensor data to file.
     * @param filename name of file to write (need *.pmdc extension)
     */
    bool saveData(string filename="data.pmdc");

    /**
     * Callback to camera settings signal.
     * @param msg settings message
     */
    void cameraSettings_cb(pmdCam::pmd_settings msg);

    /**
     * Read sensor data from file.
     * @param filename name of file to read (need *.pmdc extension)
     */
    void readFile(string filename);

    /**
     * Read data from sensor.
     */
    void readSensor();

    /**
     * Perform operation on sensor data and convert it into OpenCV images.
     */
    void obtainImages();

    /**
     * Get IFM camera grayscale view.
     */
    Mat getGrayImage();

    /**
     * Get IFM camera depth view.
     */
    Mat getDepthImage();

private:
    o3dClient client;
    o3dCompleteData *_sensorData;
    int connectionStatus;
    Mat pmdGrayImage, pmdDepthImage;

private:
    /**
     * Set up IFM camera settings.
     * @param settings_msg ROS message with new sensor settings
     */
    void setCamSettings(pmdCam::pmd_settings settings_msg);

    /**
     * Read sensor data matrix as a OpenCV image.
     * @param data pointer to sensor raw data
     * @param type data type
     * @param image pointer to OpenCV image matrix
     */
    void getPMDCameraImage(o3dCompleteData *_data, o3dDataType type, Mat *_image);

};

#endif	/* o3dcam_HPP */

