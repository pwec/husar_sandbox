/****************************************************************************
** Meta object code from reading C++ file 'pmdGUIview.hpp'
**
** Created: Tue Sep 20 16:03:45 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pmdGUIview.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pmdGUIview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pmdGUIview[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      46,   11,   11,   11, 0x05,
      60,   11,   11,   11, 0x05,
      79,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     113,  107,   11,   11, 0x08,
     142,  107,   11,   11, 0x08,
     174,   11,   11,   11, 0x08,
     190,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     291,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     378,   11,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,
     420,   11,   11,   11, 0x08,
     449,   11,   11,   11, 0x08,
     471,   11,   11,   11, 0x08,
     502,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_pmdGUIview[] = {
    "pmdGUIview\0\0newSettings(pmdCam::pmd_settings)\0"
    "acceptImage()\0calibrateCameras()\0"
    "calibrationInProgress(bool)\0image\0"
    "setSettingsImages(QImageVec)\0"
    "setCalibrationImages(QImageVec)\0"
    "resetSettings()\0acceptImageSlot()\0"
    "calibrateCamerasSlot()\0settingsMenuSlot()\0"
    "calibrationMenuSlot()\0settingsMenuExit()\0"
    "calibrationMenuExit()\0dataPortSlot(int)\0"
    "ipSlot()\0xmlPortSlot(int)\0"
    "triggerModeSlot(int)\0medianFilterSlot(int)\0"
    "meanFilterSlot(int)\0modulationFrequencySlot(int)\0"
    "samplingModeSlot(int)\0"
    "singleIntegrationTimeSlot(int)\0"
    "doubleIntegrationTimeSlot(int)\0"
};

const QMetaObject pmdGUIview::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_pmdGUIview,
      qt_meta_data_pmdGUIview, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pmdGUIview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pmdGUIview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pmdGUIview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pmdGUIview))
        return static_cast<void*>(const_cast< pmdGUIview*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int pmdGUIview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSettings((*reinterpret_cast< pmdCam::pmd_settings(*)>(_a[1]))); break;
        case 1: acceptImage(); break;
        case 2: calibrateCameras(); break;
        case 3: calibrationInProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setSettingsImages((*reinterpret_cast< QImageVec(*)>(_a[1]))); break;
        case 5: setCalibrationImages((*reinterpret_cast< QImageVec(*)>(_a[1]))); break;
        case 6: resetSettings(); break;
        case 7: acceptImageSlot(); break;
        case 8: calibrateCamerasSlot(); break;
        case 9: settingsMenuSlot(); break;
        case 10: calibrationMenuSlot(); break;
        case 11: settingsMenuExit(); break;
        case 12: calibrationMenuExit(); break;
        case 13: dataPortSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: ipSlot(); break;
        case 15: xmlPortSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: triggerModeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: medianFilterSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: meanFilterSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: modulationFrequencySlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: samplingModeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: singleIntegrationTimeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: doubleIntegrationTimeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void pmdGUIview::newSettings(pmdCam::pmd_settings _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pmdGUIview::acceptImage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void pmdGUIview::calibrateCameras()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void pmdGUIview::calibrationInProgress(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
