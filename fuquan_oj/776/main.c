#include <stdio.h>
#include <string.h>

typedef struct {
    enum {dirt, flower} type;
} box;

int is_valid_index(int i, int j, int size) {
    return !(i<0 || j<0 || i>=size || j>=size);
}

int has_flower(int i, int j, int m, int k, int n, box board[static n][n]) {
    return is_valid_index(i + m, j + k, n) && board[i+m][j+k].type == flower ||
           is_valid_index(i - m, j - k, n) && board[i-m][j-k].type == flower ||
           is_valid_index(i - m, j + k, n) && board[i-m][j+k].type == flower ||
           is_valid_index(i + m, j - k, n) && board[i+m][j-k].type == flower;
}

int main() {
    int n;
    scanf("%d", &n);
    box board[n][n];
    memset(board, 0, sizeof(box)*n*n);

    for (int i=0; i<n; i++) {
        char s[n+1];
        scanf("%s", s);
        for (int j=0; j<n; j++) {
            if (s[j]=='#') board[i][j].type = flower;
        }
    }

    int max_step = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j].type == dirt)
                for (int step=1; step<2*n; step++) {
                    for (int m=0; m<=step; m++) {
                        int k=step-m;
                        if (has_flower(i, j, m, k, n, board)) {
                            if (step > max_step) max_step = step;
                            goto next;
                        }
                    }
                }
next:
        }
    }

    printf("%d\n", max_step);
}
