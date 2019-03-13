#!/bin/bash
#
# Creates a module subproject in modules directory

# Prints an error message
function error {
	echo -e "$@" >&2
}

# Prints usage information
function usage {
	echo -e "\nUsage:\n\t$0 <core | gui> module-name\n"
}

########################################

# Creates projects directory
#
# Globals:
#  PROJECT_NAME

function create_project_directory {
	mkdir "modules/$PROJECT_NAME"
	if [ $? -ne 0 ]; then
		error "Couldn't create directory modules/$PROJECT_NAME"
		exit 1
	fi
}

########################################

# Generates project file
#
# GLOBALS:
#  PROJECT_NAME
#  PROJECT_TYPE

function generate_project_file {
	local readonly PROJECT_FILE_NAME="$PROJECT_PATH/$PROJECT_NAME.pro"

	cat > "$PROJECT_FILE_NAME" <<- _EOF_
		TARGET = $PROJECT_NAME
		DEFINES += ${PROJECT_NAME_UPPER}_LIBRARY

		include(\$\$MOD_DIR/module_$PROJECT_TYPE.pri)
		include(\$\$PWD/links.pri)

		HEADERS += \\
		    ${PROJECT_NAME}_global.h
	_EOF_

	if [ $? -ne 0 ]; then
		error "Couldn't write to $PROJECT_FILE_NAME"
		exit 1
	fi
}

########################################

# Creates projects link file
#
# Globals:
#  PROJECT_NAME
#  PROJECT_PATH

function generate_project_link_file {
	local readonly PROJECT_LINK_FILE_NAME="$PROJECT_PATH/link.pri"

	cat > "$PROJECT_LINK_FILE_NAME" <<- _EOF_
		LIBS += -L\$\$MOD_OUT/$PROJECT_NAME -l$PROJECT_NAME
	
		INCLUDEPATH += \$\$MOD_DIR/$PROJECT_NAME
		DEPENDPATH += \$\$MOD_DIR/$PROJECT_NAME
	
		opt {
			QMAKE_RPATHDIR *= \$\$MOD_LIB_PATH
		} else {
			QMAKE_RPATHDIR += \$\$MOD_LIB_PATH/$PROJECT_NAME
		}

	_EOF_

	if [ $? -ne 0 ]; then
		error "Couldn't write to $PROJECT_LINK_FILE_NAME"
		exit 1
	fi
}

########################################

# Creates projects links file
#
# Globals:
#  PROJECT_PATH

function generate_project_links_file {
	local readonly PROJECT_LINKS_FILE_NAME="$PROJECT_PATH/links.pri"

	touch "$PROJECT_LINKS_FILE_NAME"

	if [ $? -ne 0 ]; then
		error "Couldn't create file $PROJECT_LINKS_FILE_NAME"
		exit 1
	fi
}

########################################

# Creates projects shared library global header file
#
# Globals:
#  PROJECT_NAME
#  PROJECT_PATH

function generate_project_global_header {
	local readonly PROJECT_GLOBAL_HEADER_FILE_NAME="$PROJECT_PATH/${PROJECT_NAME}_global.h"

	cat > "$PROJECT_GLOBAL_HEADER_FILE_NAME" <<- _EOF_
		#ifndef ${PROJECT_NAME_UPPER}_GLOBAL_H
		#define ${PROJECT_NAME_UPPER}_GLOBAL_H

		#include <QtCore/qglobal.h>

		#if defined(${PROJECT_NAME_UPPER}_LIBRARY)
		#  define ${PROJECT_NAME_UPPER}SHARED_EXPORT Q_DECL_EXPORT
		#else
		#  define ${PROJECT_NAME_UPPER}SHARED_EXPORT Q_DECL_IMPORT
		#endif

		#endif // ${PROJECT_NAME_UPPER}_GLOBAL_H

	_EOF_

	if [ $? -ne 0 ]; then
		error "Couldn't write to $PROJECT_GLOBAL_HEADER_FILE_NAME"
		exit 1
	fi
}

########################################

# Adds project to the list of project modules
#
# Globals:
#  PROJECT_NAME

function add_project_to_project_modules {
	echo -e "\t$PROJECT_NAME \\" >> "modules/modules.pro"

	if [ $? -ne 0 ]; then
		error "Couldn't add module $PROJECT_NAME to modules/modules.pro"
		exit 1
	fi
}

########################################

# Main program

if [ $# -ne 2 ]; then
	error "Invalid list of parameters"
	usage
	exit 1
fi

readonly PROJECT_TYPE=$1
readonly PROJECT_NAME=$2

readonly PROJECT_NAME_UPPER=$(echo "$PROJECT_NAME" | tr '[a-z]' '[A-Z]')
readonly PROJECT_PATH="modules/$PROJECT_NAME"

case "$PROJECT_TYPE" in
	"core"|"gui")
		create_project_directory
		generate_project_file
		generate_project_link_file
		generate_project_links_file
		generate_project_global_header
		add_project_to_project_modules

		exit 0
	;;
	*)
		error "Invalid parameter $PROJECT_TYPE"
		usage
		exit 1
	;;
esac

