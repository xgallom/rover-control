TARGET = xrmainwindow
DEFINES += XRMAINWINDOW_LIBRARY

include($$MOD_DIR/module_gui.pri)
include($$PWD/links.pri)

HEADERS += \
    xrmainwindow_global.h \
    XRMainWindow.h \
    XRStatusBar.h \
    XRStatusBarStatus.h \
    XRStatusBarTextStatus.h \
    XRCentralWidget.h \
    XRCentralContentWidget.h \
    XRContentWidget.h \
    XRContentWidgetDelegate.h

SOURCES += \
    XRMainWindow.cpp \
    XRStatusBar.cpp \
    XRStatusBarStatus.cpp \
    XRStatusBarTextStatus.cpp \
    XRCentralWidget.cpp \
    XRCentralContentWidget.cpp \
    XRContentWidget.cpp \
    XRContentWidgetDelegate.cpp
