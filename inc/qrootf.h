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
 * @param n number of coefficients (n - 1 is the degree of the polynomial)
 * @param in input array of coefficients in descending order of degree
 *  e.g., for a[0]x^2 + a[1]x + a[2], in should be {a[0], a[1], a[2]}
 * @return calculate_roots structure containing the results
 */
qrootf_complex_t* calculate_roots(int n, qrootf_complex_t* in);

/**
 * Addition of two complex numbers
 * @param a First complex number
 * @param b Second complex number
 * @return Resulting complex number after addition
 */
qrootf_complex_t add_qrootf(qrootf_complex_t a, qrootf_complex_t b);


/**
 * Subtraction of two complex numbers
 * @param a First complex number
 * @param b Second complex number
 * @return Resulting complex number after subtraction
 */
qrootf_complex_t sub_qrootf(qrootf_complex_t a, qrootf_complex_t b);

/**
 * Multiplication of two complex numbers
 * @param a First complex number
 * @param b Second complex number
 * @return Resulting complex number after multiplication
 */
qrootf_complex_t mul_qrootf(qrootf_complex_t a, qrootf_complex_t b);

/**
 * Division of two complex numbers
 * @param a First complex number
 * @param b Second complex number
 * @return Resulting complex number after division
 */
qrootf_complex_t div_qrootf(qrootf_complex_t a, qrootf_complex_t b);

/**
 * Calculate the opposite of a complex number
 * @param a Complex number
 * @return Opposite of the complex number
 */
qrootf_complex_t opp_qrootf(qrootf_complex_t a);

/**
 * Get the library version string
 * @return Version string in format "major.minor.patch"
 */
const char* qrootf_get_version(void);

#endif // QROOTF_H
