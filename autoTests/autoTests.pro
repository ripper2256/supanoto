QT += testlib sql
QT -= gui
include(../defaults.pri)
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


INCDIR = ../app
INCLUDEPATH += $$INCDIR
HEADERS += $$INCDIR/database.h

SOURCES += $$INCDIR/database.cpp

SOURCES += tst_testdatabase.cpp
