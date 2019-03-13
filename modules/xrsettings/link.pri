LIBS += -L$$MOD_OUT/xrsettings -lxrsettings

INCLUDEPATH += $$MOD_DIR/xrsettings
DEPENDPATH += $$MOD_DIR/xrsettings

opt {
	QMAKE_RPATHDIR *= $$MOD_LIB_PATH
} else {
	QMAKE_RPATHDIR += $$MOD_LIB_PATH/xrsettings
}

