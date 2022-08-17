#include <stdio.h>
#include <stdbool.h>

int main(void) {
    scanf("%*d");

    char s[1011];
    while (scanf("%s", s) == 1) {
        const char * p = s;

        char max_ch;
        int max_time = 0;

        int times[26] = {0};
        while (*p) {
            int time = ++times[*p - 'a'];
            if (time > max_time) {
                max_time = time;
                max_ch = *p;
            }
            ++p;
        }

        printf("%c\n", max_ch);
    }
}
