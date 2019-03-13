TARGET = xrinfo
DEFINES += XRINFO_LIBRARY

include($$MOD_DIR/module_gui.pri)
include($$PWD/links.pri)

HEADERS += \
    xrinfo_global.h \
    XRInfoWidget.h \
    XRInfoModule.h \
    XRInfoWorker.h \
    XRInfo.h \
    XRContentInfoWidgetDelegate.h

FORMS += \
    XRInfoWidget.ui

SOURCES += \
    XRInfoWidget.cpp \
    XRInfoModule.cpp \
    XRInfoWorker.cpp \
    XRInfo.cpp \
    XRContentInfoWidgetDelegate.cpp
