/****************************************************************************
** Meta object code from reading C++ file 'pmdGUImodel.h'
**
** Created: Tue Sep 20 15:42:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pmdGUImodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pmdGUImodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pmdGUImodel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      42,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,
     133,   12,   12,   12, 0x0a,
     156,  152,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pmdGUImodel[] = {
    "pmdGUImodel\0\0newSettingsImages(QImageVec)\0"
    "newCalibrationImages(QImageVec)\0"
    "setSettings(pmdCam::pmd_settings)\0"
    "acceptCalibrationImage()\0calibrateCameras()\0"
    "var\0calibrationInProgress(bool)\0"
};

const QMetaObject pmdGUImodel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pmdGUImodel,
      qt_meta_data_pmdGUImodel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pmdGUImodel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pmdGUImodel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pmdGUImodel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pmdGUImodel))
        return static_cast<void*>(const_cast< pmdGUImodel*>(this));
    return QObject::qt_metacast(_clname);
}

int pmdGUImodel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSettingsImages((*reinterpret_cast< QImageVec(*)>(_a[1]))); break;
        case 1: newCalibrationImages((*reinterpret_cast< QImageVec(*)>(_a[1]))); break;
        case 2: setSettings((*reinterpret_cast< pmdCam::pmd_settings(*)>(_a[1]))); break;
        case 3: acceptCalibrationImage(); break;
        case 4: calibrateCameras(); break;
        case 5: calibrationInProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void pmdGUImodel::newSettingsImages(QImageVec _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pmdGUImodel::newCalibrationImages(QImageVec _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
