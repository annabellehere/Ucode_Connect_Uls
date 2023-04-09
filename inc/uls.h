#pragma once

#include "../libmx/inc/libmx.h"
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <sys/acl.h> // FROM MAKEFILE DELETE -L/usr/lib/x86_64-linux-gnu -lacl from FLAGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>

#define BLUEYELLOW "\033[34;43m"
#define BLUECYAN "\033[34;46m"
#define YELLOW "\033[34m"
#define MAGENTA "\033[35m"
#define GREEN "\033[32m"
#define BLACKGREEN "\033[30;42m"
#define BLACKYELLOW "\033[30;43m"
#define BLUE "\033[34m"
#define BLACKRED "\033[30;41m"
#define BLACKCYAN "\033[30;46m"
#define RED "\033[31m"

typedef struct s_largest{
        int file_size;
        int link;
        int username;
        int group;
        int ino;
}       t_largest;

typedef struct s_flags{
        bool l_flag; // done
        bool a_flag; // done
        bool A_flag; // done
        bool R_flag; // done
        bool G_flag; // done
        bool h_flag; // done
        bool sob_flag; // done
        bool e_flag; // done
        bool T_flag; // done
        bool i_flag; // done
        bool C_flag; // done
        bool r_flag; // done
        bool t_flag; // done
        bool u_flag; // done
        bool c_flag; // done
        bool S_flag; // done
        bool one_flag; // done
        bool m_flag; // done
        bool p_flag; // done
        bool f_flag; // done
        bool F_flag; // done
}       t_flags;

t_largest mx_largest_setter(t_largest file, int size, int nlink, int username, int group, int ino);
void mx_printall(int size, t_list *head, t_largest file, t_flags *flag, bool argv_input, char **argv, int argc);
void mx_usage(int argc, char** argv);
int mx_len_int(int a);
void mx_printtime(const time_t mtime, t_flags *flag);
bool mx_check_time(int check);
void mx_print_access(t_list *file);
void mx_print_day(const char* file_stats);
void mx_print_month(const char* file_stats);
void mx_print_hour(const char* file_stats);
void mx_print_hvylynka(const char *file_stats);
int lstat(const char *path, struct stat *buf);
void mx_noflag (char *path, t_flags *flag, char **argv, int argc, int recursion_flag);
void mx_printnoflag(t_list *head, int max_filename, int counter, t_flags *flag, t_largest file);
void mx_check_names(DIR *piska, char **argv, int argc);
void mx_align_right(int max, int curr);
void mx_check_flags(t_flags *flag, char **argv, int argc);
bool mx_check_val_flags(char argv);
void mx_print_second(const char *file_stats);
void mx_print_year(const char *file_stats);
void mx_print_size(int size);
double mx_round(double in);
void mx_align_size (int size);
int mx_strlen_int(int num);
void mx_print_color(mode_t mode);
char **mx_get_xattr_keys(const char *filename);
void mx_print_xattrs(t_list *head, t_flags *flag);
char* mx_copy_path(char* path);
bool mx_inside(char* str, char deli);




