LIBS += -L$$XRCORE_OUT -lxrcore

INCLUDEPATH += $$XRCORE_DIR
DEPENDPATH += $$XRCORE_DIR

opt {
	QMAKE_RPATHDIR *= $$LIB_PATH
} else {
	QMAKE_RPATHDIR += $$LIB_PATH/xrcore
}

