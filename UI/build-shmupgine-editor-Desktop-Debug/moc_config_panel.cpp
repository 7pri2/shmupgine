/****************************************************************************
** Meta object code from reading C++ file 'config_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/config_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_config_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x0a,
      56,   42,   13,   13, 0x0a,
      95,   84,   13,   13, 0x0a,
     137,  120,   13,   13, 0x0a,
     175,  168,   13,   13, 0x0a,
     205,  196,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_config_panel[] = {
    "config_panel\0\0n_name\0update_name(QString)\0"
    "n_working_dir\0update_working_dir(QString)\0"
    "n_compiler\0update_compiler(QString)\0"
    "n_compiler_flags\0update_compiler_flags(QString)\0"
    "n_make\0update_make(QString)\0n_engine\0"
    "update_engine(QString)\0"
};

void config_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        config_panel *_t = static_cast<config_panel *>(_o);
        switch (_id) {
        case 0: _t->update_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->update_working_dir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->update_compiler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->update_compiler_flags((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->update_make((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->update_engine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData config_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject config_panel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_config_panel,
      qt_meta_data_config_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &config_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *config_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *config_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_config_panel))
        return static_cast<void*>(const_cast< config_panel*>(this));
    return QWidget::qt_metacast(_clname);
}

int config_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
