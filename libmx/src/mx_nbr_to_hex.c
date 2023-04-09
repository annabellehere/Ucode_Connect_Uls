#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) return 0;
    unsigned long copy = nbr;
    int counter = 0;
    for (int i = 0; nbr > 0; i++) {
        nbr = nbr/16;
        counter++;
    }
    char *mas = mx_strnew(counter);
    nbr = copy;
    for (int i = 0; nbr > 0; i++) {
        int temp = nbr % 16;
        if (temp < 10) {
            mas[counter-i-1] = 48 + temp;
        }
        else if (temp >= 10) {
            mas[counter-i-1] = 87 + temp;
        }
        nbr = nbr/16;
    }
    return mas;
}



