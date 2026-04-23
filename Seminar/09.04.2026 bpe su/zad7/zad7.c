/*
7з. Да се напише програма, която създава правоъгълна матрица с размер  n на m .
Размерността и стойностите за елементите се въвеждат от клавиатурата.
Да се намери подматрица с размер 3х3, която има максимална сума.
Принтирайте подматрицата.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Vuvedi broi redove n i broi koloni m: ");
    scanf("%d %d", &n, &m);

    if (n < 3 || m < 3) {
        printf("Matricata trqbva da e pone 3x3.\n");
        return 1;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Greshka pri pametta.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Greshka pri pametta.\n");
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }

    printf("Vuvedi elementite na matricata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSum = 0;
    int bestRow = 0;
    int bestCol = 0;
    int first = 1;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int sum = 0;

            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    sum += matrix[r][c];
                }
            }

            if (first || sum > maxSum) {
                maxSum = sum;
                bestRow = i;
                bestCol = j;
                first = 0;
            }
        }
    }

    printf("\nPodmatricata 3x3 s maksimalna suma e:\n");
    for (int i = bestRow; i < bestRow + 3; i++) {
        for (int j = bestCol; j < bestCol + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Maksimalna suma: %d\n", maxSum);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}