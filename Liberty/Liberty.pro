#-------------------------------------------------
#
# Project created by QtCreator 2020-04-22T11:18:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Liberty
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

SOURCES += \
        main.cpp \
        Vista/mainwindow.cpp \
        Modello/Interfacce/DefenceInterface.cpp \
        Modello/Interfacce/dpsInterface.cpp \
        Modello/Interfacce/healInterface.cpp \
        Modello/Interfacce/magicInterface.cpp \
        Modello/Interfacce/Personaggio.cpp \
        Modello/arciere.cpp \
        Modello/soldato.cpp \
        Modello/guaritore.cpp \
        Modello/mago.cpp


HEADERS += \
        Vista/mainwindow.h

FORMS += \
        Vista/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target