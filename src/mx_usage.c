#include "../inc/uls.h"

void mx_usage(int argc, char** argv) {
    if (argc >= 2 && (argv[1][0] == '-')) {
        for (int i = 1; i < mx_strlen(argv[1]); i++){
            if (mx_check_val_flags(argv[1][i])){
                mx_printerr("uls: illegal option -- ");
                char er = argv[1][i];
                mx_printerr(&er);
                mx_printerr("\n");
                mx_printerr("usage: uls [-l] [file ...]\n");
                exit(1);
            }
        }
    }
}

bool mx_check_val_flags(char argv) {
    switch(argv) {
        case 'l':
            return 0;
        case 'a':
            return 0;
        case 'R':
            return 0;
        case 'A':
            return 0;
        case 'G':
            return 0;
        case 'h':
            return 0;
        case '@':
            return 0;
        case 'e':
            return 0;
        case 'T':
            return 0;
        case 'i':
            return 0;
        case 'C':
            return 0;
        case 'r':
            return 0;
        case 't':
            return 0;
        case 'u':
            return 0;
        case 'c':
            return 0;
        case 'S':
            return 0;
        case '1':
            return 0;
        case 'm':
            return 0;
        case 'p':
            return 0;
        case 'f':
            return 0;
        case 'F':
            return 0;    
        default:
            return 1;
    }
}

