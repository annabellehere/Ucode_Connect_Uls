#include "../inc/uls.h"

void mx_check_names(DIR *piska, char **argv, int argc) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && i == 1) {
            continue;
        }
        struct dirent *dir_entry;
        bool indicator = 0;
        while((dir_entry = readdir(piska))) {
            struct stat file_stats;
            if (dir_entry->d_name[0] == '.'){
                continue;
            }
            if (stat(dir_entry->d_name, &file_stats) < 0){
                if (lstat(dir_entry->d_name, &file_stats) != 0)
                {
                    mx_printerr("piska\n"); // NORMAL ERROR
                    exit(1);
                }
            }
            if (mx_strcmp(dir_entry->d_name, argv[i]) == 0) {
                indicator = 1;
            }
        }
        if (!indicator) {
            mx_printerr("uls: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");
            mx_printerr("No such file or directory\n");
            exit(1);
        }
    }
}

