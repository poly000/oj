#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int rice[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &rice[i][j]);
        }
    }

    int remain = 0;
    for (int i=0; i<(n-1)/2; i++) {
        for (int j=i+1; j<n-i-1; j++) {
            remain += rice[i][j];
        }
    }

    printf("%d\n", remain);
}