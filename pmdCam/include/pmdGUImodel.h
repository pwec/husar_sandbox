#ifndef PMDGUIMODEL_H
#define PMDGUIMODEL_H

#include "ros/ros.h"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/Empty.h"
#include <QImage>
#include <QVector>
#include "pmdCam/pmd_settings.h"
#include "pmdCam/image_box.h"
#include "pmdCam/data_flow.h"

#define IMG_WIDTH 64
#define IMG_HEIGHT 50

typedef QVector<QImage> QImageVec;

/**
  * @class pmdGUImodel
  * @brief Bridge between GUI and ROS.
  */
class pmdGUImodel : public QObject
{
    Q_OBJECT
signals:
    /**
     * Signal with images to set in GUI (settings part)
     * @param qimageVec vector of images to set
     */
    void newSettingsImages(QImageVec);

    /**
     * Signal with images to set in GUI (calibration part)
     * @param qimageVec vector of images to set
     */
    void newCalibrationImages(QImageVec);

public slots:
    /**
     * Slot getting from GUI new IFM camera settings
     * @param new IFM camera settings
     */
    void setSettings(pmdCam::pmd_settings);

    /**
     * Slot getting from GUI signal of acceptance of calibration image pair.
     */
    void acceptCalibrationImage();

    /**
     * Slot getting from GUI signal to calibrate cameras.
     */
    void calibrateCameras();

    /**
     * Slot getting from GUI signal to start calibration process.
     */
    void calibrationInProgress(bool var);

public:
    /**
     * Constructor
     * @param nh ROS NodeHandle Cam3D object cooperate with
     * @param settimgs_img_topic name of ROS topic to subscribe images useful for adjusting IFM camera settings
     * @param settimgs_topic name of ROS topic to advertise new IFM camera settings
     * @param calibration_img_topic name of ROS topic to subscribe images useful for calibration cameras
     * @param data_flow_topic name of ROS topic controll calibration process
     */
    pmdGUImodel(ros::NodeHandle nh,
                const std::string settings_img_topic,
                const std::string settings_topic,
                const std::string calibration_img_topic,
                const std::string data_flow_topic);

    /**
     * ROS listener callback for settings images.
     * @param image ROS message containing images useful for adjusting IFM camera settings
     */
    void imageSettingsCallback(pmdCam::image_box image);

    /**
     * ROS listener callback for calibration images..
     * @param image ROS message containing images useful for cameras calibration
     */
    void imageCalibrationCallback(pmdCam::image_box image);

public:
    ros::Subscriber img_settings_sub;
    ros::Subscriber img_calibration_sub;
    ros::Publisher settings_pub;
    ros::Publisher data_flow_pub;
};

#endif // PMDGUIMODEL_H
