#include "../inc/libmx.h"

bool mx_isspace(char c) {
    if ( c == ' ' || c == '\n' || c == '\t' ||
        c == '\f' || c == '\v' || c == '\r') {
        return 1;
    }
    else {
        return 0;
    }
}
