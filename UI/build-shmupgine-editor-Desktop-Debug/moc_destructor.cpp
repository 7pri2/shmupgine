/****************************************************************************
** Meta object code from reading C++ file 'destructor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/destructor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'destructor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_destructor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_destructor[] = {
    "destructor\0\0open_select_entity()\0"
    "selectEntity()\0removeEntity()\0"
};

void destructor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        destructor *_t = static_cast<destructor *>(_o);
        switch (_id) {
        case 0: _t->open_select_entity(); break;
        case 1: _t->selectEntity(); break;
        case 2: _t->removeEntity(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData destructor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject destructor::staticMetaObject = {
    { &attribute_widget::staticMetaObject, qt_meta_stringdata_destructor,
      qt_meta_data_destructor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &destructor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *destructor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *destructor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_destructor))
        return static_cast<void*>(const_cast< destructor*>(this));
    return attribute_widget::qt_metacast(_clname);
}

int destructor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = attribute_widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
