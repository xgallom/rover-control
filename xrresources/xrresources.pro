QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xrresources
TEMPLATE = lib

DEFINES += XRRESOURCES_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES +=

HEADERS += \
	xrresources_global.h \
    XRResources.h

include($$TWD/config.pri)

opt {
	target.path = $$LIB_INSTALL_PATH
	INSTALLS += target
}

RESOURCES += \
    pixmap.qrc
