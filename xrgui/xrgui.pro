QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xrgui
TEMPLATE = lib

DEFINES += XRGUI_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
	XRApplication.cpp \
    XRUi.cpp \
	XRUiManager.cpp

HEADERS += \
	XRApplication.h \
	xrgui_global.h \
	XRUi.h \
	XRUiManager.h \
    XRWidget.h

include($$TWD/config.pri)

include($$XRCORE_DIR/link.pri)

opt {
	target.path = $$LIB_INSTALL_PATH
	INSTALLS += target
}
