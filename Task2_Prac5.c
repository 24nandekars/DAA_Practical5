#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int v;
    char d;
} cell;

cell cost[MAX][MAX];

void LRS(char* str) {
    int n = strlen(str);

    for (int i = 0; i <= n; i++) {
        cost[i][0].v = 0;
        cost[i][0].d = 'H';
        cost[0][i].v = 0;
        cost[0][i].d = 'H';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                cost[i][j].v = cost[i - 1][j - 1].v + 1;
                cost[i][j].d = 'D';
            } else {
                if (cost[i - 1][j].v >= cost[i][j - 1].v) {
                    cost[i][j].v = cost[i - 1][j].v;
                    cost[i][j].d = 'U';
                } else {
                    cost[i][j].v = cost[i][j - 1].v;
                    cost[i][j].d = 'S';
                }
            }
        }
    }

    printf("\nLength of Longest Repeating Subsequence: %d\n", cost[n][n].v);
}

void Print_LRS(int i, int j, char* str) {
    if (i == 0 || j == 0)
        return;

    if (cost[i][j].d == 'D') {
        Print_LRS(i - 1, j - 1, str);
        printf("%c", str[i - 1]);
    } else if (cost[i][j].d == 'U') {
        Print_LRS(i - 1, j, str);
    } else {
        Print_LRS(i, j - 1, str);
    }
}

int main() {
    char str[MAX];

    printf("Enter the string: ");
    scanf("%s", str);

    LRS(str);

    printf("Longest Repeating Subsequence: ");
    Print_LRS(strlen(str), strlen(str), str);
    printf("\n");

    return 0;
}
