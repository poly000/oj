#include <stdio.h>
#include <stdbool.h>

static int nums[100000];

int read_num(int *);
bool contains(int n, int key, int nums[static n]);

int main(void) {
    int n;
    read_num(&n);

    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%*d");

    int num;
    while (read_num(&num) == 1) {
        printf("%s\n", contains(n, num, nums) ? "YES" : "NO");
    }

}

int read_num(int * num) {
    return scanf("%d", num);
}


bool contains(int n, int key, int nums[static n]) {
    if (n == 0) return false;

    if (n%2 == 0) {
        return contains(n/2, key, nums) || contains(n/2, key, &nums[n/2]);
    }

    if (nums[n/2] == key) return true;
    else return contains(n/2, key, nums)||contains(n/2, key, &nums[n/2+1]);
}
