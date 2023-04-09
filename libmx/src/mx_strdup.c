#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int leng = mx_strlen(str);
    char *s1 = (mx_strcpy(mx_strnew(leng), str));
    return s1;
}



