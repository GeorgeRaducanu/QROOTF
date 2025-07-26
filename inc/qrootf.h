#ifndef QROOTF_H
#define QROOTF_H

#include "version.h"

/**
 * Structure to hold the complex number representation
 */
typedef struct {
    double re;
    double im;
} qrootf_complex_t;

/**
 * Calculate the roots of a polynomial equation
 * @param in input
 * @return QuadraticRoots structure containing the results
 */
void calculate_roots(double in);

/**
 * Get the library version string
 * @return Version string in format "major.minor.patch"
 */
const char* qrootf_get_version(void);

#endif // QROOTF_H
