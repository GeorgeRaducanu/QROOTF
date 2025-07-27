#include "qrootf.h"
#include <stdlib.h>

qrootf_complex_t* calculate_roots(int n, qrootf_complex_t* in) {
    // Implementation for calculating the roots
    qrootf_complex_t* res = NULL;
    return res;
}

inline qrootf_complex_t add_qrootf(qrootf_complex_t a, qrootf_complex_t b) {
    qrootf_complex_t result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

inline qrootf_complex_t sub_qrootf(qrootf_complex_t a, qrootf_complex_t b) {
    qrootf_complex_t result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

inline qrootf_complex_t mul_qrootf(qrootf_complex_t a, qrootf_complex_t b) {
    qrootf_complex_t result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

inline qrootf_complex_t div_qrootf(qrootf_complex_t a, qrootf_complex_t b) {
    qrootf_complex_t result;
    
    double denom = b.re * b.re + b.im * b.im;

    if ((denom > 0.0 && denom < QROOTF_EPSILON) || (denom < -QROOTF_EPSILON && denom > 0.0)) {
        // Handle division by zero
        result.re = 0.0;
        result.im = 0.0;
    } else {
        result.re = (a.re * b.re + a.im * b.im) / denom;
        result.im = (a.im * b.re - a.re * b.im) / denom;
    }
    return result;
}

inline qrootf_complex_t opp_qrootf(qrootf_complex_t a) {
    qrootf_complex_t result;
    result.re = -a.re;
    result.im = -a.im;
    return result;
}

const char* qrootf_get_version(void) {
    return QROOTF_VERSION_STRING;
}

qrootf_complex_t* allocate_qrootf_complex_t_vector(int size) {
    return (qrootf_complex_t*)malloc(size * sizeof(qrootf_complex_t));
}

void free_qrootf_complex_t_vector(qrootf_complex_t* vec) {
    free(vec);
}
