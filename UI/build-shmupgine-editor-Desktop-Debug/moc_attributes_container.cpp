/****************************************************************************
** Meta object code from reading C++ file 'attributes_container.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/attributes_container.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attributes_container.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_attributes_container[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   22,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_attributes_container[] = {
    "attributes_container\0\0attr\0"
    "add_attribute(attribute_widget*)\0"
};

void attributes_container::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        attributes_container *_t = static_cast<attributes_container *>(_o);
        switch (_id) {
        case 0: _t->add_attribute((*reinterpret_cast< attribute_widget*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData attributes_container::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject attributes_container::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_attributes_container,
      qt_meta_data_attributes_container, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &attributes_container::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *attributes_container::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *attributes_container::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_attributes_container))
        return static_cast<void*>(const_cast< attributes_container*>(this));
    return QWidget::qt_metacast(_clname);
}

int attributes_container::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
