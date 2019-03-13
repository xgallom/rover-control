#ifndef XRCORE_GLOBAL_H
#define XRCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XRCORE_LIBRARY)
#  define XRCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define XRCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XRCORE_GLOBAL_H
