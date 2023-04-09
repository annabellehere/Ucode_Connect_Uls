#include "../inc/uls.h"

void mx_print_access(t_list *file) {
    if(S_ISDIR(file->information.mode)){
        mx_printchar('d');
    }
    else if(S_ISLNK(file->information.mode)){
        mx_printchar('l');
    }
    else if(S_ISCHR(file->information.mode)){
        mx_printchar('c');
    }
    else if(S_ISBLK(file->information.mode)){
        mx_printchar('b');
    }
    else if (S_ISSOCK(file->information.mode)){
        mx_printchar('s');
    }
    else{
        mx_printchar('-');
    }
    mx_printchar( (file->information.mode & S_IRUSR) ? 'r' : '-');
    mx_printchar( (file->information.mode & S_IWUSR) ? 'w' : '-');
    if(file->information.mode & S_ISUID)
        mx_printchar('s');
    else
        mx_printchar( (file->information.mode & S_IXUSR) ? 'x' : '-');

    mx_printchar( (file->information.mode & S_IRGRP) ? 'r' : '-');
    mx_printchar( (file->information.mode & S_IWGRP) ? 'w' : '-');
    if (file->information.mode & S_ISGID)
        mx_printchar('s');
    else
        mx_printchar( (file->information.mode & S_IXGRP) ? 'x' : '-');

    mx_printchar( (file->information.mode & S_IROTH) ? 'r' : '-');
    mx_printchar( (file->information.mode & S_IWOTH) ? 'w' : '-');
    if (file->information.mode & S_ISVTX)
        mx_printchar('t');
    else mx_printchar( (file->information.mode & S_IXOTH) ? 'x' : '-');
    char buffer[512];
    //int len = listxattr(file->data, buffer, sizeof(buffer)); // FOR LINUX
    int len = listxattr(file->data, buffer, sizeof(buffer), 0); // FOR MACOS
    acl_t acl = acl_get_file(file->data,ACL_TYPE_EXTENDED);

    if (len)
        mx_printchar('@');
    else if (acl){
        mx_printchar('+');
        }
    else{
        mx_printchar(' ');
    }
    mx_printchar(' ');
}

