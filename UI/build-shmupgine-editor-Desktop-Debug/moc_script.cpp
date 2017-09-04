/****************************************************************************
** Meta object code from reading C++ file 'script.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/script.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'script.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_script[] = {

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
       8,    7,    7,    7, 0x08,
      21,    7,    7,    7, 0x08,
      33,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_script[] = {
    "script\0\0openEditor()\0getScript()\0"
    "cancelEditor()\0"
};

void script::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        script *_t = static_cast<script *>(_o);
        switch (_id) {
        case 0: _t->openEditor(); break;
        case 1: _t->getScript(); break;
        case 2: _t->cancelEditor(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData script::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject script::staticMetaObject = {
    { &attribute_widget::staticMetaObject, qt_meta_stringdata_script,
      qt_meta_data_script, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &script::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *script::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *script::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_script))
        return static_cast<void*>(const_cast< script*>(this));
    return attribute_widget::qt_metacast(_clname);
}

int script::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
