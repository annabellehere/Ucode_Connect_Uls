#include "../inc/uls.h"

void mx_printtime(const time_t mtime, t_flags *flag) {
    time_t now = time(NULL);
    time_t six_months_sec = (365 / 2) * 24 * 60 * 60;

    mx_print_month(ctime(&mtime));
    mx_print_day(ctime(&mtime));
    if ((mtime + six_months_sec <= now || mtime >= now + six_months_sec) 
        && !flag->T_flag) {
        //mx_printstr(" ");
        mx_print_year(ctime(&mtime));
    }
    else
        mx_print_hour(ctime(&mtime));
    if (flag->T_flag) {
        mx_print_second(ctime(&mtime));
        mx_print_year(ctime(&mtime));
    }
}

void mx_print_day(const char* file_stats) {
    char *tempor = mx_strnew(2);
    int p = 0;
    for (int i = mx_strlen(file_stats) - 17; i < mx_strlen(file_stats) - 15; i++) {
        tempor[p] = file_stats[i];
        p++;
    }
    mx_printstr(tempor);
    free(tempor);
    mx_printstr(" ");
}

void mx_print_month(const char* file_stats) {
    char *tempor = mx_strnew(4);
    int p = 0;
    for (int i = mx_strlen(file_stats) - 21; i < mx_strlen(file_stats) - 18; i++) {
        tempor[p] = file_stats[i];
        p++;
    }
    mx_printstr(tempor);
    free(tempor);
    mx_printstr(" ");
}

void mx_print_hour(const char* file_stats) {
    char *tempor = mx_strnew(3 * sizeof(char *));
    int p = 0;
    for (int i = mx_strlen(file_stats) - 14; i < mx_strlen(file_stats) - 12; i++) {
        tempor[p] = file_stats[i];
        p++;
    }
    mx_printstr(tempor);
    free(tempor);
    mx_print_hvylynka(file_stats);
}

void mx_print_hvylynka(const char *file_stats) {
    char *tmp = mx_strnew(3 * sizeof(char *));
    mx_printstr(":");
    int p = 0;
    for (int i = mx_strlen(file_stats) - 11; i < mx_strlen(file_stats) - 9; i++) {
        tmp[p] = file_stats[i];
        p++;
    }
    mx_printstr(tmp);
    free(tmp);
}

void mx_print_second(const char *file_stats) {
    char *tmp = mx_strnew(3 * sizeof(char *));
    mx_printstr(":");
    int p = 0;
    for (int i = mx_strlen(file_stats) - 8; i < mx_strlen(file_stats) - 6; i++) {
        tmp[p] = file_stats[i];
        p++;
    }
    mx_printstr(tmp);
    free(tmp);
}

void mx_print_year(const char *file_stats) {
    char *tmp = mx_strnew(3 * sizeof(char *));
    mx_printstr(" ");
    int p = 0;
    for (int i = mx_strlen(file_stats) - 5; i < mx_strlen(file_stats) - 1; i++) {
        tmp[p] = file_stats[i];
        p++;
    }
    mx_printstr(tmp);
    free(tmp);
}

