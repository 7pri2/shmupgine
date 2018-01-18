/****************************************************************************
** Meta object code from reading C++ file 'config_panel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/config_panel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_config_panel_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_config_panel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_config_panel_t qt_meta_stringdata_config_panel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "config_panel"
QT_MOC_LITERAL(1, 13, 11), // "fill_fields"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "update_name"
QT_MOC_LITERAL(4, 38, 6), // "n_name"
QT_MOC_LITERAL(5, 45, 18), // "update_working_dir"
QT_MOC_LITERAL(6, 64, 13), // "n_working_dir"
QT_MOC_LITERAL(7, 78, 15), // "update_compiler"
QT_MOC_LITERAL(8, 94, 10), // "n_compiler"
QT_MOC_LITERAL(9, 105, 21), // "update_compiler_flags"
QT_MOC_LITERAL(10, 127, 16), // "n_compiler_flags"
QT_MOC_LITERAL(11, 144, 11), // "update_make"
QT_MOC_LITERAL(12, 156, 6), // "n_make"
QT_MOC_LITERAL(13, 163, 13), // "update_engine"
QT_MOC_LITERAL(14, 177, 8) // "n_engine"

    },
    "config_panel\0fill_fields\0\0update_name\0"
    "n_name\0update_working_dir\0n_working_dir\0"
    "update_compiler\0n_compiler\0"
    "update_compiler_flags\0n_compiler_flags\0"
    "update_make\0n_make\0update_engine\0"
    "n_engine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_config_panel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      13,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void config_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        config_panel *_t = static_cast<config_panel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fill_fields(); break;
        case 1: _t->update_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->update_working_dir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->update_compiler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->update_compiler_flags((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->update_make((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->update_engine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject config_panel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_config_panel.data,
      qt_meta_data_config_panel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *config_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *config_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_config_panel.stringdata0))
        return static_cast<void*>(const_cast< config_panel*>(this));
    return QWidget::qt_metacast(_clname);
}

int config_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
