/**
 * Connect GUI with model and ROS
 */
#include "pmdCam.h"

#include <ros/ros.h>
#include "std_msgs/String.h"
#include "pmdCam/pmd_settings.h"

#include "qtros.h"
#include <QApplication>
#include <QObject>
#include <QMetaType>

#include "pmdGUIview.hpp"
#include "pmdGUImodel.h"

int main(int argc, char** argv)
{
    qRegisterMetaType<QImageVec>("QImageVec");

    QApplication application(argc,argv);
    QtROS qtRos(argc, argv,"pmd_settings"); //Thread object, to run the ros event processing loop in parallel to the qt loop
    //If one thread receives a exit signal from the user, signal the other thread to quit too
    QObject::connect(&application, SIGNAL(aboutToQuit()), &qtRos, SLOT(quitNow()));
    QObject::connect(&qtRos, SIGNAL(rosQuits()), &application, SLOT(quit()));

    pmdGUIview window;
    window.show();

    pmdGUImodel pmd_model(qtRos.getNodeHandle(),
                          "system3d_images",
                          "pmdcam_settings",
                          "system3d_calibration_images",
                          "system3d_data_flow");

    QObject::connect(&pmd_model, SIGNAL(newSettingsImages(QImageVec)),
                     &window, SLOT(setSettingsImages(QImageVec)),
                     Qt::BlockingQueuedConnection);

    QObject::connect(&pmd_model, SIGNAL(newCalibrationImages(QImageVec)),
                     &window, SLOT(setCalibrationImages(QImageVec)),
                     Qt::BlockingQueuedConnection);

    QObject::connect(&window, SIGNAL(acceptImage()), &pmd_model, SLOT(acceptCalibrationImage()));
    QObject::connect(&window, SIGNAL(calibrateCameras()), &pmd_model, SLOT(calibrateCameras()));
    QObject::connect(&window, SIGNAL(calibrationInProgress(bool)), &pmd_model, SLOT(calibrationInProgress(bool)));
    QObject::connect(&window, SIGNAL(newSettings(pmdCam::pmd_settings)), &pmd_model, SLOT(setSettings(pmdCam::pmd_settings)));

    // Run main loop.
    qtRos.start();
    application.exec();
    //exit(0); // hack to mask something is wrong if return is called on application.exec(). Couldn't find out what's wrong. This was only b/c of qglviewer I think
}
