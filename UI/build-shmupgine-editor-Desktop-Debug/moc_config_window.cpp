/****************************************************************************
** Meta object code from reading C++ file 'config_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/config_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_config_window[] = {

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
      27,   15,   14,   14, 0x0a,
      48,   44,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_config_window[] = {
    "config_window\0\0current_tab\0tab_changed(int)\0"
    "tab\0open_tab(int)\0"
};

void config_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        config_window *_t = static_cast<config_window *>(_o);
        switch (_id) {
        case 0: _t->tab_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->open_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData config_window::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject config_window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_config_window,
      qt_meta_data_config_window, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &config_window::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *config_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *config_window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_config_window))
        return static_cast<void*>(const_cast< config_window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int config_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
