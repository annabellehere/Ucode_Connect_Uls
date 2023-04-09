#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    if (!str || !sub || !replace || (mx_strlen(str) <= mx_strlen(sub))) return NULL;
	int ext = mx_strlen(replace) - mx_strlen(sub);
	int len = mx_strlen(str) + mx_count_substr(str, sub) * ext;
	char *result = mx_strnew(len);
	int check = 0;
	for (int i = 0; i < len; i++) {
		check = 0;
		if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub))) {
			str += mx_strlen(sub);
			for (int j = 0; j < mx_strlen(replace); i++, j++) {
				result[i] = replace[j];
            }
			check = 1;
		}
		result[i] = *str;
		if (check == 1) {
			str--;
			i--;
		}
		str++;
	}
	return result;
}


