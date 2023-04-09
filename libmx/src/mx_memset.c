#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ptr = (unsigned char*)b;
    int i = 0;
    while (len-- > 0) {
        ptr[i] = (unsigned char )c;
        i++;
    }
    return ptr;
}


