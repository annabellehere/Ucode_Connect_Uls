#include "../inc/libmx.h"

char *mx_strstr(const char*s1, const char*s2) {
    if ((s1 == NULL) || (s2 == NULL)) return NULL;
    int count2 = mx_strlen(s2);
    if (!count2) return (char *)s1;
    while (*s1 != '\0') {
        int cmp = mx_strncmp(s1, s2, count2);
        if (!cmp) return (char *)s1;
        s1++;
    }
    return NULL;
}



