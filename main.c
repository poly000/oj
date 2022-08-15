#include <stdio.h>

char input[100001] = {0};

size_t get_string(char *);

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // skip '\n'

    while (n--) {
        size_t len = get_string(input);

        const char * head = input;
        const char * end = input+len-1;

        int rep = 1;
        while (head < end) {
            if (*head != *end) {
                rep = 0;
                break;
            }
            head++;
            end--;
        }

        if(rep) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

size_t get_string(char *p) {
    char * head = p;
    while ((*p = getchar()) != '\n') p++;
    *p = 0;
    return p - head;
}
