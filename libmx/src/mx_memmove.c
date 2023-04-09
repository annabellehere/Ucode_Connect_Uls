#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *temp = (char*)malloc(sizeof(char) * len);
    if(temp == NULL) return NULL;
    unsigned int i = 0;
    char *temp_dest = (char*)dst;
    char *temp_src = (char*)src;
    for(i = 0; i < len; i++) *(temp + i) = *(temp_src + i);
    for(i = 0; i < len; i++) *(temp_dest + i) = *(temp + i);
    free(temp);
    return (void*) dst;
}



