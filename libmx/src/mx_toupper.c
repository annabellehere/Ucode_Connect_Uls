#include "../inc/libmx.h"

int mx_toupper(int c) {
    if (c >= 'A' && c <= 'Z') {
        char b = c;
        return b;
    }
    if (c >= 'a' && c <= 'z') {
        char b = c-32;
        return b;
    }
    else {
        return c;
    }
}
