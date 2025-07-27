#ifndef VERSION_H
#define VERSION_H

#define QROOTF_VERSION_MAJOR 0
#define QROOTF_VERSION_MINOR 2
#define QROOTF_VERSION_PATCH 0

// Helper macros to create version string from components
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define QROOTF_VERSION_STRING TOSTRING(QROOTF_VERSION_MAJOR) "." \
                            TOSTRING(QROOTF_VERSION_MINOR) "." \
                            TOSTRING(QROOTF_VERSION_PATCH)

#endif // VERSION_H
