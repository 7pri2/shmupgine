/****************************************************************************
** Meta object code from reading C++ file 'new_project.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/new_project.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_new_project[] = {

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
      13,   12,   12,   12, 0x0a,
      39,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_new_project[] = {
    "new_project\0\0switch_create_btn_state()\0"
    "create_new_project()\0"
};

void new_project::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        new_project *_t = static_cast<new_project *>(_o);
        switch (_id) {
        case 0: _t->switch_create_btn_state(); break;
        case 1: _t->create_new_project(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData new_project::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject new_project::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_new_project,
      qt_meta_data_new_project, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &new_project::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *new_project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *new_project::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_new_project))
        return static_cast<void*>(const_cast< new_project*>(this));
    return QWidget::qt_metacast(_clname);
}

int new_project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
