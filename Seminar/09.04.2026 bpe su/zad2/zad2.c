/*
 *2з. Даден е масив NxM запълнен с цели числа. Намерете числото, което има околни на него сбора,
 *на които е най-голям. (околно е всяко число което се намира до, над, под или по диагонал на
 *текущото на отстояние не повече от 1 поле).
*/

#include <stdio.h>

int main() {
    int n, m;

    printf("Vavedi broi redove (N): ");
    scanf("%d", &n);

    printf("Vavedi broi koloni (M): ");
    scanf("%d", &m);

    int arr[n][m];

    printf("Vavedi elementite na matricata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int maxSum = -1000000;
    int bestValue = 0;
    int bestI = 0, bestJ = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int sum = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {

                    if (di == 0 && dj == 0)
                        continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        sum += arr[ni][nj];
                    }

                }
            }

            printf("Susedna suma za arr[%d][%d] = %d e %d\n",
                i, j, arr[i][j], sum);

            if (sum > maxSum) {
                maxSum = sum;
                bestValue = arr[i][j];
                bestI = i;
                bestJ = j;
            }
        }
    }

    printf("\n---------------------------\n");
    printf("Chisloto s nai-golqma susedna suma e: %d\n", bestValue);
    printf("Namereno na poziciq [%d][%d]\n", bestI, bestJ);
    printf("Susednata suma e: %d\n", maxSum);

    return 0;
}



//
// Created by Admin on 4/9/2026.
//