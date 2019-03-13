TEMPLATE = subdirs

SUBDIRS += \
	xrcore \
	xrgui \
	xrresources \
	modules \
	xrover

CONFIG += ordered
OTHER_FILES += module_create.sh docs/Doxyfile
