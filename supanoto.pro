TEMPLATE = subdirs

SUBDIRS = app autoTests
autoTests.depends = app
