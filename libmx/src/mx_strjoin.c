#include "../inc/libmx.h"

char *mx_strjoin(char const*s1, char const*s2) {
    char *str = NULL;
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);
    str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    str = mx_strcat(str, s1);
    str = mx_strcat(str, s2);
    return str;
}

char *mx_delim(const char *s1, const char *s2, char delim) {
    if (s1 == NULL) {
        return mx_strdup(s2);
    }

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    char *str = mx_strnew(len1 + len2 + 1);

    mx_strcpy(str, s1);
    str[len1] = delim;
    mx_strcpy(str + len1 + 1, s2);

    return str;
}


