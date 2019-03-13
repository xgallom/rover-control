#ifndef XRGUI_GLOBAL_H
#define XRGUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XRGUI_LIBRARY)
#  define XRGUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define XRGUISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XRGUI_GLOBAL_H
