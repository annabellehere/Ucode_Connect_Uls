#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *cop_s1 = (unsigned char*) s1;
    unsigned char *cop_s2 = (unsigned char*) s2;
    int compare = 0;
    if (s1 == s2){
        return compare;
    }
    while (n-- > 0){
        if (*cop_s1 != *cop_s2){
            compare = (cop_s1 - cop_s2);
            break;
        }
        cop_s1++;
        cop_s2++;
    }
    return compare;
}




