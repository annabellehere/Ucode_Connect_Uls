#include <stdbool.h>

bool mx_isalpha(int c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    else {
        return 0;
    }
}
