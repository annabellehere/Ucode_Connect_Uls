#include "../inc/libmx.h"
void swap(t_list *a, t_list *b) {
    t_list tmp = *a;
    t_list b_buffer = *b;
    *a = *b;
    a->next = tmp.next;
    *b = tmp;
    b->next = b_buffer.next;
}

void sort_list(t_list **head) {
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (mx_strcmp(ptr1->information.filename, ptr1->next->information.filename) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void sort_list_to_the_end(t_list **head) {
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (mx_strcmp(ptr1->information.filename, ptr1->next->information.filename) < 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void sort_list_size(t_list **head) {
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->information.size_byte < ptr1->next->information.size_byte) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            else if (ptr1->information.size_byte == ptr1->next->information.size_byte &&
                mx_strcmp(ptr1->information.filename, ptr1->next->information.filename) > 0) {
                swap(ptr1, ptr1->next);

            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void sort_list_size_end(t_list **head) {
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->information.size_byte > ptr1->next->information.size_byte) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void sort_time(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;
    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 5, 1);
            file_stats1 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats1, 5, 1);
            ptr1->information.year = mx_atoi(tmp1);
            ptr1->next->information.year = mx_atoi(tmp2);
            if (ptr1->information.year < ptr1->next->information.year) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

int mx_getmonth(char *temp) {
    char months[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
        if (mx_strcmp(temp, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

char *mx_value(const char* file, int start, int end) {
    char *tmp1 = mx_strnew(start - end + 1);
    int p = 0;
    for (int i = mx_strlen(file) - start; i < mx_strlen(file) - end; i++) {
        tmp1[p] = file[i];
        p++;
    } 
    return tmp1;
}


void mx_sort_month(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 21, 18);
            const char * file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 21, 18);
            ptr1->information.month = mx_getmonth(tmp1);
            ptr1->next->information.month = mx_getmonth(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month < ptr1->next->information.month) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void mx_sort_day(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 17, 15);
            const char* file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 17, 15);
            ptr1->information.day = mx_atoi(tmp1);
            ptr1->next->information.day = mx_atoi(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month == ptr1->next->information.month &&
                ptr1->information.day < ptr1->next->information.day) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void mx_sort_hour(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 14, 12);
            const char* file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 14, 12);
            ptr1->information.hour = mx_atoi(tmp1);
            ptr1->next->information.hour = mx_atoi(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month == ptr1->next->information.month &&
                ptr1->information.day == ptr1->next->information.day &&
                ptr1->information.hour < ptr1->next->information.hour) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void mx_sort_minute(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 11, 9);
            const char* file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 11, 9);
            ptr1->information.minute = mx_atoi(tmp1);
            ptr1->next->information.minute = mx_atoi(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month == ptr1->next->information.month &&
                ptr1->information.day == ptr1->next->information.day &&
                ptr1->information.hour == ptr1->next->information.hour &&
                ptr1->information.minute < ptr1->next->information.minute) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void mx_sort_second(t_list **head) { // 1 - year .. 1.1 month// 2 - day // 3 - hour // 4 - minute // 5 - second
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 8, 6);
            const char* file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 8, 6);
            ptr1->information.second = mx_atoi(tmp1);
            ptr1->next->information.second = mx_atoi(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month == ptr1->next->information.month &&
                ptr1->information.day == ptr1->next->information.day &&
                ptr1->information.hour == ptr1->next->information.hour &&
                ptr1->information.minute == ptr1->next->information.minute &&
                ptr1->information.second < ptr1->next->information.second) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void mx_check_identy(t_list **head, char* path) {
    bool slash = false;
    if (path[0] == '/') slash = true; 
    int swapped = 1;
    t_list *ptr1;
    t_list *lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL)
        return;

    while(swapped){
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            const char * file_stats1 = ctime(&ptr1->information.mtime);
            char *tmp1 = mx_value(file_stats1, 8, 6);
            const char* file_stats2 = ctime(&ptr1->next->information.mtime);
            char *tmp2 = mx_value(file_stats2, 8, 6);
            ptr1->information.second = mx_atoi(tmp1);
            ptr1->next->information.second = mx_atoi(tmp2);
            if (ptr1->information.year == ptr1->next->information.year &&
                ptr1->information.month == ptr1->next->information.month &&
                ptr1->information.day == ptr1->next->information.day &&
                ptr1->information.hour == ptr1->next->information.hour &&
                ptr1->information.minute == ptr1->next->information.minute &&
                ptr1->information.second == ptr1->next->information.second) {
                if (slash && mx_strcmp(ptr1->information.filename, ptr1->next->information.filename) > 0) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                else if (!slash && mx_strcmp(ptr1->information.filename, ptr1->next->information.filename) < 0) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }

            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }  
}


