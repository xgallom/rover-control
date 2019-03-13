opt {
	defaultConfig.path = $$BIN_INSTALL_PATH
	defaultConfig.files = $$PWD/defaults.ini
	INSTALLS += defaultConfig
} else {
	QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$PWD/defaults.ini) $$quote($$OUT_TWD/xrover/)
}
