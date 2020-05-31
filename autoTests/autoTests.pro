QT += testlib sql
QT -= gui
include(../defaults.pri)
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


INCDIR = ../app
INCLUDEPATH += $$INCDIR
HEADERS += $$INCDIR/database.h  $$INCDIR/note.h

SOURCES += $$INCDIR/database.cpp  $$INCDIR/note.cpp \



SOURCES +=  tst_unitTestClass.cpp
