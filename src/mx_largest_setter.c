#include "../inc/uls.h"

t_largest mx_largest_setter(t_largest file, int size, int nlink, int username, int group, int ino){
    t_largest tmp;
    tmp.file_size = file.file_size < size ? size : file.file_size;
    tmp.link = file.link < nlink ? nlink : file.link;
    tmp.username = file.username < username ? username : file.username;
    tmp.group = file.group < group ? group : file.group;
    tmp.ino = file.ino < ino ? ino : file.ino;
    return tmp;
}

