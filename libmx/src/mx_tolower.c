#include "../inc/libmx.h"

int mx_tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        char b = c+32;
        return b;
    }
    if (c >= 'a' && c <= 'z') {
        char b = c;
        return b;
    }
    else {
        return c;
    }
}
