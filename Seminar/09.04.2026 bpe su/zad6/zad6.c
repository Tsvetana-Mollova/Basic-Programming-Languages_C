/*
6з. Създайте динамичен масив от цели числа с n на брой елементи,като n и стойностите на елементите
се четат от клавиатурата. Изтрийте простите числа от този масив и създайте втори динамичен масив,
в който ги записвате . Принтирайте двата масива.
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int x) {
    if (x < 2) return 0;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;

    printf("Vuvedi broi elementi: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Greshka pri pametta.\n");
        return 1;
    }

    printf("Vuvedi elementite:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *primes = (int *)malloc(n * sizeof(int));
    if (primes == NULL) {
        printf("Greshka pri pametta.\n");
        free(arr);
        return 1;
    }

    int primeCount = 0;
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            primes[primeCount++] = arr[i];
        } else {
            arr[newSize++] = arr[i];
        }
    }

    printf("\nMasiv bez prostite chisla:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nProstite chisla:\n");
    for (int i = 0; i < primeCount; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");

    free(arr);
    free(primes);

    return 0;
}