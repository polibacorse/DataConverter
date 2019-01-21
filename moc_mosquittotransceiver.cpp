/****************************************************************************
** Meta object code from reading C++ file 'mosquittotransceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mosquittotransceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mosquittotransceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MosquittoTransceiver_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MosquittoTransceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MosquittoTransceiver_t qt_meta_stringdata_MosquittoTransceiver = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MosquittoTransceiver"
QT_MOC_LITERAL(1, 21, 9), // "connected"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "disconnected"
QT_MOC_LITERAL(4, 45, 7), // "message"
QT_MOC_LITERAL(5, 53, 5), // "topic"
QT_MOC_LITERAL(6, 59, 7), // "payload"
QT_MOC_LITERAL(7, 67, 18), // "isConnectedChanged"
QT_MOC_LITERAL(8, 86, 10), // "_connected"
QT_MOC_LITERAL(9, 97, 13), // "_disconnected"
QT_MOC_LITERAL(10, 111, 8), // "_message"
QT_MOC_LITERAL(11, 120, 7), // "connect"
QT_MOC_LITERAL(12, 128, 10), // "disconnect"
QT_MOC_LITERAL(13, 139, 7), // "publish"
QT_MOC_LITERAL(14, 147, 9), // "subscribe"
QT_MOC_LITERAL(15, 157, 11) // "isConnected"

    },
    "MosquittoTransceiver\0connected\0\0"
    "disconnected\0message\0topic\0payload\0"
    "isConnectedChanged\0_connected\0"
    "_disconnected\0_message\0connect\0"
    "disconnect\0publish\0subscribe\0isConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MosquittoTransceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    2,   71,    2, 0x06 /* Public */,
       7,    0,   76,    2, 0x06 /* Public */,
       8,    0,   77,    2, 0x06 /* Public */,
       9,    0,   78,    2, 0x06 /* Public */,
      10,    2,   79,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   84,    2, 0x02 /* Public */,
      12,    0,   85,    2, 0x02 /* Public */,
      13,    2,   86,    2, 0x02 /* Public */,
      14,    1,   91,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    5,    6,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,

 // properties: name, type, flags
      15, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       3,

       0        // eod
};

void MosquittoTransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MosquittoTransceiver *_t = static_cast<MosquittoTransceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->message((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 3: _t->isConnectedChanged(); break;
        case 4: _t->_connected(); break;
        case 5: _t->_disconnected(); break;
        case 6: _t->_message((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 7: _t->connect(); break;
        case 8: _t->disconnect(); break;
        case 9: _t->publish((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 10: _t->subscribe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MosquittoTransceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::connected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::message)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::isConnectedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::_connected)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::_disconnected)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MosquittoTransceiver::*_t)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MosquittoTransceiver::_message)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MosquittoTransceiver *_t = static_cast<MosquittoTransceiver *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isConnected_; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MosquittoTransceiver *_t = static_cast<MosquittoTransceiver *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->isConnected_ != *reinterpret_cast< bool*>(_v)) {
                _t->isConnected_ = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->isConnectedChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MosquittoTransceiver::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MosquittoTransceiver.data,
      qt_meta_data_MosquittoTransceiver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MosquittoTransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MosquittoTransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MosquittoTransceiver.stringdata0))
        return static_cast<void*>(const_cast< MosquittoTransceiver*>(this));
    return QThread::qt_metacast(_clname);
}

int MosquittoTransceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MosquittoTransceiver::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MosquittoTransceiver::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MosquittoTransceiver::message(QString _t1, QJsonObject _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MosquittoTransceiver::isConnectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MosquittoTransceiver::_connected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MosquittoTransceiver::_disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MosquittoTransceiver::_message(QString _t1, QJsonObject _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
