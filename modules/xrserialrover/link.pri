LIBS += -L$$MOD_OUT/xrserialrover -lxrserialrover

INCLUDEPATH += $$MOD_DIR/xrserialrover
DEPENDPATH += $$MOD_DIR/xrserialrover

opt {
QMAKE_RPATHDIR *= $$MOD_LIB_PATH
} else {
QMAKE_RPATHDIR += $$MOD_LIB_PATH/xrserialrover
}

