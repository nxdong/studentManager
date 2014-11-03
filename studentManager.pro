#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T12:51:05
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cdatabase.cpp

HEADERS  += mainwindow.h \
    cdatabase.h

FORMS    += mainwindow.ui
