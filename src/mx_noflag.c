#include "../inc/uls.h"

void mx_noflag (char * path, t_flags *flag, char **argv, int argc, int recursion_flag) {

    struct dirent *dir_entry;
    t_list *head = NULL;
    int filename_size = 0;
    int counter = 0;
    t_largest file = {0, 0, 0, 0, 0};
    int size = 0;
    int folders_amount = 0;
    bool argv_input = false;
    int input_cursor = 0;
    if (flag->m_flag) flag->l_flag = false;
    if (!recursion_flag){
        for(int i = 1; i < argc; i++){
            if(argv[i][0] != '-'){
                if(argv[i+1] != NULL){
                    argv_input = true;
                    input_cursor = i;
                    break;
                }
            }
        }
    }
    struct stat path_stat;
    char *pather =mx_strnew(mx_strlen(path)); 
    pather = mx_strcpy(pather, path);
    DIR *dir = NULL;
    if(!argv_input) {
        dir = opendir(pather);
        if(lstat(pather, &path_stat) != 0){
            if (dir == NULL){
                mx_printerr("uls: ");
                mx_printerr(pather);
                mx_printerr(": ");
                mx_printerr("No such file or directory\n");   
                exit(1);
            }
        }
    }
    while (true){
        if(argv_input) {
           if (argv_input && input_cursor == argc){
                break;
            }
            dir = NULL;
            char* pather = mx_strnew(mx_strlen(argv[input_cursor])); 
            pather = mx_strcpy(pather, argv[input_cursor]);
            DIR *dir = opendir(pather);
            if(lstat(pather, &path_stat) != 0){
                if (dir == NULL){
                    mx_printerr("uls: ");
                    mx_printerr(pather);
                    mx_printerr(": ");
                    mx_printerr("No such file or directory\n");   
                    exit(1);
                }
            }
            if (dir){
                folders_amount++;
                if  (flag->f_flag) {
                mx_push_front(&head, pather, (t_information){mx_get_xattr_keys(pather), pather,path_stat.st_nlink,
                                                        0, 0, path_stat.st_size ,
                                                        path_stat.st_mode, 0, path_stat.st_ino, 0, 0, 0, 0, 0, 0});
                }
                else{
                    mx_push_back(&head, pather, (t_information){mx_get_xattr_keys(pather), pather,path_stat.st_nlink,
                                                        0, 0, path_stat.st_size ,
                                                        path_stat.st_mode, 0, path_stat.st_ino, 0, 0, 0, 0, 0, 0});
                }
            }
            else{
                struct group *grp;
                struct passwd *pass;

                if ((pass = getpwuid(path_stat.st_uid)) == NULL){
                        perror("getpwuid");
                        exit(1);
                }
                if((grp = getgrgid(path_stat.st_gid)) == NULL) {
                    perror("getgrid");
                    exit(1);
                }

                time_t mods;
                if (flag->c_flag) mods = path_stat.st_ctime;
                else if (flag->u_flag) mods = path_stat.st_atime;
                else mods = path_stat.st_mtime;
                size += path_stat.st_blocks;
                char *username = mx_strnew(mx_strlen(pass->pw_name));
                mx_strcpy(username, pass->pw_name);
                file = mx_largest_setter(file, mx_len_int(path_stat.st_size), mx_len_int(path_stat.st_nlink),mx_strlen(pass->pw_name), mx_strlen(grp->gr_name), mx_len_int(path_stat.st_ino));
                if  (flag->f_flag) {
                    mx_push_back(&head, (void *)pather, (t_information){mx_get_xattr_keys(pather), pather,path_stat.st_nlink,
                                                        username, grp->gr_name, path_stat.st_size ,
                                                        path_stat.st_mode, mods, path_stat.st_ino, 0, 0, 0, 0, 0, 0});
                }
                else { 
                    mx_push_front(&head, (void *)pather, (t_information){mx_get_xattr_keys(pather), pather,path_stat.st_nlink,
                                                        username, grp->gr_name, path_stat.st_size ,
                                                        path_stat.st_mode, mods, path_stat.st_ino, 0, 0, 0, 0, 0, 0});
                }
            }
 
        input_cursor++;
        continue;
        }
       
        else if (!argv_input && S_ISDIR(path_stat.st_mode) && ((dir_entry = readdir(dir)) == NULL))
        {
            break;
        }
        char *filename;
        if (argv_input){
            filename = mx_strnew(mx_strlen(argv[input_cursor]));
            filename = mx_strcpy(filename, argv[input_cursor]);
        }
        else if (!S_ISDIR(path_stat.st_mode)){
            filename = mx_strnew(mx_strlen(pather));
            filename = mx_strcpy(filename, pather);

        }
        else{
            filename = mx_strnew(mx_strlen(dir_entry->d_name));
            filename = mx_strcpy(filename, dir_entry->d_name);
        }
        struct stat file_stats;
        if (flag->A_flag && (!mx_strcmp(filename, ".") || !mx_strcmp(filename, ".."))) {
            continue;
        }
        if (filename[0] == '.' && !flag->a_flag && !flag->A_flag && !flag->f_flag){
            continue;
        }
        char *file_path;
        if (S_ISDIR(path_stat.st_mode)){
            char *file_p = mx_strcat(pather,"/");
            file_path = mx_strcat(file_p,filename);
            free(file_p);
        }
        else{
            file_path = mx_strnew(mx_strlen(filename));
            file_path = mx_strcpy(file_path, filename);
        }
        if (lstat(file_path, &file_stats) != 0){
            mx_printerr("uls: ");
            mx_printerr(file_path);
            mx_printerr(": ");
            mx_printerr("No such file or directory\n");   
            exit(1);            
        }
        counter++;
        if((file_stats.st_mode & S_IFMT) == S_IFDIR)
            folders_amount++;
            struct group *grp;
            struct passwd *pass;
            filename_size = filename_size < mx_strlen(filename) ? mx_strlen(filename) : filename_size;

            if ((pass = getpwuid(file_stats.st_uid)) == NULL){
                    perror("getpwuid");
                    exit(1);
            }
            if((grp = getgrgid(file_stats.st_gid)) == NULL) {
                perror("getgrid");
                exit(1);
            }

            time_t mods;
            if (flag->c_flag) mods = file_stats.st_ctime;
            else if (flag->u_flag) mods = file_stats.st_atime;
            else mods = file_stats.st_mtime;
            size += file_stats.st_blocks;
            char *username = mx_strnew(mx_strlen(pass->pw_name));
            mx_strcpy(username, pass->pw_name);
            file = mx_largest_setter(file, mx_len_int(file_stats.st_size), mx_len_int(file_stats.st_nlink),mx_strlen(pass->pw_name), mx_strlen(grp->gr_name), mx_len_int(file_stats.st_ino));
            if  (flag->f_flag) {
                mx_push_back(&head, (void *)file_path, (t_information){mx_get_xattr_keys(file_path), filename,file_stats.st_nlink,
                                                    username, grp->gr_name, file_stats.st_size ,
                                                    file_stats.st_mode, mods, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
            }
            else { 
                mx_push_front(&head, (void *)file_path, (t_information){mx_get_xattr_keys(file_path), filename,file_stats.st_nlink,
                                                    username, grp->gr_name, file_stats.st_size ,
                                                    file_stats.st_mode, mods, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
            }
        if(!S_ISDIR(path_stat.st_mode) && !argv_input){
            size = -1;
            break;
        }
    }
    if  (flag->S_flag && flag->r_flag) sort_list_size_end(&head);
    else if (flag->S_flag) sort_list_size(&head);
    else if (flag->t_flag) {
        sort_time(&head);
        mx_sort_month(&head);
        mx_sort_day(&head);
        mx_sort_hour(&head);
        mx_sort_minute(&head);
        mx_sort_second(&head);
        mx_check_identy(&head, pather);
    }
    else if (flag->r_flag) sort_list_to_the_end(&head);
    else if (!flag->f_flag) sort_list(&head);
    
   if (!argv_input && flag->l_flag && !flag->R_flag && !flag->C_flag && !flag->one_flag){

            mx_printall(size, head, file, flag, argv_input, argv, argc);
            if (dir != NULL)
                closedir(dir);
    }
    else if (flag->R_flag){
        if (flag->l_flag && !flag->C_flag){
            mx_printall(size, head, file, flag, argv_input, argv, argc);
        }
        else{
            mx_printnoflag(head,filename_size, counter, flag, file);
        }
        if (dir != NULL)
            closedir(dir);

        for (t_list *i = head; i != NULL; i = i->next){
            if ((i->information.mode & S_IFMT) == S_IFDIR){
                mx_printstr("\n");
                mx_printstr(i->data);
                mx_printstr(":\n");
                mx_noflag(i->data, flag, argv, argc, recursion_flag);
            }
            else{
                free(i->data);
                free(i->information.filename);
                free(i->information.username);
                free(i);
            }
        }
    }
    else{
        if (!argv_input){
            if  (flag->S_flag && flag->r_flag) sort_list_size_end(&head);
            else if (flag->S_flag) sort_list_size(&head);
            else if (flag->t_flag) {
                sort_time(&head);
                mx_sort_month(&head);
                mx_sort_day(&head);
                mx_sort_hour(&head);
                mx_sort_minute(&head);
                mx_sort_second(&head);
                mx_check_identy(&head, pather);
            }
            else if (flag->r_flag) sort_list_to_the_end(&head);
            else if (!flag->f_flag) sort_list(&head);
            mx_printnoflag(head, filename_size, counter, flag ,file);
            if (dir != NULL)
                closedir(dir);
        }
        else{
            t_list *head_buffer = NULL;
            filename_size = 0;
            counter = 0;

            for (t_list *i = head; i != NULL; i = i->next){
                if (S_ISDIR(i->information.mode)){
                    continue;
                }
                filename_size = filename_size < mx_strlen(i->information.filename) ? mx_strlen(i->information.filename) : filename_size;
                counter++;
                mx_push_front(&head_buffer,i->data, i->information);
            }
            if(head_buffer){
                if  (flag->S_flag && flag->r_flag) sort_list_size_end(&head);
                else if (flag->S_flag) sort_list_size(&head);
                else if (flag->t_flag) {
                    sort_time(&head);
                    mx_sort_month(&head);
                    mx_sort_day(&head);
                    mx_sort_hour(&head);
                    mx_sort_minute(&head);
                    mx_sort_second(&head);
                    mx_check_identy(&head, pather);
                }
                else if (flag->r_flag) sort_list_to_the_end(&head);
                else if (!flag->f_flag) sort_list(&head);
                if (!flag->l_flag)mx_printnoflag(head_buffer, filename_size, counter, flag, file);
                else 
                    mx_printall(-1, head_buffer, file, flag, 0, argv, argc);

                if(folders_amount){
                    mx_printchar('\n');
                }
            }
            for (t_list *i = head; i != NULL; i = i->next){
                if((i->information.mode & S_IFMT) == S_IFDIR){
                    size = 0;
                    file = (t_largest) {0,0,0,0, 0};
                    if(folders_amount != 0){
                        mx_printstr(i->information.filename);
                        mx_printstr(":\n");
                }
                    t_list *tmp_folder = NULL;
                    DIR *papka = opendir(i->data);
                    int counter = 0;
                    filename_size = 0;
                    while ((dir_entry = readdir(papka))){
                        char *filename = dir_entry->d_name;
                        struct stat file_stats;
                        if (flag->A_flag && (!mx_strcmp(filename, ".") || !mx_strcmp(filename, ".."))) {
                            continue;
                        }
                        if (filename[0] == '.' && !flag->a_flag && !flag->A_flag){
                            continue;
                        }
                        char *dir_path = mx_strcat(mx_strcat(i->data, "/"),filename);
                        if (lstat(dir_path, &file_stats) < 0){
                            mx_printerr("uls: ");
                            mx_printerr(pather);
                            mx_printerr(": ");
                            mx_printerr("No such file or directory\n");   
                            exit(1);
                        }
                        counter++;
                        if(flag->l_flag){
                            struct group *grp;
                            struct passwd *pass;
                            if ((pass = getpwuid(file_stats.st_uid)) == NULL){
                                    perror("getpwuid");
                                    exit(1);
                            }
                            if((grp = getgrgid(file_stats.st_gid)) == NULL) {
                                perror("getgrid");
                                exit(1);
                            }
                            char *username = mx_strnew(mx_strlen(pass->pw_name));
                            mx_strcpy(username, pass->pw_name);
                            size += file_stats.st_blocks;
                            file = mx_largest_setter(file, mx_len_int(file_stats.st_size), mx_len_int(file_stats.st_nlink),mx_strlen(pass->pw_name), mx_strlen(grp->gr_name), mx_len_int(file_stats.st_ino));
                            if(!flag->f_flag) {
                            mx_push_front(&tmp_folder, (void *)dir_path, (t_information){mx_get_xattr_keys(dir_path),filename,file_stats.st_nlink,
                                                                    username, grp->gr_name, file_stats.st_size ,
                                                                    file_stats.st_mode, file_stats.st_mtime, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
                            }
                            else{
                                mx_push_back(&tmp_folder, (void *)dir_path, (t_information){mx_get_xattr_keys(dir_path),filename,file_stats.st_nlink,
                                                                    username, grp->gr_name, file_stats.st_size ,
                                                                    file_stats.st_mode, file_stats.st_mtime, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
                            
                            }
                        }
                        else{
                            file = mx_largest_setter(file, 0,0,0,0, mx_len_int(file_stats.st_ino));
                            filename_size = filename_size < mx_strlen(filename) ? mx_strlen(filename) : filename_size;
                            if(!flag->f_flag) {
                                mx_push_front(&tmp_folder, (void *)dir_path, (t_information){mx_get_xattr_keys(dir_path), filename,0, 0, 0, 0 , file_stats.st_mode, 0, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
                            }
                            else
                                mx_push_back(&tmp_folder, (void *)dir_path, (t_information){mx_get_xattr_keys(dir_path), filename,0, 0, 0, 0 , file_stats.st_mode, 0, file_stats.st_ino, 0, 0, 0, 0, 0, 0});
                            
                        }
                        input_cursor++;
                        }
                    

                        if  (flag->S_flag && flag->r_flag) sort_list_size_end(&head);
                        else if (flag->S_flag) sort_list_size(&head);
                        else if (flag->t_flag) {
                            sort_time(&head);
                            mx_sort_month(&head);
                            mx_sort_day(&head);
                            mx_sort_hour(&head);
                            mx_sort_minute(&head);
                            mx_sort_second(&head);
                            mx_check_identy(&head, pather);
                        }
                        else if (flag->r_flag) sort_list_to_the_end(&head);
                        else if (!flag->f_flag) sort_list(&head);
                        if (!flag->l_flag) mx_printnoflag(tmp_folder, filename_size, counter, flag, file);
                        else{
                            mx_printall(size, tmp_folder, file, flag, 0, argv, argc);

                            }
                        if (--folders_amount)
                            mx_printchar('\n');
                        closedir(papka);
                    }
                }
        }
    }
}


bool mx_inside(char* str, char deli) {
    for(int i = 0; i < mx_strlen(str); i++) {
        if(str[i] == deli) return true;
    }
    return false;
}

char* mx_copy_path(char* path) {
    for(int i = mx_strlen(path) - 1;i > -1; i--) {
        if(path[i] == '/') {
            char* result = malloc(sizeof(char) * i);
            for(int j = 0; j < i;j++) {
                result[j] = path[j];
            }
            return result; // src/mx_noflag.c
        }
    }
    char *result = ".";
    return result;
}

