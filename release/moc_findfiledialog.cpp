/****************************************************************************
** Meta object code from reading C++ file 'findfiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/findfiledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findfiledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FindFileDialog_t {
    QByteArrayData data[9];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FindFileDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FindFileDialog_t qt_meta_stringdata_FindFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 6),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 4),
QT_MOC_LITERAL(4, 28, 8),
QT_MOC_LITERAL(5, 37, 16),
QT_MOC_LITERAL(6, 54, 4),
QT_MOC_LITERAL(7, 59, 6),
QT_MOC_LITERAL(8, 66, 15)
    },
    "FindFileDialog\0browse\0\0help\0openFile\0"
    "QTreeWidgetItem*\0item\0update\0"
    "dialog_rejected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FindFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    1,   46,    2, 0x08,
       4,    0,   49,    2, 0x28,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FindFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FindFileDialog *_t = static_cast<FindFileDialog *>(_o);
        switch (_id) {
        case 0: _t->browse(); break;
        case 1: _t->help(); break;
        case 2: _t->openFile((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->openFile(); break;
        case 4: _t->update(); break;
        case 5: _t->dialog_rejected(); break;
        default: ;
        }
    }
}

const QMetaObject FindFileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindFileDialog.data,
      qt_meta_data_FindFileDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *FindFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FindFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindFileDialog.stringdata))
        return static_cast<void*>(const_cast< FindFileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
