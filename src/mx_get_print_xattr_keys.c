#include "../inc/uls.h"

void mx_print_xattrs(t_list *head, t_flags *flag) {
    if(head->information.xattrkey == NULL) return;
    for (char **src = head->information.xattrkey; *src != NULL; src++) {
        mx_printchar('\t');
        mx_printstr(*src);
        mx_printchar('\t');
        mx_printstr("   ");
        char *np = NULL;
        ssize_t value_size = getxattr(head->data, *src, np, 0, 0, XATTR_NOFOLLOW);
        if (flag->h_flag) mx_print_size(value_size);
        else mx_printint(value_size);
        mx_printstr(" \n");
    }
}

char **mx_get_xattr_keys(const char *filename) {
    char buff[1024]= {'\0'};
    ssize_t count = listxattr(filename, buff, sizeof(buff), XATTR_NOFOLLOW);
    for (int i = 0; i < count - 1; i++) if (buff[i] == '\0') buff[i] = ':';
    if (count > 0) {
        char** str = mx_strsplit(buff, ':');
        return str;
    }
    return NULL;
}

