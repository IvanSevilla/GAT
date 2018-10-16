#ifndef GEOLIB_GLOBAL_H
#define GEOLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GEOLIB_LIBRARY)
#  define GEOLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GEOLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GEOLIB_GLOBAL_H
