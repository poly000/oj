#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int read_num(int *);
char * print_base3(int);

int main(void) {
    int num;
    while (read_num(&num) == 1) {
        printf("%s\n", print_base3(num));
    }
}

int read_num(int * num) {
    return scanf("%d", num);
}

char * print_base3(int num) {

    #define LENGTH 11

    static char result[LENGTH];
    memset(result, 0, LENGTH);

    if (!num) {
        return "0";
    }

    char * p = &result[LENGTH-1];
    while (num) {
        *p-- = num % 3 + '0';
        num /= 3;
    }

    return p+1;
}

