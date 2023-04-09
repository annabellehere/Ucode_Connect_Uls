#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int count = 0;
    if (s == NULL) return 0;
    while (1) {
        char symb = s[count];
        if (symb == '\0') {
            return count;
        }
        count++;
    }
    return 1;
}



