/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Qt/mainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "captureTimerUpdated"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "connectToNewBridge"
QT_MOC_LITERAL(4, 51, 18), // "connectToNewCamera"
QT_MOC_LITERAL(5, 70, 15), // "connectToBridge"
QT_MOC_LITERAL(6, 86, 15), // "connectToCamera"
QT_MOC_LITERAL(7, 102, 20), // "disconnectFromBridge"
QT_MOC_LITERAL(8, 123, 20), // "disconnectFromCamera"
QT_MOC_LITERAL(9, 144, 27), // "changeImageUpdatePreference"
QT_MOC_LITERAL(10, 172, 9), // "canUpdate"
QT_MOC_LITERAL(11, 182, 20), // "rotateImageClockwise"
QT_MOC_LITERAL(12, 203, 24), // "rotateImageAntiClockwise"
QT_MOC_LITERAL(13, 228, 19), // "flipImageHorizontal"
QT_MOC_LITERAL(14, 248, 4), // "flip"
QT_MOC_LITERAL(15, 253, 17), // "flipImageVertical"
QT_MOC_LITERAL(16, 271, 11) // "showOptions"

    },
    "MainWindow\0captureTimerUpdated\0\0"
    "connectToNewBridge\0connectToNewCamera\0"
    "connectToBridge\0connectToCamera\0"
    "disconnectFromBridge\0disconnectFromCamera\0"
    "changeImageUpdatePreference\0canUpdate\0"
    "rotateImageClockwise\0rotateImageAntiClockwise\0"
    "flipImageHorizontal\0flip\0flipImageVertical\0"
    "showOptions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x09 /* Protected */,
       3,    0,   80,    2, 0x09 /* Protected */,
       4,    0,   81,    2, 0x09 /* Protected */,
       5,    0,   82,    2, 0x09 /* Protected */,
       6,    0,   83,    2, 0x09 /* Protected */,
       7,    0,   84,    2, 0x09 /* Protected */,
       8,    0,   85,    2, 0x09 /* Protected */,
       9,    1,   86,    2, 0x09 /* Protected */,
      11,    0,   89,    2, 0x09 /* Protected */,
      12,    0,   90,    2, 0x09 /* Protected */,
      13,    1,   91,    2, 0x09 /* Protected */,
      15,    1,   94,    2, 0x09 /* Protected */,
      16,    0,   97,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->captureTimerUpdated(); break;
        case 1: _t->connectToNewBridge(); break;
        case 2: _t->connectToNewCamera(); break;
        case 3: _t->connectToBridge(); break;
        case 4: _t->connectToCamera(); break;
        case 5: _t->disconnectFromBridge(); break;
        case 6: _t->disconnectFromCamera(); break;
        case 7: _t->changeImageUpdatePreference((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->rotateImageClockwise(); break;
        case 9: _t->rotateImageAntiClockwise(); break;
        case 10: _t->flipImageHorizontal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->flipImageVertical((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->showOptions(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "AbstractBridgeConnectionNotifier"))
        return static_cast< AbstractBridgeConnectionNotifier*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
