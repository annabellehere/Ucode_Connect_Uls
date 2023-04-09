#include "../inc/uls.h"

void mx_printnoflag(t_list *head, int max_filename, int counter, t_flags *flag, t_largest file) {
    if(!head){
        return;
    }
    int is_pipe = !isatty(STDOUT_FILENO); // Перевірка, чи запущена програма через конвеєр
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Розмір вікни
    if (flag->m_flag) {
            for (t_list *i = head; i != NULL; i = i->next){
                mx_printstr(i->information.filename);
                if ((flag->p_flag && S_ISDIR(i->information.mode)) || 
                        (flag->F_flag && S_ISDIR(i->information.mode))) mx_printstr("/");
                    else if (flag->F_flag && S_ISLNK(i->information.mode)) mx_printstr("@");
                    else if (flag->F_flag && S_ISSOCK(i->information.mode)) mx_printstr("=");
                    else if (flag->F_flag && S_ISFIFO(i->information.mode)) mx_printstr("|");
                    else if (flag->F_flag && (i->information.mode & S_IXUSR)) mx_printstr("*");
                    //else if (flag->F_flag && (i->information.mode & S_IFWHT)) mx_printstr("%");

                if (i->next != NULL)     
                    mx_printstr(", ");
                else mx_printstr("\n");
            }
        }
        else if ((is_pipe || flag->one_flag) && !flag->C_flag) {
            for (t_list *i = head; i != NULL; i = i->next){
                if (flag->i_flag) {
                    mx_align_right(file.ino, mx_len_int(i->information.ino));
                    mx_printint(i->information.ino);
                    mx_printstr(" ");
                }
                mx_printstr(i->information.filename);
                if ((flag->p_flag && S_ISDIR(i->information.mode)) || 
                        (flag->F_flag && S_ISDIR(i->information.mode))) mx_printstr("/");
                else if (flag->F_flag && S_ISLNK(i->information.mode)) mx_printstr("@");
                else if (flag->F_flag && S_ISSOCK(i->information.mode)) mx_printstr("=");
                else if (flag->F_flag && S_ISFIFO(i->information.mode)) mx_printstr("|");
                else if (flag->F_flag && (i->information.mode & S_IXUSR)) mx_printstr("*");
                //else if (flag->F_flag && (i->information.mode & S_IFWHT)) mx_printstr("%");

                mx_printchar('\n');
            }
    } else {
        int num_cols = w.ws_col  / (max_filename + 8 + file.ino);
        int num_rows = (counter + num_cols - 1) / num_cols;
        //int num_rows = counter / num_cols + (counter % num_cols > 0 ? 1 : 0);

        char **names = malloc(sizeof(char*) * counter);
        int *numbers = malloc(sizeof(int) * counter);
        mode_t *mod = malloc(sizeof(mode_t) * counter);
        int r = 0;
        for (t_list *i = head; r < counter; r++, i = i->next) {
            names[r] = mx_strdup(i->information.filename);
            numbers[r] = i->information.ino;
            mod[r] = i->information.mode;    
        }
        for (int j = 0; j < num_rows ; j++){
            for (int k = 0; k < num_cols; k++) {
                int index = j + k * num_rows;
                if (index < counter) {
                    if (flag->i_flag) {
                        mx_align_right(file.ino, mx_len_int(numbers[index]));
                        mx_printint(numbers[index]);
                        mx_printstr(" ");
                    }
                    mx_printstr(names[index]);
                    if ((flag->p_flag && S_ISDIR(mod[index])) || 
                        (flag->F_flag && S_ISDIR(mod[index]))) mx_printstr("/");
                    else if (flag->F_flag && S_ISLNK(mod[index])) mx_printstr("@");
                    else if (flag->F_flag && S_ISSOCK(mod[index])) mx_printstr("=");
                    else if (flag->F_flag && S_ISFIFO(mod[index])) mx_printstr("|");
                    else if (flag->F_flag && (mod[index] & S_IXUSR)) mx_printstr("*"); 
                    //else if (flag->F_flag && (mod[index] & S_IFWHT)) mx_printstr("%");
                    int p;
                    if (index + 1 != r){ //FIIIXXXX
                        for (p = 0; p < max_filename - mx_strlen(names[index]); p++) {
                            mx_printstr(" ");  // Додатково вивести пробіли, щоб рівномірно вирівняти слова
                        }
                        //if(k < num_cols - 1){
                            mx_printstr("\t");
                        //}
                    }
                }
            }
            mx_printchar('\n');
        }
    }
}


