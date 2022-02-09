#-------------------------------------------------
#
# Project created by QtCreator 2018-12-16T01:24:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = core-planner-QtProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    aboutwindow.cpp \
    mdichild.cpp \
    database.cpp \
    graphicitem.cpp \
    points.cpp \
    itembypicture.cpp \
    itembycolor.cpp \
    formcreate.cpp \
    jsondata.cpp \
    fileway.cpp \
    filesave.cpp \
    fileopen.cpp \
    itemeditwindow.cpp

HEADERS += \
    mainwindow.h \
    aboutwindow.h \
    mdichild.h \
    database.h \
    graphicitem.h \
    points.h \
    itembypicture.h \
    itembycolor.h \
    formcreate.h \
    jsondata.h \
    fileway.h \
    filesave.h \
    fileopen.h \
    itemeditwindow.h

FORMS += \
    mainwindow.ui \
    aboutwindow.ui \
    mdichild.ui \
    formcreate.ui \
    itemeditwindow.ui

RESOURCES += \
    core-images.qrc \
    scene-images.qrc \
    core-cursors.qrc

QMAKE_CXXFLAGS += \
    -std=c++0x

TRANSLATIONS +=\
    Core_Planner_ru.ts \
    Core_Planner_en.ts


DISTFILES += \
    Core_Planner_en.ts \
    Core_Planner_ru.ts

#DB
QT += sql
