/*
 *1.	Всяка редица от равни числа в едномерен сортиран масив, се нарича площадка.
 *Да се напише програма, която намира началото и дължината на най-дългата площадка в
 *даден сортиран във възходящ ред едномерен масив(въвеждат се N и самият масив от потребителя).
*/

#include <stdio.h>

int main() {
    int n;
    printf("Vuvedete N: ");
    scanf("%d", &n);

    int arr[100];

    printf("Vuvedete elementite (sortirani):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 1;
    int maxStart = 0;

    int currentLen = 0;
    int currentStart = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentLen++;
        } else {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxStart = currentStart;
            }
            currentLen = 1;
            currentStart = i;
        }
    }

    if (currentLen > maxLen) {
        maxLen = currentLen;
        maxStart = currentStart;
    }

    printf("Nai-dulgata ploshtadka zapochva ot indeks %d i e s dulzina %d\n", maxStart, maxLen);

    return 0;
}


//
// Created by Admin on 3/26/2026.
//