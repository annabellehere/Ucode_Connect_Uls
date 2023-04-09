#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -1;
    if (mx_strlen(sub) == 0) return 0;
    int result = 0;
    const char *temp = str;
    for (int i = 0; i < mx_strlen(str); i++) {
        if(mx_strstr(temp, sub)) {
            result++;
        }
        temp++;
    }
    return result;
}



