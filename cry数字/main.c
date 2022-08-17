#include <stdio.h>
#include <stdbool.h>

int read_num(int *);
bool is_cry(int);
bool is_prime(int);


int main(void) {
    scanf("%*d");
    int n;
    while (read_num(&n) == 1) {
        printf("%s\n", is_cry(n)?"YES":"NO");
    }
}

int read_num(int * num) {
    return scanf("%d", num);
}

bool is_prime(int num) {
    if (num == 2) return true;
    if (num == 1||num % 2 == 0) return false;
    for (int i = 3; i*i <= num; i+=2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_cry(int num) {
    if (!is_prime(num)) return false;

    int b;
    while (b = num % 10) {
        if (!is_prime(b)) return false;
        num /= 10;
    }

    return true;
}
