QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputingRecords
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    legend.cpp \
    legendService.cpp \
    dataaccess.cpp

HEADERS += \
    consoleui.h \
    legend.h \
    legendService.h \
    dataaccess.h
