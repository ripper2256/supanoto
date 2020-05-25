QT += testlib sql
QT -= gui
include(../defaults.pri)
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_testdatabase.cpp

LIBS += -L../app -lsupanoto
