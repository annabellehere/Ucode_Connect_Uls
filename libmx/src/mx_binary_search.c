#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char*s, int *count) {
    int counter = 0;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int curr = low + (high - low) / 2;
        if (mx_strcmp(arr[curr], s) == 0) {
            *count = counter + 1;
            return curr;
        }
        if (mx_strcmp(arr[curr], s) < 0) {
            low = curr + 1;
            counter++;
        }
        else {
            high = curr - 1;
            counter++;
        }
    }
    return -1;
}



