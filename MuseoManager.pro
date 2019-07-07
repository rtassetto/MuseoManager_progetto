#-------------------------------------------------
#
# Project created by QtCreator 2019-05-21T17:32:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MuseoManager
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

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
        main.cpp \
        View/mainwindow.cpp \
    Model/Gerarchia/bookitem.cpp \
    Model/Gerarchia/documentitem.cpp \
    View/insertitem.cpp \
    View/itemview.cpp \
    Model/Gerarchia/letteritem.cpp \
    Model/Gerarchia/magazineitem.cpp \
    Model/modello.cpp \
    Model/Gerarchia/museoitem.cpp \
    Model/Gerarchia/pictureitem.cpp \
    Model/qproxymodel.cpp \
    Model/qtablemodel.cpp \
    Model/Gerarchia/statueitem.cpp \
    View/tableview.cpp \
    xmlio.cpp \
    View/searchview.cpp

HEADERS += \
        View/mainwindow.h \
    Model/Gerarchia/qontainer.h \
    Model/qproxymodel.h \
    Model/qtablemodel.h \
    Model/Gerarchia/statueitem.h \
    View/tableview.h \
    xmlio.h \
    Model/Gerarchia/bookitem.h \
    Model/Gerarchia/documentitem.h \
    View/insertitem.h \
    View/itemview.h \
    Model/Gerarchia/letteritem.h \
    Model/Gerarchia/magazineitem.h \
    Model/modello.h \
    Model/Gerarchia/museoitem.h \
    Model/Gerarchia/pictureitem.h \
    xmlio.h \
    View/searchview.h

RESOURCES += \
    resource.qrc
