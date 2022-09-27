#include <stdio.h>
#include <stdbool.h>

static int nums[11451419];

int read_num(int *);
int binary_search(int left_bound, int right_bound, int x, int arr[static right_bound+1]);

int main(void) {
    int n;
    read_num(&n);

    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int num;
    while (read_num(&num) == 1) {
        printf("%s\n", binary_search(0, n-1, num, nums) >= 0 ? "YES" : "NO");
    }

}

int read_num(int * num) {
    return scanf("%d", num);
}

int three_way(int a, int b) {
    if (a<b) return -1;
    if (a==b) return 0;
    return 1;
}

int binary_search(int left_bound, int right_bound, int x, int arr[static right_bound+1]) {
    if (left_bound > right_bound) return -1;

    int mid = (left_bound+right_bound) / 2;

    switch (three_way(arr[mid], x)) {

    case 1:
        return binary_search(left_bound, mid-1, x, arr);
    case -1:
        return binary_search(mid+1, right_bound, x, arr);
    default:
        return mid;
    }

    return -1;
}
