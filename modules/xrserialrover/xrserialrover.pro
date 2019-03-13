QT += serialport
TARGET = xrserialrover
DEFINES += XRSERIALROVER_LIBRARY

include($$MOD_DIR/module_gui.pri)
include($$PWD/links.pri)

HEADERS += \
    xrserialrover_global.h \
    XRSerialRoverModule.h \
    XRSerialRoverWorker.h \
    XRStatusBarSerialRoverStatus.h \
    XRStatusBarSerialRoverStatusWidget.h

SOURCES += \
    XRSerialRoverModule.cpp \
    XRSerialRoverWorker.cpp \
    XRStatusBarSerialRoverStatus.cpp \
    XRStatusBarSerialRoverStatusWidget.cpp
