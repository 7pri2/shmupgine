/****************************************************************************
** Meta object code from reading C++ file 'entities_container.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/entities_container.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'entities_container.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_entities_container[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x0a,
      60,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_entities_container[] = {
    "entities_container\0\0index\0"
    "update_current_index(QModelIndex)\0"
    "remove_entity()\0"
};

void entities_container::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        entities_container *_t = static_cast<entities_container *>(_o);
        switch (_id) {
        case 0: _t->update_current_index((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->remove_entity(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData entities_container::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject entities_container::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_entities_container,
      qt_meta_data_entities_container, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &entities_container::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *entities_container::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *entities_container::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_entities_container))
        return static_cast<void*>(const_cast< entities_container*>(this));
    return QWidget::qt_metacast(_clname);
}

int entities_container::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
