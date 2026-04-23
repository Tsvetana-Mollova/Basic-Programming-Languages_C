/*
 *3з. Дадена е матрица NxM запълнена с цели числа. Разменете редовете с най-голям
 *и най-малък елемент.
*/

#include <stdio.h>

int main() {
    int N, M;

    printf("Vuvedi broi redove N: ");
    scanf("%d", &N);

    printf("Vuvedi broi koloni M: ");
    scanf("%d", &M);

    int a[N][M];

    printf("Vuvedi elementite na matricata:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int max = a[0][0], min = a[0][0];
    int rowMax = 0, rowMin = 0;

    for (int i = 0; i < N; i++) {
        for (int j= 0; j < M; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                rowMax = i;
            }
            if (a[i][j] < min) {
                min = a[i][j];
                rowMin = i;
            }
        }
    }

    if (rowMax != rowMin) {
        for (int j = 0; j < M; j++) {
            int temp = a[rowMax][j];
            a[rowMax][j] = a[rowMin][j];
            a[rowMin][j] = temp;
        }
    }

    printf("\nRed s nai-golqm element (%d): %d\n", max, rowMax);
    printf("Red s nai-maluk element (%d): %d\n", min, rowMin);

    printf("\nMatricata sled razmqnata e:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}




//
// Created by Admin on 4/9/2026.
//