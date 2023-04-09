#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
    int file_to_read = open(filename, O_RDONLY);
    if(file_to_read < 0) return NULL;
    int file = open(filename, O_RDONLY);
    if (file < 0) return NULL;
    char c;
    int size = 0;
    while (read(file, &c, 1)) size++;
    close(file);
    char *str = mx_strnew(size);
    file = open(filename, O_RDONLY);
    if (file < 0) return NULL;
    for (int i = 0; read(file, &c, 1); i++) str[i] = c;
    close(file);
    return str;
}


