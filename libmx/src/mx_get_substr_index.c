#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    int result = 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if(mx_strstr(str, sub)) {
            break;
        }
        result++;
    }
    if (result == 0) return -1;
    return result;
}


