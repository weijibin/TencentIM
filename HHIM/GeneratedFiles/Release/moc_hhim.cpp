/****************************************************************************
** Meta object code from reading C++ file 'hhim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hhim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hhim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HHIM_t {
    QByteArrayData data[9];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HHIM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HHIM_t qt_meta_stringdata_HHIM = {
    {
QT_MOC_LITERAL(0, 0, 4), // "HHIM"
QT_MOC_LITERAL(1, 5, 9), // "sigRecMsg"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 4), // "info"
QT_MOC_LITERAL(4, 21, 12), // "sigJoinGroup"
QT_MOC_LITERAL(5, 34, 7), // "groupId"
QT_MOC_LITERAL(6, 42, 3), // "ids"
QT_MOC_LITERAL(7, 46, 12), // "sigQuitGroup"
QT_MOC_LITERAL(8, 59, 14) // "sigKickOffline"

    },
    "HHIM\0sigRecMsg\0\0info\0sigJoinGroup\0"
    "groupId\0ids\0sigQuitGroup\0sigKickOffline"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HHIM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    2,   37,    2, 0x06 /* Public */,
       7,    2,   42,    2, 0x06 /* Public */,
       8,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void,

       0        // eod
};

void HHIM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HHIM *_t = static_cast<HHIM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigRecMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sigJoinGroup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 2: _t->sigQuitGroup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 3: _t->sigKickOffline(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HHIM::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HHIM::sigRecMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HHIM::*_t)(const QString & , const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HHIM::sigJoinGroup)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HHIM::*_t)(const QString & , const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HHIM::sigQuitGroup)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (HHIM::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HHIM::sigKickOffline)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject HHIM::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HHIM.data,
      qt_meta_data_HHIM,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HHIM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HHIM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HHIM.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HHIM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void HHIM::sigRecMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HHIM::sigJoinGroup(const QString & _t1, const QStringList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HHIM::sigQuitGroup(const QString & _t1, const QStringList & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HHIM::sigKickOffline()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
