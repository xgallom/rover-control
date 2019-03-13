#ifndef XRINFO_GLOBAL_H
#define XRINFO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XRINFO_LIBRARY)
#  define XRINFOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XRINFOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XRINFO_GLOBAL_H

