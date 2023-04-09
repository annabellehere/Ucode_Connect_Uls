
#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wchar.h>
//#include <malloc/malloc.h>
#include <time.h>
 
typedef struct s_information{
    char **xattrkey;
    char *filename;
    int nlink;
    char *username;
    char *groupname;
    int size_byte;
    mode_t mode;
    time_t mtime;
    int ino;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}       t_information;

typedef struct s_list {
    void *data;
    t_information information;
    struct s_list *next;
}              t_list;

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
double mx_pow(double n, unsigned int pow);
void mx_printint(int n);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

char *mx_strnew(const int size);
int mx_strcmp(const char *s1, const char *s2);
void mx_swap_char(char *s1, char *s2);
void mx_swap(char **a, char **b);
void mx_del_strarr(char ***arr);
void mx_strdel(char **str);
void mx_str_reverse(char *s);
int mx_get_char_index(const char *str, char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strcat(char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *haystack, const char *needle);
char *mx_strchr(const char *s, int c);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
bool mx_isspace(char c);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
//void *mx_realloc(void *ptr, size_t size);

t_list* mx_create_node(void *data, t_information file);
void mx_push_front (t_list **list, void *data, t_information file);
void mx_push_back (t_list **list, void *data, t_information file);

//void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
void sort_list(t_list **head);
void sort_list_to_the_end(t_list **head);
void sort_list_size(t_list **head);
void sort_list_size_end(t_list **head);
void sort_time(t_list **head) ;
void mx_sort_month(t_list **head);
void mx_sort_day(t_list **head);
char *mx_value(const char* file, int start, int end);
int mx_getmonth(char *temp);
void mx_sort_hour(t_list **head);
void mx_sort_minute(t_list **head);
void mx_sort_second(t_list **head);
void mx_check_identy(t_list **head, char* path);

bool mx_check(const char *hex); // hex to nbr
unsigned long mx_checking(const char *hex, unsigned long result, int counter);
int mx_atoi(const char *str);
bool mx_islower(int c);
bool mx_isupper(int c);
int mx_toupper(int c);
int mx_tolower(int c);
void mx_printerr(const char *s);
bool mx_isalpha(int c);
char *mx_itoa(int number);
bool mx_isdigit(int c);
char *mx_delim(const char *s1, const char *s2, char delim);

#endif
