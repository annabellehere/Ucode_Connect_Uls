#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *res = (unsigned char*) s;
    while(n-- > 0) {
        if( *res != (unsigned char)c )
            res++;
        else
            return res;
    }
    return 0;
}



