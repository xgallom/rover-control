TARGET = xrsettings
DEFINES += XRSETTINGS_LIBRARY

include($$MOD_DIR/module_core.pri)

include(defaults.pri)

SOURCES += \
	XRSettingsWorker.cpp \
	XRSettingsModule.cpp \
	XRSettings.cpp

HEADERS += \
	xrsettings_global.h \
	XRSettingsWorker.h \
	XRSettingsModule.h \
	XRSettings.h

DISTFILES += \
	defaults.ini
