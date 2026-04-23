/*
 *1з. Даден е двумерен масив NxM запълнен с цели числа. Проверете дали всеки ред съдържа числа,
 *подредени в нарастващ ред, а всяка колона съдържа числа подредени в намаляващ ред.
*/

#include <stdio.h>

int main() {
    int N, M;

    printf("Vuvedete broi redove (N): ");
    scanf("%d", &N);

    printf("Vuvedete broi koloni (M): ");
    scanf("%d", &M);

    int matrix[N][M];

    printf("Vuvedete elementite na matricata:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int rowsAscending = 1;
    int colsDescending = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                rowsAscending = 0;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (matrix[i][j] < matrix[i+1][j]) {
                colsDescending = 0;
            }
        }
    }

    printf("\nResultat:\n");

    if (rowsAscending) {
        printf("Vseki red e podreden v narastvasht red.\n");
    } else {
        printf("NE vseki red e v narastvasht red.\n");
    }

    if (colsDescending) {
        printf("Vsqka kolona e podredena v namalqvasht red.\n");
    } else {
        printf("NE vsqka kolona e v namalqvasht red.\n");
    }

    if (rowsAscending && colsDescending) {
        printf("\nMatricata otgovarq na uslovieto.\n");
    } else {
        printf("\nMatricata NE otgovarq na uslovieto.\n");
    }

    return 0;
}



//
// Created by Admin on 4/9/2026.
//