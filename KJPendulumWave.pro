#-------------------------------------------------
#
# Project created by QtCreator 2017-01-20T14:59:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KJPendulumWave
TEMPLATE = app


SOURCES += main.cpp\
        ControlWindow.cpp \
    DisplayWindow.cpp \
    pendulum.cpp \
    undampedpendulum.cpp \
    dampedpendulum.cpp \
    pendulumsystem.cpp

HEADERS  += ControlWindow.h \
    DisplayWindow.h \
    pendulum.h \
    undampedpendulum.h \
    dampedpendulum.h \
    pendulumsystem.h

FORMS    += ControlWindow.ui \
    DisplayWindow.ui
