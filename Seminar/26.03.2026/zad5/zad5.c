/*
 *5.	Дадена е редица с N цели числа. Да не намери K тия по големина елемент в редицата.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (y > x) return 1;
    if (y < x) return -1;
    return 0;
}

int main() {
    int N, K;
    int a[1000];

    printf("Vuvedete broi elementi N: ");
    scanf("%d", &N);

    printf("Vuvedete K: ");
    scanf("%d", &K);

    printf("Vuvedete %d celi chisla:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("K-tiqt po golemina element e: %d\n", a[K - 1]);

    return 0;
}


//
// Created by Admin on 3/26/2026.
//