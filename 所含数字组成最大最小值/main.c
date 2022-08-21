#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_string(char *p) {
    char * head = p;
    while ((*p = getchar()) != '\n') p++;
    *p = 0;
    return p - head;
}

int main() {
    scanf("%*d ");

    long len;
    char num[101];
    while ((len = get_string(num)) != 0) {
        if (strcmp(num, "0") == 0) {
            printf("0 0\n");
            continue;
        }

        qsort(num, len, 1, strcmp);

        for (int i = len-1; i>=0; i--) {
            putchar(num[i]);
        }

        char * p = num;
        while (*p == '0') ++p;
        printf(" %s\n", p);
    }
}
