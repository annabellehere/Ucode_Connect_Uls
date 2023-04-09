#include "../inc/uls.h"

void mx_print_size(int size) {
    const char *suffixes = {"BKMGTP"};
    double size_f = size;
    int suffix = 0;
    while (size_f >= 1000) {
        size_f /= 1024;
        suffix++;
    }

    double size_r = mx_round(size_f * 10) / 10;
    if (size_r >= 10 || suffix == 0) {
        mx_printint(mx_round(size_f));
        mx_printchar(suffixes[suffix]);
    } else {
        mx_printint(mx_round(size_f));
        int pr = (long long)(size_r * 10) % 10;
        mx_printchar('.');
        mx_printint(pr);
        mx_printchar(suffixes[suffix]);
    }
}

double mx_round(double in) {
    if (in >= 0.0){
        return (int)(in + 0.5);
    }
    else return (int)(in - 0.5);
}


