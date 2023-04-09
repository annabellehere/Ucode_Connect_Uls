#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    const char *copy = hex;
    int counter = 0;
    if (!mx_check(hex)) return 0;
    while (*hex) {
        counter++;
        hex++;
    }
    unsigned long result = 0;
    hex = copy;
    result = mx_checking(hex, result, counter);
    return result;
}

bool mx_check(const char *hex) {
    while (hex && *hex) {
        if (!(*hex >= '0' && *hex <= '9')
             && !(*hex >= 'A' && *hex <= 'F')
             && !(*hex >= 'a' && *hex <= 'f')) {
            return 0;
        }
        hex++;
    }
    return 1;
}

unsigned long mx_checking(const char *hex, unsigned long result, int len) {
    unsigned long help = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= 48 && hex[i] <= 57) {
            result += (hex[i] - 48) * help;
            help = help * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'Z') {
            result += (hex[i] - 55) * help;
            help = help * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'z') {
            result += (hex[i] - 87) * help;
            help = help * 16;
        }
    }
    return result;
}

