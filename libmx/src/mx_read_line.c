#include "../inc/libmx.h"

int mx_read_line(char **resultptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0) return -2;
    for (int i = 0; (*resultptr)[i] != '\0'; i++) (*resultptr)[i] = '\0';
    char *buff = NULL;
    int curr = 0;
    int result = 0;
    while (buff == NULL || buff[curr] != delim) {
        if (buff == NULL || *buff == '\0') {
            buff = mx_strnew(buf_size);
            if(!read(fd, buff, buf_size))
                return result;
        }
        if (buff[curr] != delim) (*resultptr)[result++] = buff[curr++];
        else break;
        if (buff[curr] == '\0') {
            curr = 0;
            mx_strdel(&buff);
        }
    }
    char *temp = mx_strdup(&buff[curr+1]);
    mx_strcpy(buff, temp);
    mx_strdel(&temp);
    return result;
}



