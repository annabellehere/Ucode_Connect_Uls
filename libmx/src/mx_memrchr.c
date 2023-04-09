#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *res = (unsigned char*) s + n;
    while(n-- > 0) {
        if( *res != (unsigned char)c )
            res--;
        else
            return ((void *) res);
    }
    return ((void *) 0);
}



