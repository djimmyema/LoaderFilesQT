
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = LoaderQt

SOURCES += main.cpp \
    mainwindow.cpp \
    subject.cpp \
    progressbar.cpp \
    fileloader.cpp \
    observer.cpp \
    splashwindow.cpp \
    file.cpp

HEADERS += \
    mainwindow.h \
    subject.h \
    observer.h \
    progressbar.h \
    fileloader.h \
    splashwindow.h \
    file.h

FORMS += \
    mainwindow.ui
