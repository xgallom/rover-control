# Comment when running a build from build directory,
# uncomment if installing to /opt
#CONFIG += opt

opt {
	INSTALL_PATH = /opt/xrover
	BIN_INSTALL_PATH = $${INSTALL_PATH}/bin
	LIB_INSTALL_PATH = $${INSTALL_PATH}/lib
	MOD_INSTALL_PATH = $${INSTALL_PATH}/lib

	LIB_PATH = $$LIB_INSTALL_PATH
	MOD_LIB_PATH = $$LIB_PATH
} else {
	LIB_PATH = $$OUT_TWD
	MOD_LIB_PATH = $$LIB_PATH/modules
}

opt {
	DEFINES += APPLICATION_ROOT=\"\\\"$${INSTALL_PATH}\\\"\" \
			APPLICATION_BIN=\"\\\"$${BIN_INSTALL_PATH}\\\"\"
} else {
	DEFINES += APPLICATION_ROOT=\"\\\".\\\"\" \
			APPLICATION_BIN=\"\\\".\\\"\"
}
