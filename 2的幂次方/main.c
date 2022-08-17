#include <stdio.h>
#include <stdbool.h>

int read_num(int *);

int main(void) {
    scanf("%*d");

    int num;
    while (1 == read_num(&num)) {
        printf("%s\n", (num-1&num)?"NO":"YES");
    }

}

int read_num(int * num) {
    return scanf("%d", num