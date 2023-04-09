#include "../inc/libmx.h"

bool mx_islower(int c) {
    if(c >= 'a' && c <= 'z') {
        return 1;
    }
    else {
        return 0;
    }
}


