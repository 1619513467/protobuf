/****************************************************************************
** Meta object code from reading C++ file 'rcfserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../../src/RcfServer/rcfserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rcfserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RcfServer_t {
    QByteArrayData data[13];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RcfServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RcfServer_t qt_meta_stringdata_RcfServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RcfServer"
QT_MOC_LITERAL(1, 10, 7), // "sltStop"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "sltStart"
QT_MOC_LITERAL(4, 28, 10), // "sltSetData"
QT_MOC_LITERAL(5, 39, 10), // "QsFileName"
QT_MOC_LITERAL(6, 50, 10), // "QsFilePath"
QT_MOC_LITERAL(7, 61, 10), // "QsFilesize"
QT_MOC_LITERAL(8, 72, 10), // "QsProgress"
QT_MOC_LITERAL(9, 83, 5), // "QsMD5"
QT_MOC_LITERAL(10, 89, 6), // "QsTime"
QT_MOC_LITERAL(11, 96, 12), // "sltUpdateRow"
QT_MOC_LITERAL(12, 109, 8) // "sltClear"

    },
    "RcfServer\0sltStop\0\0sltStart\0sltSetData\0"
    "QsFileName\0QsFilePath\0QsFilesize\0"
    "QsProgress\0QsMD5\0QsTime\0sltUpdateRow\0"
    "sltClear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RcfServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    6,   41,    2, 0x09 /* Protected */,
      11,    0,   54,    2, 0x09 /* Protected */,
      12,    0,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RcfServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RcfServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sltStop(); break;
        case 1: _t->sltStart(); break;
        case 2: _t->sltSetData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 3: _t->sltUpdateRow(); break;
        case 4: _t->sltClear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RcfServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_RcfServer.data,
    qt_meta_data_RcfServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RcfServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RcfServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RcfServer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RcfServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
