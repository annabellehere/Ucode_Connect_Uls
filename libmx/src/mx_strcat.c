#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int count1 = mx_strlen(s1);
    char *new_s1 = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    for (int i = 0; i < mx_strlen(s1); i++){
        new_s1[i] = s1[i];
    }
    for (int i = 0; i < mx_strlen(s2); i++ ) {
        new_s1[count1 + i] = s2[i];
    }
    return new_s1;
}


