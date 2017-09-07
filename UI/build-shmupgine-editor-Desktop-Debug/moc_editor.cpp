/****************************************************************************
** Meta object code from reading C++ file 'editor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shmupgine-editor/editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      21,    7,    7,    7, 0x0a,
      48,   46,    7,    7, 0x0a,
      87,   46,    7,    7, 0x0a,
     123,   46,    7,    7, 0x0a,
     157,   46,    7,    7, 0x0a,
     197,  192,    7,    7, 0x0a,
     241,  233,    7,    7, 0x0a,
     281,    7,    7,    7, 0x0a,
     293,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_editor[] = {
    "editor\0\0add_entity()\0request_attribute_menu()\0"
    "a\0manage_attribute_menu_choice(QAction*)\0"
    "manage_config_menu_choice(QAction*)\0"
    "manage_file_menu_choice(QAction*)\0"
    "manage_build_menu_choice(QAction*)\0"
    "attr\0create_attribute(attribute_widget*)\0"
    "id,attr\0create_attribute(int,attribute_widget*)\0"
    "enable_ui()\0disable_ui()\0"
};

void editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        editor *_t = static_cast<editor *>(_o);
        switch (_id) {
        case 0: _t->add_entity(); break;
        case 1: _t->request_attribute_menu(); break;
        case 2: _t->manage_attribute_menu_choice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->manage_config_menu_choice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->manage_file_menu_choice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->manage_build_menu_choice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->create_attribute((*reinterpret_cast< attribute_widget*(*)>(_a[1]))); break;
        case 7: _t->create_attribute((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< attribute_widget*(*)>(_a[2]))); break;
        case 8: _t->enable_ui(); break;
        case 9: _t->disable_ui(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData editor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject editor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_editor,
      qt_meta_data_editor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editor))
        return static_cast<void*>(const_cast< editor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
