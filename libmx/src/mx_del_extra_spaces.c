#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;
    char *res = NULL;
    char *temp = NULL;
    int i = 0;
    int j = 0;
    temp = mx_strnew(mx_strlen(str));
    while(str[i]) {
        if (!(mx_isspace(str[i]))) {
            temp[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            temp[j] = ' ';
            j++;
        }
        i++;
    }
    res = mx_strtrim(temp);
    mx_strdel(&temp);
    return res;
}




