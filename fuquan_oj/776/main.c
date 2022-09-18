#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    enum {dirt, flower} type;
    int min_step;
} box;

void step(const int current, const int i, const int j, const int size, box board[static size][size]) {
    if (i<0||j<0||j>=size||i>=size) return;

    if (board[i][j].type == dirt && ( board[i][j].min_step == 0 || board[i][j].min_step > current)) {
        board[i][j].min_step = current;
    }

    step(current+1, i-1, j, size, board);
    step(current+1, i+1, j, size, board);
    step(current+1, i, j-1, size, board);
    step(current+1, i, j+1, size, board);
}

int main() {
    int n;
    scanf("%d", &n);
    box board[n][n];
    memset(board, 0, sizeof(box)*n*n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '#') board[i][j].type = flower;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j].type == flower) {
                step(0, i, j, n, board);
            }
        }
    }

    int max_step = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int step = board[i][j].min_step;
            if (step > max_step) max_step = step;
        }
    }

    printf("%d\n", max_step);
}
