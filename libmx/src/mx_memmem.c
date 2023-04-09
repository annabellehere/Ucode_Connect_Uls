#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    char *temp_big = (char*)big;
    char *temp_little = (char*)little;
    if(little_len == 0 || big_len == 0 || big_len < little_len) return NULL;
    if(little_len == 1) return mx_memchr(big, (int)*temp_little, big_len);
    char* end = big_len + (char*)temp_big - little_len;
    for(char* c = (char*)temp_big; c <= end; c++) { // IA KOHAU MARIIU BILOVU
        if(c[0] == temp_little[0] && mx_memcmp(c, temp_little, little_len) == 0) return c;
    }
    return NULL;
}



