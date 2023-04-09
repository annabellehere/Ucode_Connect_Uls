#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) return -1;
    int result = 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0 && str[i] == c) {
            result--;
            continue;
        }
        if (str[i+1] == c && str[i] == c ) continue;
        if (str[i] == c) {
            result++;
        }
        if(str[i] == c && str[i + 1] == '\0') result--;
    }
    if (result < 0) return 0;
    return result;
}



