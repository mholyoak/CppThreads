#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T16:39:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CppThreads
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cthreadtest.cpp \
    ccountitem.cpp \
    cthreadworker.cpp

HEADERS  += mainwindow.h \
    cthreadtest.h \
    ccountitem.h \
    cthreadworker.h

FORMS    += mainwindow.ui
