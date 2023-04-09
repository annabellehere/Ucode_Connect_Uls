#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *result = dst;
    const char *temp = src;
    while (n--) *result++ = *temp++;
    return result;
}
