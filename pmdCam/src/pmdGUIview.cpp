#include "pmdGUIview.hpp"

pmdGUIview::pmdGUIview()
    : QMainWindow(0, Qt::Window)
{
    setupUi(this);

    tab1->setEnabled(false);
    tab2->setEnabled(false);

    int scale = 3;
    QPixmap blank = QPixmap(scale*IMG_HEIGHT, scale*IMG_WIDTH);
    //QPixmap blank = QPixmap(200,256);
    //blank.fill(QColor(0,0,0));
    blank.fill(QColor(255,255,255));
    img1->setPixmap(blank);
    img2->setPixmap(blank);
    img3->setPixmap(blank);

    image_web->setPixmap(blank);
    image_pmd->setPixmap(blank);

    img_calib1->setPixmap(blank);
    img_calib2->setPixmap(blank);
    img_calib3->setPixmap(blank);
    img_calib4->setPixmap(blank);

    // set settings menu items properities
    data_port_box->setRange(1,65535);
    ip_box->setMaxLength(15);
    xml_port_box->setRange(1,65535);
    trigger_mode_box->setRange(1,4);

    frequency_box->addItem("0 (23MHz)");
    frequency_box->addItem("1 (20.4MHz)");
    frequency_box->addItem("2 (20.6MHz)");

    sampling_mode_box->addItem("0 (single)");
    sampling_mode_box->addItem("1 (double)");

    single_integration_time_box->setRange(1,5000);
    double_integration_time_box->setRange(1,5000);

    resetSettings();

    // connect GUI signals & slots

    // menu
    connect(settingsMenuButton, SIGNAL(clicked()), this, SLOT(settingsMenuSlot()));
    connect(calibrationMenuButton, SIGNAL(clicked()), this, SLOT(calibrationMenuSlot()));
    connect(exitButton3, SIGNAL(clicked()), qApp, SLOT(quit()));

    // settings menu
    connect(defaultSettingsButton, SIGNAL(clicked()), this, SLOT(resetSettings()));

    connect(data_port_box, SIGNAL(valueChanged(int)), this, SLOT(dataPortSlot(int)));
    connect(ip_box, SIGNAL(editingFinished()), this, SLOT(ipSlot()));
    connect(xml_port_box, SIGNAL(valueChanged(int)), this, SLOT(xmlPortSlot(int)));
    connect(trigger_mode_box, SIGNAL(valueChanged(int)), this, SLOT(triggerModeSlot(int)));
    connect(median_filter_box, SIGNAL(stateChanged(int)), this, SLOT(medianFilterSlot(int)));
    connect(mean_filter_box, SIGNAL(stateChanged(int)), this, SLOT(meanFilterSlot(int)));

    connect(frequency_box, SIGNAL(currentIndexChanged(int)), this, SLOT(modulationFrequencySlot(int)));
    connect(sampling_mode_box, SIGNAL(currentIndexChanged(int)), this, SLOT(samplingModeSlot(int)));

    connect(single_integration_time_box, SIGNAL(valueChanged(int)), this, SLOT(singleIntegrationTimeSlot(int)));
    connect(double_integration_time_box, SIGNAL(valueChanged(int)), this, SLOT(doubleIntegrationTimeSlot(int)));

    connect(exitButton1, SIGNAL(clicked()), this, SLOT(settingsMenuExit()));

    // calibration menu
    connect(acceptButton, SIGNAL(clicked()), this, SLOT(acceptImageSlot()));
    connect(calibrateButton, SIGNAL(clicked()), this, SLOT(calibrateCamerasSlot()));
    connect(exitButton2, SIGNAL(clicked()), this, SLOT(calibrationMenuExit()));
}

pmdGUIview::~pmdGUIview()
{

}

void pmdGUIview::settingsMenuSlot()
{
    tab1->setEnabled(true);
    tabWidget->setCurrentIndex(tabWidget->indexOf(tab1));
    menuTab->setEnabled(false);
}

void pmdGUIview::calibrationMenuSlot()
{
    menuTab->setEnabled(false);
    tab1->setEnabled(false);
    settingsMenuButton->setEnabled(false);
    tab2->setEnabled(true);
    tabWidget->setCurrentIndex(tabWidget->indexOf(tab2));
    calibrationInProgress(true);
}

void pmdGUIview::settingsMenuExit()
{
    menuTab->setEnabled(true);
    tab1->setEnabled(false);
    settingsMenuButton->setEnabled(false);
    tabWidget->setCurrentIndex(tabWidget->indexOf(menuTab));
}

void pmdGUIview::calibrationMenuExit()
{
    if(calibrateButton->isEnabled()) calibrationInProgress(false);
    menuTab->setEnabled(true);
    tab2->setEnabled(false);
    calibrationMenuButton->setEnabled(false);
    tabWidget->setCurrentIndex(tabWidget->indexOf(menuTab));
}


