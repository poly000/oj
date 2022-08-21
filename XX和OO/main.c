#include <stdio.h>

int read_num(int *);
void mark(const char *);
int termial(int);

int main(void) {
    scanf("%*d");

    char s[81] = {0};
    while (scanf("%s", s) == 1) {
        mark(s);
    }
}

void mark(const char * s) {
    int grade = 0;

    int count = 0;
    while (*s) {
        if (*s++ == 'O') {
            ++count;
            printf("%d", count);
        } else {
            grade += termial(count);
            count = 0;
            printf("0");
        }
        if (*s) putchar('+');
    }
    grade += termial(count);

    printf("=%d\n", grade);
}

int termial(int num) {
    return num*(num+1)/2;
}
