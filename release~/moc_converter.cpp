/****************************************************************************
** Meta object code from reading C++ file 'converter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../converter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'converter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_converter_t {
    QByteArrayData data[10];
    char stringdata[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_converter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_converter_t qt_meta_stringdata_converter = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 22),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 22),
QT_MOC_LITERAL(4, 57, 18),
QT_MOC_LITERAL(5, 76, 17),
QT_MOC_LITERAL(6, 94, 18),
QT_MOC_LITERAL(7, 113, 23),
QT_MOC_LITERAL(8, 137, 22),
QT_MOC_LITERAL(9, 160, 26)
    },
    "converter\0on_BT_Choose_1_clicked\0\0"
    "on_BT_Choose_2_clicked\0on_BT_Quit_clicked\0"
    "on_BT_App_clicked\0on_BT_Exec_clicked\0"
    "on_actionQuit_triggered\0on_actionApp_triggered\0"
    "on_actionExecute_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_converter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    0,   60,    2, 0x08,
       9,    0,   61,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void converter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        converter *_t = static_cast<converter *>(_o);
        switch (_id) {
        case 0: _t->on_BT_Choose_1_clicked(); break;
        case 1: _t->on_BT_Choose_2_clicked(); break;
        case 2: _t->on_BT_Quit_clicked(); break;
        case 3: _t->on_BT_App_clicked(); break;
        case 4: _t->on_BT_Exec_clicked(); break;
        case 5: _t->on_actionQuit_triggered(); break;
        case 6: _t->on_actionApp_triggered(); break;
        case 7: _t->on_actionExecute_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject converter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_converter.data,
      qt_meta_data_converter,  qt_static_metacall, 0, 0}
};


const QMetaObject *converter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *converter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_converter.stringdata))
        return static_cast<void*>(const_cast< converter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int converter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
