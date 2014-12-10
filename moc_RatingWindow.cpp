/****************************************************************************
** Meta object code from reading C++ file 'RatingWindow.h'
**
** Created: Tue Dec 9 22:24:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/RatingWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RatingWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RatingWindow[] = {

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
      14,   13,   13,   13, 0x0a,
      28,   13,   13,   13, 0x0a,
      43,   13,   13,   13, 0x0a,
      58,   13,   13,   13, 0x0a,
      73,   13,   13,   13, 0x0a,
      88,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RatingWindow[] = {
    "RatingWindow\0\0ratePressed()\0ratePressed2()\0"
    "ratePressed3()\0ratePressed4()\0"
    "ratePressed5()\0cancelPressed()\0"
};

void RatingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RatingWindow *_t = static_cast<RatingWindow *>(_o);
        switch (_id) {
        case 0: _t->ratePressed(); break;
        case 1: _t->ratePressed2(); break;
        case 2: _t->ratePressed3(); break;
        case 3: _t->ratePressed4(); break;
        case 4: _t->ratePressed5(); break;
        case 5: _t->cancelPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RatingWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RatingWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RatingWindow,
      qt_meta_data_RatingWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RatingWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RatingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RatingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RatingWindow))
        return static_cast<void*>(const_cast< RatingWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int RatingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
