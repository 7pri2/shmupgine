/****************************************************************************
** Meta object code from reading C++ file 'attributes_container.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shmupgine-editor/attributes_container.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attributes_container.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_attributes_container_t {
    QByteArrayData data[7];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_attributes_container_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_attributes_container_t qt_meta_stringdata_attributes_container = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 16),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 17),
QT_MOC_LITERAL(4, 57, 4),
QT_MOC_LITERAL(5, 62, 2),
QT_MOC_LITERAL(6, 65, 22)
    },
    "attributes_container\0create_attribute\0"
    "\0attribute_widget*\0attr\0id\0"
    "update_what_is_visible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_attributes_container[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       1,    2,   32,    2, 0x0a /* Public */,
       6,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    5,    4,
    QMetaType::Void,

       0        // eod
};

void attributes_container::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        attributes_container *_t = static_cast<attributes_container *>(_o);
        switch (_id) {
        case 0: _t->create_attribute((*reinterpret_cast< attribute_widget*(*)>(_a[1]))); break;
        case 1: _t->create_attribute((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< attribute_widget*(*)>(_a[2]))); break;
        case 2: _t->update_what_is_visible(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< attribute_widget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< attribute_widget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject attributes_container::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_attributes_container.data,
      qt_meta_data_attributes_container,  qt_static_metacall, 0, 0}
};


const QMetaObject *attributes_container::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *attributes_container::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_attributes_container.stringdata))
        return static_cast<void*>(const_cast< attributes_container*>(this));
    return QWidget::qt_metacast(_clname);
}

int attributes_container::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
