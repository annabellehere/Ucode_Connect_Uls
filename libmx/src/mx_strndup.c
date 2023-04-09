#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char* result = NULL;
    if ((size_t) mx_strlen(s1) <= n) {
        result = mx_strdup(s1);
        return result;
    }
    else {
        result = mx_strnew(n);
        for(size_t i = 0; i < n; i++) {
            result[i] = s1[i];
        }
        return result;
    }
}



