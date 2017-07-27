/****************************************************************************
** Meta object code from reading C++ file 'graphics_manager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/graphics_manager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphics_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_graphics_manager[] = {

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
      18,   17,   17,   17, 0x08,
      38,   32,   17,   17, 0x08,
      67,   62,   17,   17, 0x08,
      96,   17,   17,   17, 0x08,
     111,   17,   17,   17, 0x08,
     128,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_graphics_manager[] = {
    "graphics_manager\0\0add_picture()\0index\0"
    "fill_infos(QModelIndex)\0item\0"
    "update_infos(QStandardItem*)\0"
    "update_model()\0delete_picture()\0"
    "dis_or_enable_details()\0"
};

void graphics_manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        graphics_manager *_t = static_cast<graphics_manager *>(_o);
        switch (_id) {
        case 0: _t->add_picture(); break;
        case 1: _t->fill_infos((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->update_infos((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 3: _t->update_model(); break;
        case 4: _t->delete_picture(); break;
        case 5: _t->dis_or_enable_details(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData graphics_manager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject graphics_manager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_graphics_manager,
      qt_meta_data_graphics_manager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &graphics_manager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *graphics_manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *graphics_manager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_graphics_manager))
        return static_cast<void*>(const_cast< graphics_manager*>(this));
    return QWidget::qt_metacast(_clname);
}

int graphics_manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
