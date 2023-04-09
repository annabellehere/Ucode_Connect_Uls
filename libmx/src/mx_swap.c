#include "../inc/libmx.h"

void mx_swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
