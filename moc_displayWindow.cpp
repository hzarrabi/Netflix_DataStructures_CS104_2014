/****************************************************************************
** Meta object code from reading C++ file 'displayWindow.h'
**
<<<<<<< HEAD
** Created: Fri Dec 5 13:04:25 2014
=======
** Created: Thu Dec 4 00:58:43 2014
>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/displayWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displayWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_displayWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   14,   14,   14, 0x0a,
      38,   14,   14,   14, 0x0a,
      45,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_displayWindow[] = {
    "displayWindow\0\0updateParent()\0nextM()\0"
    "addM()\0returnToMenu()\0"
};

void displayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        displayWindow *_t = static_cast<displayWindow *>(_o);
        switch (_id) {
        case 0: _t->updateParent(); break;
        case 1: _t->nextM(); break;
        case 2: _t->addM(); break;
        case 3: _t->returnToMenu(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData displayWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject displayWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_displayWindow,
      qt_meta_data_displayWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &displayWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *displayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *displayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_displayWindow))
        return static_cast<void*>(const_cast< displayWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int displayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void displayWindow::updateParent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
