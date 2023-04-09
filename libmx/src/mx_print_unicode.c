#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80) {
        char output[1];
        output[0] = ((c >> 0) & 0x7F) | 0x00;
        write(1, output, 1);
    }
    else if (c < 0x0800) {
        char output[2];
        output[0] = ((c >> 6) & 0x1F) | 0xC0;
        output[1] = ((c >> 0) & 0x3F) | 0x80;
        write(1, output, 2);
    }
    else if (c < 0x010000) {
        char output[3];
        output[0] = ((c >> 12) & 0x0F) | 0xE0;
        output[1] = ((c >> 6 ) & 0x3F) | 0x80;
        output[2] = ((c >> 0 ) & 0x3F) | 0x80;
        write(1, output, 3);
    }
    else if (c < 0x110000) {
        char output[4];
        output[0] = ((c >> 18) & 0x07) | 0xF0;
        output[1] = ((c >> 12) & 0x3F) | 0x80;
        output[2] = ((c >> 6 ) & 0x3F) | 0x80;
        output[3] = ((c >> 0 ) & 0x3F) | 0x80;
        write(1, output, 4);
    }
}

