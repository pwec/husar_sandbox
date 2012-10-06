#include "pmdGUImodel.h"

pmdGUImodel::pmdGUImodel(ros::NodeHandle nh,
                         const std::string settings_img_topic,
                         const std::string settings_topic,
                         const std::string calibration_img_topic,
                         const std::string data_flow_topic)
{
    img_settings_sub = nh.subscribe(settings_img_topic, 1, &pmdGUImodel::imageSettingsCallback, this );
    img_calibration_sub = nh.subscribe(calibration_img_topic, 1, &pmdGUImodel::imageCalibrationCallback, this );

    settings_pub = nh.advertise<pmdCam::pmd_settings>(settings_topic, 1);
    data_flow_pub = nh.advertise<pmdCam::data_flow>(data_flow_topic, 1);

    ROS_INFO("pmdGUImodel constructor");
}

void pmdGUImodel::imageSettingsCallback(pmdCam::image_box msg)
{
    cv_bridge::CvImagePtr cv_ptr[3];

    cv_ptr[0] = cv_bridge::toCvCopy(msg.img1, sensor_msgs::image_encodings::BGR8);
    cv_ptr[1] = cv_bridge::toCvCopy(msg.img2, sensor_msgs::image_encodings::MONO8);
    cv_ptr[2] = cv_bridge::toCvCopy(msg.img3, sensor_msgs::image_encodings::MONO8);

    cv::Mat image[3];

    cvtColor(cv_ptr[0]->image, image[0], CV_BGR2RGB);
    cvtColor(cv_ptr[1]->image, image[1], CV_GRAY2RGB);
    cvtColor(cv_ptr[2]->image, image[2], CV_GRAY2RGB);

    QImage qimage[3];
    for(int i=0; i<3; i++)
        qimage[i] = QImage(image[i].data, image[i].size().width, image[i].size().height, image[i].step,
                           QImage::Format_RGB888);

    QVector<QImage> qimageVec;
    for(int i=0; i<3; i++)
        qimageVec.push_back(qimage[i]);

    newSettingsImages(qimageVec);
}

void pmdGUImodel::imageCalibrationCallback(pmdCam::image_box msg)
{
    cv_bridge::CvImagePtr cv_ptr[4];

    cv_ptr[0] = cv_bridge::toCvCopy(msg.img1, sensor_msgs::image_encodings::MONO8);
    cv_ptr[1] = cv_bridge::toCvCopy(msg.img2, sensor_msgs::image_encodings::MONO8);
    cv_ptr[2] = cv_bridge::toCvCopy(msg.img3, sensor_msgs::image_encodings::MONO8);
    cv_ptr[3] = cv_bridge::toCvCopy(msg.img4, sensor_msgs::image_encodings::MONO8);

    cv::Mat image[4];

    for(int i=0; i<4; i++) cvtColor(cv_ptr[i]->image, image[i], CV_GRAY2RGB);

    QImage qimage[4];
    for(int i=0; i<4; i++)
        qimage[i] = QImage(image[i].data, image[i].size().width, image[i].size().height, image[i].step,
                           QImage::Format_RGB888);

    QVector<QImage> qimageVec;
    for(int i=0; i<4; i++)
        qimageVec.push_back(qimage[i]);

    newCalibrationImages(qimageVec);
}

void pmdGUImodel::setSettings(pmdCam::pmd_settings settings)
{
    settings_pub.publish(settings);
}

void pmdGUImodel::acceptCalibrationImage()
{
    pmdCam::data_flow msg;
    msg.calibration_in_progress = true;
    msg.accept_last_pair = true;
    msg.perform_calibration = false;
    data_flow_pub.publish(msg);
}

void pmdGUImodel::calibrateCameras()
{
    pmdCam::data_flow msg;
    msg.calibration_in_progress = false;
    msg.accept_last_pair = false;
    msg.perform_calibration = true;
    data_flow_pub.publish(msg);
}

void pmdGUImodel::calibrationInProgress(bool var)
{
    pmdCam::data_flow msg;
    msg.calibration_in_progress = var;
    msg.accept_last_pair = false;
    msg.perform_calibration = false;
    data_flow_pub.publish(msg);
}
