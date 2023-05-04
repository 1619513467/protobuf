#-------------------------------------------------
#
# Project created by QtCreator 2022-06-06T11:39:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = RcfClient
#TEMPLATE = app

## The following define makes your compiler emit warnings if you use
## any feature of Qt which has been marked as deprecated (the exact warnings
## depend on your compiler). Please consult the documentation of the
## deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

## You can also make your code fail to compile if you use deprecated APIs.
## In order to do so, uncomment the following line.
## You can also select to disable deprecated APIs only up to a certain version of Qt.
##DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../../Global.pri)

DESTDIR = $${DESTDIR}/bin
INCLUDEPATH += $${MIDDLEWARE_INC_PATH} \
    $${Utils_INC_PATH} \
    $${LogServer_INC_PATH} \

QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\':\'\$$ORIGIN/lib\'"


INCLUDEPATH +=   ../../../vrv/src/common \
    ../../../vrv/src/classlib \
    ../../../vrv/src/VRVLog \
    ../../../vrv/vrv \
    ../../../Common/

SOURCES += \
        main.cpp \
        rcfclient.cpp \
    senddatathread.cpp

HEADERS += \
        rcfclient.h \
    senddatathread.h

FORMS += \
        rcfclient.ui

LIBS += -l$$Utils_TARGET -luuid

include(../../../After.pri)
