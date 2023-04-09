#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int res = 0;
    int b = 1;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 48 && str[i]  <= 57 ) {
            if (str[i-1] == '-') {
            	b = -1;
            	res = (res * 10 + str[i] - '0');
            }
            else res = res * 10 + str[i] - '0';
        }
        if (!(str[i] >= 48 && str[i] <= 57) && res != 0) return res * b;
    }
    return res * b;
}

