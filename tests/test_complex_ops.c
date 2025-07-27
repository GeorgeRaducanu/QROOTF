#include <stdio.h>
#include <assert.h>
#include "qrootf.h"

int main() {
    qrootf_complex_t a = {2.0, 3.0};
    qrootf_complex_t b = {1.0, -1.0};
    qrootf_complex_t sum = add_qrootf(a, b);
    assert(sum.re == 3.0 && sum.im == 2.0);
    qrootf_complex_t diff = sub_qrootf(a, b);
    assert(diff.re == 1.0 && diff.im == 4.0);
    qrootf_complex_t prod = mul_qrootf(a, b);
    assert(prod.re == 5.0 && prod.im == 1.0);
    printf("Complex operations tests passed.\n");
    return 0;
}
