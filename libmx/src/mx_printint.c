#include "../inc/libmx.h"

void mx_printint(int num) {
    if (num == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    else if (num < 0) {
        write(1, "-", 1);
        num *= -1;
    }
    if (num > 9) mx_printint(num / 10);
    int pr = num % 10 + 48;
    write(1, &pr, 1);
}



