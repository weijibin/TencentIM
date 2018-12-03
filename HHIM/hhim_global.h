#ifndef HHIM_GLOBAL_H
#define HHIM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HHIM_LIBRARY)
#  define HHIMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HHIMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HHIM_GLOBAL_H
