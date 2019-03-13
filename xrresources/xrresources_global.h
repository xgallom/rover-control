#ifndef XRRESOURCES_GLOBAL_H
#define XRRESOURCES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XRRESOURCES_LIBRARY)
#  define XRRESOURCESSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XRRESOURCESSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XRRESOURCES_GLOBAL_H
