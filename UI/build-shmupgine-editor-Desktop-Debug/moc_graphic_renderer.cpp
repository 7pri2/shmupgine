/****************************************************************************
** Meta object code from reading C++ file 'graphic_renderer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/graphic_renderer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphic_renderer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_graphic_renderer[] = {

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
      18,   17,   17,   17, 0x0a,
      39,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_graphic_renderer[] = {
    "graphic_renderer\0\0open_select_Sprite()\0"
    "selectSprite()\0"
};

void graphic_renderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        graphic_renderer *_t = static_cast<graphic_renderer *>(_o);
        switch (_id) {
        case 0: _t->open_select_Sprite(); break;
        case 1: _t->selectSprite(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData graphic_renderer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject graphic_renderer::staticMetaObject = {
    { &attribute_widget::staticMetaObject, qt_meta_stringdata_graphic_renderer,
      qt_meta_data_graphic_renderer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &graphic_renderer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *graphic_renderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *graphic_renderer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_graphic_renderer))
        return static_cast<void*>(const_cast< graphic_renderer*>(this));
    return attribute_widget::qt_metacast(_clname);
}

int graphic_renderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = attribute_widget::qt_metacall(_c, _id, _a);
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
