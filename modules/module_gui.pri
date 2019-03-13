QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

include($$TWD/config.pri)

include($$TWD/xrcore/link.pri)
include($$TWD/xrgui/link.pri)

include($$MOD_DIR/install.pri)

