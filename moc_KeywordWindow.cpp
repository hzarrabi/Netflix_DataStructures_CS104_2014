/****************************************************************************
** Meta object code from reading C++ file 'KeywordWindow.h'
**
** Created: Thu Dec 4 00:58:45 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/KeywordWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeywordWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeywordWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      31,   14,   14,   14, 0x0a,
      45,   14,   14,   14, 0x0a,
      61,   14,   14,   14, 0x0a,
      75,   14,   14,   14, 0x0a,
      90,   14,   14,   14, 0x0a,
     107,   14,   14,   14, 0x0a,
     123,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KeywordWindow[] = {
    "KeywordWindow\0\0returnPressed()\0"
    "rentPressed()\0deletePressed()\0"
    "backPressed()\0titlePressed()\0"
    "keywordPressed()\0logOutPressed()\0"
    "update()\0"
};

void KeywordWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeywordWindow *_t = static_cast<KeywordWindow *>(_o);
        switch (_id) {
        case 0: _t->returnPressed(); break;
        case 1: _t->rentPressed(); break;
        case 2: _t->deletePressed(); break;
        case 3: _t->backPressed(); break;
        case 4: _t->titlePressed(); break;
        case 5: _t->keywordPressed(); break;
        case 6: _t->logOutPressed(); break;
        case 7: _t->update(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData KeywordWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeywordWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KeywordWindow,
      qt_meta_data_KeywordWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeywordWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeywordWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeywordWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeywordWindow))
        return static_cast<void*>(const_cast< KeywordWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int KeywordWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
