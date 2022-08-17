#include <stdio.h>

size_t get_string(char *p) {
    char * head = p;
    while ((*p = getchar()) != '\n') p++;
    *p = 0;
    return p - head;
}