void pmdGUIview::acceptImageSlot()
{
    calibImageCounter->setValue(calibImageCounter->value()+1);
    acceptImage();
}

void pmdGUIview::calibrateCamerasSlot()
{
    calibrateButton->setEnabled(false);
    acceptButton->setEnabled(false);
    calibrateCameras();
}

void pmdGUIview::setSettingsImages(QImageVec qimageVec)
{
    if(qimageVec.size()==3)
    {
        QVector<QPixmap> pixImage(3);
        for(int i=0; i<pixImage.size(); i++)
        {
            pixImage[i].convertFromImage(qimageVec[i]);
        }

        img1->setPixmap(pixImage[0]);
        img2->setPixmap(pixImage[1]);
        img3->setPixmap(pixImage[2]);

        image_pmd->setPixmap(pixImage[0]);
        image_web->setPixmap(pixImage[1]);
    }
}

void pmdGUIview::setCalibrationImages(QImageVec qimageVec)
{
    if(qimageVec.size()==4)
    {
        QVector<QPixmap> pixImage(4);
        for(int i=0; i<pixImage.size(); i++)
        {
            pixImage[i].convertFromImage(qimageVec[i]);
        }

        img_calib1->setPixmap(pixImage[0]);
        img_calib2->setPixmap(pixImage[1]);
        img_calib3->setPixmap(pixImage[2]);
        img_calib4->setPixmap(pixImage[3]);
    }
}

void pmdGUIview::resetSettings()
{
    defaultSettings();
}

void pmdGUIview::defaultSettings()
{
    settings.data_port    = 50002; // 1 to 65535
    settings.ip    = "192.168.0.63"; // default address
    settings.xml_port = 8080; // default port
    settings.trigger_mode    = 3; //SW
    settings.median_filter = 0;
    settings.mean_filter = 0;
    settings.modulation_frequency  = 0; // Modulation Frequency 0 (23MHz) 1 (20.4MHz) 2 (20.6MHz)
    settings.illu_mode = 0; // don't change
    settings.reset_duration = 20; // don't change
    settings.sampling_mode = 0; // 0 - single, 1 - double
    settings.integration_time_single = 125; // 1-5000 (short)
    settings.integration_time_double = 2000; // 1-5000 (long)
    settings.ifm_time      = 100;
    settings.delay_time = 100;
    settings.unambiguous_range = 0.0;

    data_port_box->setValue(settings.data_port);
    ip_box->setText(QString::fromStdString(settings.ip)); // sprawdzić wyrażenia regularne
    xml_port_box->setValue(settings.xml_port);
    trigger_mode_box->setValue(settings.trigger_mode);
    frequency_box->setCurrentIndex(settings.modulation_frequency);
    sampling_mode_box->setCurrentIndex(settings.sampling_mode);
    mean_filter_box->setChecked(bool(settings.mean_filter));
    median_filter_box->setChecked(bool(settings.median_filter));
    sampling_mode_box->setCurrentIndex(settings.sampling_mode);
    single_integration_time_box->setValue(settings.integration_time_single);
    double_integration_time_box->setValue(settings.integration_time_double);

    double_integration_time_box->setEnabled(bool(settings.sampling_mode));

    newSettings(settings);
}

void pmdGUIview::dataPortSlot(int val)
{
    settings.data_port = val;
    newSettings(settings);
}

void pmdGUIview::ipSlot()
{
    // TODO: check string
    QString text = ip_box->text();
    settings.ip = text.toStdString();
    newSettings(settings);
}

void pmdGUIview::xmlPortSlot(int val)
{
    settings.xml_port = val;
    newSettings(settings);
}

void pmdGUIview::triggerModeSlot(int val)
{
    settings.trigger_mode = val;
    newSettings(settings);
}

void pmdGUIview::medianFilterSlot(int val)
{
    settings.median_filter = bool(val);
    newSettings(settings);
}

void pmdGUIview::meanFilterSlot(int val)
{
    settings.mean_filter = bool(val);
    newSettings(settings);
}

void pmdGUIview::modulationFrequencySlot(int val)
{
    settings.modulation_frequency = val;
    newSettings(settings);
}

void pmdGUIview::samplingModeSlot(int val)
{
    settings.sampling_mode = val;
    double_integration_time_box->setEnabled(bool(val));
    newSettings(settings);
}

void pmdGUIview::singleIntegrationTimeSlot(int time)
{
    settings.integration_time_single = time;
    if(time >= double_integration_time_box->value())
    {
        settings.integration_time_double = time+1;
        double_integration_time_box->setValue(time+1);
    }
    newSettings(settings);
}

void pmdGUIview::doubleIntegrationTimeSlot(int time)
{
    settings.integration_time_double = time;
    if(time <= single_integration_time_box->value())
    {
        settings.integration_time_single = time-1;
        single_integration_time_box->setValue(time-1);
    }
    newSettings(settings);
}

