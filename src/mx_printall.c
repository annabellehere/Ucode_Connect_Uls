#include "../inc/uls.h"

void mx_align_right(int max, int curr){
    for (int j = 0; j < max - curr; j++){
            mx_printchar(' ');
        }
}

void mx_align_size (int size) {
    double size_f = size;
    while (size_f >= 1000) {
        size_f /= 1024;
    }

    double size_r = mx_round(size_f * 10) / 10;
    if (size_r >= 10) {
        int len = mx_strlen_int(size_f);
        for (int i = 0; i < 4 - len; i++) {
            mx_printchar(' ');
        }
    } else {
        int len = mx_strlen_int(size_f);
        int pr = (long long)(size_r * 10) % 10;
        len += mx_strlen_int(pr) + 1;
        for (int i = 0; i < 4 - len; i++)
            mx_printchar(' ');
    }  
}
 
void mx_printall(int size, t_list *head, t_largest file, t_flags *flag, bool argv_input, char **argv, int argc) {
    if(!head)
        return;
    if (!argv_input){
        if (size != -1){
        mx_printstr("total ");
        mx_printint(size);
        mx_printstr("\n");
    }
    }
        for (t_list *i = head; i != NULL; i = i->next){
        if (argv_input){
            if(S_ISDIR(i->information.mode)){
                continue;
            }
        }
        char buffer_symb_link[512];
        t_list *symb_tmp = NULL;

        if(S_ISLNK(i->information.mode) && flag->l_flag && !flag->C_flag){
            ssize_t symb_link_size;
            if((symb_link_size = readlink(i->data, buffer_symb_link, sizeof(buffer_symb_link))) != 0){
                buffer_symb_link[symb_link_size] = '\0';
                char *symb_link = mx_strnew(symb_link_size);
                symb_link = mx_strncpy(symb_link, buffer_symb_link,symb_link_size);
                symb_tmp = mx_create_node(symb_link, i->information);
                free(symb_link);
            }
        }
        if (flag->i_flag){
                mx_align_right(file.ino, mx_len_int(i->information.ino));
                mx_printint(i->information.ino);
                mx_printstr(" ");
            }
        if(symb_tmp){
            mx_print_access(symb_tmp);
            free(symb_tmp);
        }
        else
            mx_print_access(i);
        mx_align_right(file.link, mx_len_int(i->information.nlink));
        mx_printint(i->information.nlink);
        mx_printstr(" ");
        mx_printstr(i->information.username);
        mx_align_right(file.username, mx_strlen(i->information.username));
        mx_printstr("  ");
        mx_printstr(i->information.groupname);
        mx_align_right(file.group, mx_strlen(i->information.groupname));
        mx_printstr("  ");
        if (flag->h_flag) {
            mx_align_size(i->information.size_byte);
            mx_print_size(i->information.size_byte);

        }
        else {
            mx_align_right(file.file_size, mx_len_int(i->information.size_byte));
            mx_printint(i->information.size_byte);
        }
        mx_printstr(" ");
        mx_printtime(i->information.mtime, flag);
        mx_printstr(" ");
        int is_pipe = !isatty(STDOUT_FILENO); // Перевірка, чи запущена програма через конвеєр
        if(!is_pipe) {
            if (flag->G_flag) mx_print_color(i->information.mode); 
            mx_printstr(i->information.filename);
            if (flag->G_flag) mx_printstr("\033[0m");
        }
        else mx_printstr(i->information.filename);
        if ((flag->p_flag && S_ISDIR(i->information.mode)) || 
                        (flag->F_flag && S_ISDIR(i->information.mode))) mx_printstr("/");
                else if (flag->F_flag && S_ISLNK(i->information.mode)) mx_printstr("@");
                else if (flag->F_flag && S_ISSOCK(i->information.mode)) mx_printstr("=");
                else if (flag->F_flag && S_ISFIFO(i->information.mode)) mx_printstr("|");
                else if (flag->F_flag && (i->information.mode & (S_IXUSR | S_IXGRP | S_IXOTH))) mx_printstr("*");
                //else if (flag->F_flag && (i->information.mode & S_IFWHT)) mx_printstr("%");
        if(S_ISLNK(i->information.mode) && flag->l_flag && !flag->C_flag){
                mx_printstr(" -> ");
                mx_printstr(buffer_symb_link);
            
        }
        mx_printstr("\n");
        if(flag->sob_flag){
            mx_print_xattrs(i, flag);
        }
        if(flag->e_flag) {
            char *acltext = acl_to_text(acl_get_file(i->data, ACL_TYPE_EXTENDED), NULL);
            if (acltext != NULL) {
                char **counts = mx_strsplit(acltext, '\n');
                for (int i = 1; counts[i] != NULL; i++) {
                    mx_printchar(' ');
                    mx_printint(i - 1);
                    mx_printchar(':');
                    mx_printchar(' ');
                    char **delim = mx_strsplit(counts[i], ':');
                    mx_printstr(delim[0]);
                    mx_printchar(':');
                    mx_printstr(delim[2]);
                    mx_printchar(' ');
                    mx_printstr(delim[4]);
                    mx_printchar(' ');
                    mx_printstr(delim[5]);
                    mx_printchar('\n');
                    mx_del_strarr(&delim);
                }
                mx_del_strarr(&counts);
                free(acltext);
            }
        }
        
    }

    if (argv_input){
        int list_size = mx_list_size(head);
        for (t_list *i = head; i != NULL; i = i->next){
            if (argv_input){
                if(S_ISDIR(i->information.mode)){
                    int remain_folders = 0;
                    for(t_list *j = i; j != NULL; j = j->next){
                        if (S_ISDIR(j->information.mode)){
                            remain_folders++;
                            if(remain_folders > 1)
                                break;
                        }
                    }
                    
                    if(list_size != 1) {
                        mx_printstr(i->information.filename);
                        mx_printstr(":\n");
                    }
                    mx_noflag(i->data, flag, argv, argc, 1);
                    if(remain_folders - 1)
                        mx_printstr("\n");
                }
            }
        }
    }

}

int mx_len_int(int a){
    int len = 0;
    int b = a;
    while (b != 0){
        b /= 10;
        len++;
    }
    return len;
}

int mx_strlen_int(int num) {
    if (num == 0) return 1;
    int len = 0;
    for (int i = 0; num > 0; i++) {
        num /= 10;
        len++;
    }
    return len;
}




