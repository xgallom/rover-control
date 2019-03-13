LIBS += -L$$MOD_OUT/xrinfo -lxrinfo

INCLUDEPATH += $$MOD_DIR/xrinfo
DEPENDPATH += $$MOD_DIR/xrinfo

opt {
QMAKE_RPATHDIR *= $$MOD_LIB_PATH
} else {
QMAKE_RPATHDIR += $$MOD_LIB_PATH/xrinfo
}

