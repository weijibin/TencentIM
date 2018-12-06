#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T13:52:04
#
#-------------------------------------------------

QT       += widgets  network core

QT       -= gui

CONFIG += c++11

TARGET = HHIM
TEMPLATE = lib

DEFINES += HHIM_LIBRARY

INCLUDEPATH += $$PWD/libs/includes
INCLUDEPATH += $$PWD/libs/c_include
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./libs/c_includes

SOURCES += \
        hhim.cpp \
    callback.cpp

HEADERS += \
        hhim.h \
        hhim_global.h \ 
    libs/c_includes/tim_c.h \
    libs/c_includes/tim_comm_c.h \
    libs/c_includes/tim_conv_c.h \
    libs/c_includes/tim_friend_c.h \
    libs/c_includes/tim_friendship_proxy.h \
    libs/c_includes/tim_group_assistant.h \
    libs/c_includes/tim_group_c.h \
    libs/c_includes/tim_image_upload_c.h \
    libs/c_includes/tim_int_c.h \
    libs/c_includes/tim_msg_c.h \
    libs/c_includes/tim_relay_c.h \
    libs/c_includes/tim_status_c.h \
    libs/c_includes/tim_wrapper.h \
    callback.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:{
        CONFIG(release, debug|release):{
            DESTDIR = $$PWD/libs/libs/release
            LIBS += $$PWD/libs/libs/release/libtim.lib
        }
        else:CONFIG(debug, debug|release):{
            DESTDIR = $$PWD/libs/libs/debug
            LIBS += $$PWD/libs/libs/debug/libtim.lib
        }
}
