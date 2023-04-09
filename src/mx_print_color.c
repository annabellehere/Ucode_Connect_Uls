#include "../inc/uls.h"

void mx_print_color(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFCHR:
        mx_printstr(BLUEYELLOW);
        break;    
    case S_IFBLK:
        mx_printstr(BLUECYAN);
        break;
    case S_IFIFO:
        mx_printstr(YELLOW);
        break;
    case S_IFLNK:
        mx_printstr(MAGENTA);
        break;
    case S_IFSOCK:
        mx_printstr(GREEN);
        break;
    case S_IFDIR:
        if (mode & S_IWOTH) {
            if (mode & S_ISTXT) {
                mx_printstr(BLACKGREEN);
            } else {
                mx_printstr(BLACKYELLOW);
            }
        } else {
            mx_printstr(BLUE);
        }
        break;
    default:
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            if (mode & S_ISUID) {
                mx_printstr(BLACKRED);
            } else if (mode & S_ISGID) {
                mx_printstr(BLACKCYAN);
            } else {
                mx_printstr(RED);
            }
        }
        break;
    }
}

