#include "../inc/libmx.h"

void *mx_memccpy(void *dst, const void *src, int c, size_t n) {
    char* result = dst;
    const char* p = src;
    const char* end = p + n;
    char ch = ((char)c + 1);  /* ensure ch != c */
    while (1) {
        if (ch == c || p >= end) break;
        *result++ = ch = *p++;
    }
    if (p >= end && ch != c)
        return NULL;
    return result;
}

