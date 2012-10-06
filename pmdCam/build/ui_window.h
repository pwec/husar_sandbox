/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Mon Aug 13 17:20:44 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTabWidget *tabWidget;
    QWidget *menuTab;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *settingsMenuButton;
    QPushButton *calibrationMenuButton;
    QPushButton *exitButton3;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *image_pmd;
    QLabel *image_web;
    QWidget *tab1;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QPushButton *defaultSettingsButton;
    QLabel *label_9;
    QSpinBox *data_port_box;
    QLabel *label_10;
    QLineEdit *ip_box;
    QLabel *label_11;
    QSpinBox *xml_port_box;
    QLabel *label_12;
    QSpinBox *trigger_mode_box;
    QLabel *label_16;
    QCheckBox *median_filter_box;
    QLabel *label_29;
    QCheckBox *mean_filter_box;
    QLabel *label_14;
    QComboBox *frequency_box;
    QLabel *label_13;
    QComboBox *sampling_mode_box;
    QLabel *label_15;
    QSlider *single_integration_time_box;
    QLabel *label_30;
    QSlider *double_integration_time_box;
    QPushButton *exitButton1;
    QSpacerItem *verticalSpacer_3;
    QWidget *left_box;
    QVBoxLayout *verticalLayout;
    QLabel *img1;
    QLabel *img2;
    QLabel *img3;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *img_calib1;
    QLabel *img_calib2;
    QLabel *img_calib4;
    QLabel *img_calib3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QPushButton *calibrateButton;
    QPushButton *exitButton2;
    QFrame *line;
    QPushButton *acceptButton;
    QLabel *label;
    QSpinBox *calibImageCounter;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(786, 662);
        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 696, 635));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        menuTab = new QWidget();
        menuTab->setObjectName(QString::fromUtf8("menuTab"));
        horizontalLayout = new QHBoxLayout(menuTab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_3 = new QWidget(menuTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        settingsMenuButton = new QPushButton(widget_3);
        settingsMenuButton->setObjectName(QString::fromUtf8("settingsMenuButton"));

        verticalLayout_3->addWidget(settingsMenuButton);

        calibrationMenuButton = new QPushButton(widget_3);
        calibrationMenuButton->setObjectName(QString::fromUtf8("calibrationMenuButton"));

        verticalLayout_3->addWidget(calibrationMenuButton);

        exitButton3 = new QPushButton(widget_3);
        exitButton3->setObjectName(QString::fromUtf8("exitButton3"));

        verticalLayout_3->addWidget(exitButton3);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        image_pmd = new QLabel(widget_4);
        image_pmd->setObjectName(QString::fromUtf8("image_pmd"));
        image_pmd->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image_pmd->sizePolicy().hasHeightForWidth());
        image_pmd->setSizePolicy(sizePolicy1);
        image_pmd->setMinimumSize(QSize(256, 200));
        image_pmd->setBaseSize(QSize(248, 200));
        image_pmd->setAutoFillBackground(true);
        image_pmd->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(image_pmd, 0, 0, 1, 1);

        image_web = new QLabel(widget_4);
        image_web->setObjectName(QString::fromUtf8("image_web"));
        image_web->setEnabled(true);
        sizePolicy1.setHeightForWidth(image_web->sizePolicy().hasHeightForWidth());
        image_web->setSizePolicy(sizePolicy1);
        image_web->setMinimumSize(QSize(256, 200));
        image_web->setBaseSize(QSize(248, 200));
        image_web->setAutoFillBackground(true);
        image_web->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(image_web, 0, 1, 1, 1);


        verticalLayout_3->addWidget(widget_4);


        horizontalLayout->addWidget(widget_3);

        tabWidget->addTab(menuTab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout = new QGridLayout(tab1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        scrollArea_2 = new QScrollArea(tab1);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 343, 438));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        defaultSettingsButton = new QPushButton(scrollAreaWidgetContents_2);
        defaultSettingsButton->setObjectName(QString::fromUtf8("defaultSettingsButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, defaultSettingsButton);

        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        data_port_box = new QSpinBox(scrollAreaWidgetContents_2);
        data_port_box->setObjectName(QString::fromUtf8("data_port_box"));
        data_port_box->setMinimum(1);
        data_port_box->setMaximum(100);
        data_port_box->setValue(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, data_port_box);

        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAutoFillBackground(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        ip_box = new QLineEdit(scrollAreaWidgetContents_2);
        ip_box->setObjectName(QString::fromUtf8("ip_box"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ip_box);

        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_11);

        xml_port_box = new QSpinBox(scrollAreaWidgetContents_2);
        xml_port_box->setObjectName(QString::fromUtf8("xml_port_box"));

        formLayout->setWidget(3, QFormLayout::FieldRole, xml_port_box);

        label_12 = new QLabel(scrollAreaWidgetContents_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_12);

        trigger_mode_box = new QSpinBox(scrollAreaWidgetContents_2);
        trigger_mode_box->setObjectName(QString::fromUtf8("trigger_mode_box"));

        formLayout->setWidget(5, QFormLayout::FieldRole, trigger_mode_box);

        label_16 = new QLabel(scrollAreaWidgetContents_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_16);

        median_filter_box = new QCheckBox(scrollAreaWidgetContents_2);
        median_filter_box->setObjectName(QString::fromUtf8("median_filter_box"));

        formLayout->setWidget(8, QFormLayout::FieldRole, median_filter_box);

        label_29 = new QLabel(scrollAreaWidgetContents_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_29);

        mean_filter_box = new QCheckBox(scrollAreaWidgetContents_2);
        mean_filter_box->setObjectName(QString::fromUtf8("mean_filter_box"));

        formLayout->setWidget(10, QFormLayout::FieldRole, mean_filter_box);

        label_14 = new QLabel(scrollAreaWidgetContents_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_14);

        frequency_box = new QComboBox(scrollAreaWidgetContents_2);
        frequency_box->setObjectName(QString::fromUtf8("frequency_box"));

        formLayout->setWidget(11, QFormLayout::FieldRole, frequency_box);

        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_13);

        sampling_mode_box = new QComboBox(scrollAreaWidgetContents_2);
        sampling_mode_box->setObjectName(QString::fromUtf8("sampling_mode_box"));

        formLayout->setWidget(12, QFormLayout::FieldRole, sampling_mode_box);

        label_15 = new QLabel(scrollAreaWidgetContents_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_15);

        single_integration_time_box = new QSlider(scrollAreaWidgetContents_2);
        single_integration_time_box->setObjectName(QString::fromUtf8("single_integration_time_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(single_integration_time_box->sizePolicy().hasHeightForWidth());
        single_integration_time_box->setSizePolicy(sizePolicy2);
        single_integration_time_box->setMinimum(1);
        single_integration_time_box->setMaximum(5000);
        single_integration_time_box->setValue(125);
        single_integration_time_box->setOrientation(Qt::Horizontal);

        formLayout->setWidget(13, QFormLayout::FieldRole, single_integration_time_box);

        label_30 = new QLabel(scrollAreaWidgetContents_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label_30);

        double_integration_time_box = new QSlider(scrollAreaWidgetContents_2);
        double_integration_time_box->setObjectName(QString::fromUtf8("double_integration_time_box"));
        sizePolicy2.setHeightForWidth(double_integration_time_box->sizePolicy().hasHeightForWidth());
        double_integration_time_box->setSizePolicy(sizePolicy2);
        double_integration_time_box->setMinimum(1);
        double_integration_time_box->setMaximum(5000);
        double_integration_time_box->setValue(125);
        double_integration_time_box->setOrientation(Qt::Horizontal);

        formLayout->setWidget(15, QFormLayout::FieldRole, double_integration_time_box);

        exitButton1 = new QPushButton(scrollAreaWidgetContents_2);
        exitButton1->setObjectName(QString::fromUtf8("exitButton1"));

        formLayout->setWidget(17, QFormLayout::FieldRole, exitButton1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(16, QFormLayout::FieldRole, verticalSpacer_3);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea_2, 1, 0, 2, 1);

        left_box = new QWidget(tab1);
        left_box->setObjectName(QString::fromUtf8("left_box"));
        sizePolicy2.setHeightForWidth(left_box->sizePolicy().hasHeightForWidth());
        left_box->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(left_box);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        img1 = new QLabel(left_box);
        img1->setObjectName(QString::fromUtf8("img1"));
        img1->setAutoFillBackground(true);
        img1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(img1);

        img2 = new QLabel(left_box);
        img2->setObjectName(QString::fromUtf8("img2"));
        img2->setAutoFillBackground(true);
        img2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(img2);

        img3 = new QLabel(left_box);
        img3->setObjectName(QString::fromUtf8("img3"));
        img3->setAutoFillBackground(true);
        img3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(img3);

        img2->raise();
        img3->raise();
        img1->raise();

        gridLayout->addWidget(left_box, 1, 1, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        verticalLayout_2 = new QVBoxLayout(tab2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(tab2);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(256, 200));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        img_calib1 = new QLabel(widget);
        img_calib1->setObjectName(QString::fromUtf8("img_calib1"));
        img_calib1->setEnabled(true);
        sizePolicy1.setHeightForWidth(img_calib1->sizePolicy().hasHeightForWidth());
        img_calib1->setSizePolicy(sizePolicy1);
        img_calib1->setMinimumSize(QSize(256, 200));
        img_calib1->setBaseSize(QSize(248, 200));
        img_calib1->setAutoFillBackground(true);
        img_calib1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(img_calib1, 1, 1, 1, 1);

        img_calib2 = new QLabel(widget);
        img_calib2->setObjectName(QString::fromUtf8("img_calib2"));
        img_calib2->setMinimumSize(QSize(256, 200));
        img_calib2->setAutoFillBackground(true);
        img_calib2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(img_calib2, 1, 3, 1, 1);

        img_calib4 = new QLabel(widget);
        img_calib4->setObjectName(QString::fromUtf8("img_calib4"));
        img_calib4->setMinimumSize(QSize(256, 200));
        img_calib4->setAutoFillBackground(true);
        img_calib4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(img_calib4, 3, 3, 1, 1);

        img_calib3 = new QLabel(widget);
        img_calib3->setObjectName(QString::fromUtf8("img_calib3"));
        img_calib3->setMinimumSize(QSize(256, 200));
        img_calib3->setAutoFillBackground(true);
        img_calib3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(img_calib3, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 4, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(tab2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        calibrateButton = new QPushButton(widget_2);
        calibrateButton->setObjectName(QString::fromUtf8("calibrateButton"));

        gridLayout_3->addWidget(calibrateButton, 1, 3, 1, 1);

        exitButton2 = new QPushButton(widget_2);
        exitButton2->setObjectName(QString::fromUtf8("exitButton2"));

        gridLayout_3->addWidget(exitButton2, 4, 3, 1, 1);

        line = new QFrame(widget_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 2, 3, 1, 1);

        acceptButton = new QPushButton(widget_2);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        gridLayout_3->addWidget(acceptButton, 0, 3, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        calibImageCounter = new QSpinBox(widget_2);
        calibImageCounter->setObjectName(QString::fromUtf8("calibImageCounter"));
        calibImageCounter->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(calibImageCounter->sizePolicy().hasHeightForWidth());
        calibImageCounter->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(calibImageCounter, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        tabWidget->addTab(tab2, QString());

        retranslateUi(Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Sterowanie uk\305\202adem kamer", 0, QApplication::UnicodeUTF8));
        settingsMenuButton->setText(QApplication::translate("Form", "ustawienia kamery", 0, QApplication::UnicodeUTF8));
        calibrationMenuButton->setText(QApplication::translate("Form", "kalibracja kamer", 0, QApplication::UnicodeUTF8));
        exitButton3->setText(QApplication::translate("Form", "zako\305\204cz", 0, QApplication::UnicodeUTF8));
        image_pmd->setText(QApplication::translate("Form", "image_pmd", 0, QApplication::UnicodeUTF8));
        image_web->setText(QApplication::translate("Form", "image_web", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(menuTab), QApplication::translate("Form", "Menu", 0, QApplication::UnicodeUTF8));
        defaultSettingsButton->setText(QApplication::translate("Form", "ustawienia domy\305\233lne", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Form", "data port", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form", "ip", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Form", "xml port", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Form", "trigger mode", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Form", "median filter", 0, QApplication::UnicodeUTF8));
        median_filter_box->setText(QApplication::translate("Form", "enable", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Form", "mean filter", 0, QApplication::UnicodeUTF8));
        mean_filter_box->setText(QApplication::translate("Form", "enable", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Form", "modulation frequency", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Form", "sampling mode", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Form", "single integration time", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Form", "double integration time", 0, QApplication::UnicodeUTF8));
        exitButton1->setText(QApplication::translate("Form", "powr\303\263t", 0, QApplication::UnicodeUTF8));
        img1->setText(QApplication::translate("Form", "image1", 0, QApplication::UnicodeUTF8));
        img2->setText(QApplication::translate("Form", "image2", 0, QApplication::UnicodeUTF8));
        img3->setText(QApplication::translate("Form", "image3", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Form", "ustawienia kamery IFM", 0, QApplication::UnicodeUTF8));
        img_calib1->setText(QApplication::translate("Form", "image1", 0, QApplication::UnicodeUTF8));
        img_calib2->setText(QApplication::translate("Form", "image2", 0, QApplication::UnicodeUTF8));
        img_calib4->setText(QApplication::translate("Form", "image4", 0, QApplication::UnicodeUTF8));
        img_calib3->setText(QApplication::translate("Form", "image3", 0, QApplication::UnicodeUTF8));
        calibrateButton->setText(QApplication::translate("Form", "kalibracja kamer", 0, QApplication::UnicodeUTF8));
        exitButton2->setText(QApplication::translate("Form", "powr\303\263t", 0, QApplication::UnicodeUTF8));
        acceptButton->setText(QApplication::translate("Form", "zatwierd\305\272 zdj\304\231cie", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "ilo\305\233\304\207 zatwierdzonych zdj\304\231\304\207", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("Form", "kalibracja kamer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
