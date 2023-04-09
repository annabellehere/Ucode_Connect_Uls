#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) return malloc(size);
    if(size == 0){
        free(ptr);
        return 0;
    }
    /*if(size <= malloc_size(ptr)){
        return ptr;
    }*/
    void *poin = malloc(size);
    mx_memcpy(poin, ptr, size);
    free(ptr);
    return poin;
}



