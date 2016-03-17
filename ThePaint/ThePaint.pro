#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T19:59:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThePaint
TEMPLATE = app


SOURCES += main.cpp\
        view.cpp \
    control.cpp \
    model.cpp \
    paintarea.cpp

HEADERS  += view.h \
    control.h \
    model.h \
    paintarea.h

RESOURCES += \
    images.qrc

OTHER_FILES +=

