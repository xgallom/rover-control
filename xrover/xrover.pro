QT += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xrover
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++17

include($$TWD/config.pri)
include($$PWD/links.pri)

opt {
	target.path = $$BIN_INSTALL_PATH
	INSTALLS += target
}

SOURCES += \
	Application.cpp \
	main.cpp \
	ModuleLoader.cpp \
	UiLoader.cpp

HEADERS += \
	Application.h \
	ModuleLoader.h \
	UiLoader.h
