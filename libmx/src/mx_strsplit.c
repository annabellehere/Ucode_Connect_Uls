#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) return NULL;
    int words = mx_count_words(s, c);
    int i = 0;
    char **res = (char **) malloc(sizeof(char *) * (words + 1));
    while (*s != '\0') {
        if (*s != c) {
            int length = 0;
	        while (s[length] != c && s[length]) length++;
	        char *temp = mx_strnew(length);
	        if (!temp) return NULL;
	        res[i] = mx_strncpy(temp, s, length);
	        i++;
	        s += length;
	        continue;
        }
        s++;
    }
    res[i] = NULL;
    return res;
}




