#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T08:35:52
#
#-------------------------------------------------

QT       += core gui
QT += charts qml quick widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WaterTariffCalculator
TEMPLATE = app

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    doublenumber.cpp \
    extendedmeterreading.cpp \
    tariffsforwater.cpp \
    extendedmeterreadingchange.cpp \
    extendedmeterreadinginputsession.cpp \
    session.cpp \
    consumedwatercalculationbinding.cpp \
    waterpricecalculationbinding.cpp \
    bindings/binding.cpp \
    bindings/numeric/numericbinding.cpp \
    bindings/numeric/twonumbersbinding.cpp \
    bindings/numeric/divisionbinding.cpp \
    bindings/numeric/subtractionbinding.cpp \
    jsonutilities.cpp \
    connectors/doublespinboxtonumberconnector.cpp \
    connectors/doublespinboxestoextendedmeterreadingconnector.cpp \
    connectors/doublenumbertospinboxconnector.cpp \
    connectors/extendedmeterreadingtodoublespinboxesconnector.cpp \
    statisticswindow.cpp \
    connectors/doublenumbertonumberconnector.cpp \
    connectors/doublenumberstotwonumbersbindingconnector.cpp \
    connectors/extendedmeterreadingconnector.cpp \
    connectors/extendedmeterreadingchangeconnector.cpp \
    connectors/datatoconsumedwatercalculationbindingconnector.cpp \
    connectors/datatowaterpricecalculationbindingconnector.cpp \
    connectors/tariffsforwaterconnector.cpp

HEADERS  += mainwindow.h \
    doublenumber.h \
    extendedmeterreading.h \
    tariffsforwater.h \
    extendedmeterreadingchange.h \
    extendedmeterreadinginputsession.h \
    session.h \
    consumedwatercalculationbinding.h \
    waterpricecalculationbinding.h \
    bindings/binding.h \
    bindings/numeric/numericbinding.h \
    bindings/numeric/twonumbersbinding.h \
    bindings/numeric/divisionbinding.h \
    bindings/numeric/subtractionbinding.h \
    jsonutilities.h \
    connectors/doublespinboxtonumberconnector.h \
    connectors/doublespinboxestoextendedmeterreadingconnector.h \
    connectors/doublenumbertospinboxconnector.h \
    connectors/extendedmeterreadingtodoublespinboxesconnector.h \
    statisticswindow.h \
    connectors/doublenumbertonumberconnector.h \
    connectors/doublenumberstotwonumbersbindingconnector.h \
    connectors/extendedmeterreadingconnector.h \
    connectors/extendedmeterreadingchangeconnector.h \
    connectors/datatoconsumedwatercalculationbindingconnector.h \
    connectors/datatowaterpricecalculationbindingconnector.h \
    connectors/tariffsforwaterconnector.h

FORMS    += mainwindow.ui \
    statisticswindow.ui

RESOURCES += \
    qml.qrc
