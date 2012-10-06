#ifndef PMDCAMGUIVIEW_HPP
#define	PMDCAMGUIVIEW_HPP

#include <QMainWindow>
#include <QImage>
#include <QVector>
#include "ui_window.h"
#include "pmdCam/pmd_settings.h"
#include "pmdGUImodel.h"

#include <cstdlib>
using namespace std;

/**
  * @class Ui_Form
  * @brief Class generated by QtDesigner - GUI form.
  */

/**
  * @class Ui::Form
  * @brief Inter class generated by QtDesigner from Qt form.
  */
namespace Ui {
    class Form;
}

/**
  * @typedef QImageVec
  */
typedef QVector<QImage> QImageVec;

/**
  * @brief Qt-based qraphical user interface.
  */
class pmdGUIview : public QMainWindow, private Ui::Form
{
    Q_OBJECT
signals:
    /**
     * Signal with new IFM camera settings
     * @param settings message object
     */
    void newSettings(pmdCam::pmd_settings);

    /**
     * Signal of acceptance of calibration images pair
     */
    void acceptImage();

    /**
     * Signal to procced calibration images
     */
    void calibrateCameras();

    /**
     * Signal to controll calibration process
     */
    void calibrationInProgress(bool);

public:
    /**
     * Constructor
     */
    pmdGUIview();
    ~pmdGUIview();
private:
    /**
     * Reset IFM camera settings to default
     */
    void defaultSettings();

private slots:
    /**
     * Slot getting images to set in settings part
     * @param vector of images to set
     */
    void setSettingsImages(QImageVec image);

    /**
     * Slot getting images to set in calibration part
     * @param vector of images to set
     */
    void setCalibrationImages(QImageVec image);

    /**
     * Slot getting signal to reset settings to default.
     */
    void resetSettings();

    /**
     * Slot getting signal of acceptance of calibration image pair.
     */
    void acceptImageSlot();

    /**
     * Slot getting signal to calibrate cameras.
     */
    void calibrateCamerasSlot();

    void settingsMenuSlot();
    void calibrationMenuSlot();
    void settingsMenuExit();
    void calibrationMenuExit();

    // settings menu items slots
    void dataPortSlot(int);
    void ipSlot();
    void xmlPortSlot(int);
    void triggerModeSlot(int);
    void medianFilterSlot(int);
    void meanFilterSlot(int);
    void modulationFrequencySlot(int);
    void samplingModeSlot(int);
    void singleIntegrationTimeSlot(int);
    void doubleIntegrationTimeSlot(int);

private:
    pmdCam::pmd_settings settings;

};

#endif	/* PMDCAMGUIVIEW_HPP */

