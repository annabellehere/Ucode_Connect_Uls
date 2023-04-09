#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if(!arr) return -1;
    int counter = 0;
    if (left >= right) return 0;
    else {
        int start = left;
        int end = right;
        char *middle = arr[(start + end) / 2];
        while(start < end){
            while(mx_strlen(arr[start]) < mx_strlen(middle))
                start++;
            while(mx_strlen(arr[end]) > mx_strlen(middle))
                end--;
            if(start <= end){
                if(mx_strlen(arr[start]) != mx_strlen(arr[end])) {
                    char *temp = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    counter++;
                }
                start++;
                end--;
            }
        }
        counter += mx_quicksort(arr, left, end);
        counter += mx_quicksort(arr, start, right);
    }
    return counter;
}


