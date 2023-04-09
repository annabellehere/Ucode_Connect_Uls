#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    int before = 0;
    int after = mx_strlen(str) - 1;
    for (int i = 0; mx_isspace(str[i]);i++) {
        before++;
    }
    for (int i = mx_strlen(str) - 1; mx_isspace(str[i]); i--) {
        after--;
    }
    if (before > after) return NULL;
    char *s1 = mx_strncpy(mx_strnew(after - before + 1), &str[before], after - before + 1);
    return s1;
}



