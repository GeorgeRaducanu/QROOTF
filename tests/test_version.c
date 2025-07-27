#include <stdio.h>
#include <string.h>
#include "qrootf.h"

int main() {
    const char* version = qrootf_get_version();
    if (strcmp(version, QROOTF_VERSION_STRING) == 0) {
        printf("Version test passed.\n");
        return 0;
    } else {
        printf("Version test failed: got %s, instead of %s\n", version, QROOTF_VERSION_STRING);
        return 1;
    }
}
