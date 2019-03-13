QT       -= gui

TARGET = xrcore
TEMPLATE = lib

DEFINES += XRCORE_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
	XRCoreApplication.cpp \
	XRModule.cpp \
	XRModuleManager.cpp \
	XRModuleWorker.cpp \
	XRObject.cpp \
    XRThread.cpp \
    XRLog.cpp \
    XRLogModule.cpp \
    XRLogWorker.cpp \
    XRThreadSafeVariant.cpp

HEADERS += \
	xrcore_global.h \
	XRCoreApplication.h \
	XRModule.h \
	XRModuleManager.h \
	XRModuleWorker.h \
	XRObject.h \
    XRThread.h \
	XRThreadPriority.h \
    XRLog.h \
    XRLogModule.h \
    XRLogWorker.h \
    XRThreadSafeVariant.h

include($$TWD/config.pri)

opt {
	target.path = $$LIB_INSTALL_PATH
	INSTALLS += target
}
