#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int v;
    char d;
} cell;

cell cost[MAX][MAX];

void LCS(char* a, char* b) {
    int m = strlen(a);
    int n = strlen(b);

    for (int i = 0; i <= m; i++) {
        cost[i][0].v = 0;
        cost[i][0].d = 'H';
    }

    for (int j = 0; j <= n; j++) {
        cost[0][j].v = 0;
        cost[0][j].d = 'H';
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] != b[j - 1]) {
                if (cost[i - 1][j].v >= cost[i][j - 1].v) {
                    cost[i][j].v = cost[i - 1][j].v;
                    cost[i][j].d = 'U';
                } else {
                    cost[i][j].v = cost[i][j - 1].v;
                    cost[i][j].d = 'S';
                }
            } else {
                cost[i][j].v = cost[i - 1][j - 1].v + 1;
                cost[i][j].d = 'D';
            }
        }
    }

    printf("\nLCS length: %d\n", cost[m][n].v);
}

void Print_LCS(int i, int j, char* a) {
    if (i == 0 || j == 0)
        return;

    if (cost[i][j].d == 'D') {
        Print_LCS(i - 1, j - 1, a);
        printf("%c", a[i - 1]);
    } else if (cost[i][j].d == 'U') {
        Print_LCS(i - 1, j, a);
    } else {
        Print_LCS(i, j - 1, a);
    }
}

int main() {
    char a[MAX], b[MAX];

    printf("Enter first DNA sequence: ");
    scanf("%s", a);
    printf("Enter second DNA sequence: ");
    scanf("%s", b);

    LCS(a, b);

    printf("LCS: ");
    Print_LCS(strlen(a), strlen(b), a);
    printf("\n");

    return 0;
}
