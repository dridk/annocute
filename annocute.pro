#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T18:55:08
#
#-------------------------------------------------

QT       += core gui sql
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = annocute
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    previewfilemodel.cpp \
    importfileeditor.cpp \
    mapfilemodel.cpp \
    importdialog.cpp \
    mapfilewidget.cpp \
    previewfilewidget.cpp \
    pathlineedit.cpp

HEADERS  += mainwindow.h \
    previewfilemodel.h \
    importfileeditor.h \
    mapfilemodel.h \
    importdialog.h \
    mapfilewidget.h \
    previewfilewidget.h \
    pathlineedit.h

FORMS    += mainwindow.ui
