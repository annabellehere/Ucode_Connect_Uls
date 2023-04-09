#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *numbers = 0;
    if(number == 0){
        numbers = mx_strnew(1);
        mx_strcpy(numbers, "0");
        return numbers;
    }
    else if(number == -2147483648){
        numbers = mx_strnew(11);
        mx_strcpy(numbers, "-2147483648");
        return numbers;
    }
    int tem = number;
    int size = 0;
    bool minus = false;
    if(tem < 0){
        size++;
        number *= -1;
        tem *= -1;
        minus = true;
    }
    for(; tem > 0; size++){
        tem /= 10;
    }
    numbers = mx_strnew(size);
    for (; number > 0; size--){
        numbers[size - 1] = (number % 10) + '0';
        number /= 10;
    }
    if (minus) numbers[0] = '-';
    return numbers;
}


