#include "../inc/uls.h"


int main(int argc, char** argv) {
    mx_usage(argc, argv);
    
    t_flags flag = {false, false,false,false,false,false,false,false,false,
        false,false,false,false,false,false,false,false,false, false, false,false};
    if (argc >= 2 && argv[1][0] == '-'){
        mx_check_flags(&flag, argv, argc);
    }
   
    //if(argc >= 2) {
    //    mx_check_names(piska, argv, argc);
    //}
    char *path = ".";
    for (int i = 1; i < argc; i++){
        if (argv[i][0] != '-'){
            path = argv[i];
            break;
        }
    }
    mx_noflag(path, &flag, argv, argc, 0);
    exit(0);
}



