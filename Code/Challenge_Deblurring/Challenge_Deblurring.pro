#-------------------------------------------------
#
# Project created by QtCreator 2017-01-11T08:46:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Challenge_Deblurring
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += H:\OpenCV\build\include\opencv2
LIBS += H:\OpenCV\build\x64\vc12
