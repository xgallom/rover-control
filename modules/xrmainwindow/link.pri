LIBS += -L$$MOD_OUT/xrmainwindow -lxrmainwindow

INCLUDEPATH += $$MOD_DIR/xrmainwindow
DEPENDPATH += $$MOD_DIR/xrmainwindow

opt {
QMAKE_RPATHDIR *= $$MOD_LIB_PATH
} else {
QMAKE_RPATHDIR += $$MOD_LIB_PATH/xrmainwindow
}

