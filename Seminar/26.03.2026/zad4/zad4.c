/*
 *4.	Напишете програма, която получава редица с цели N числа. След това получава цяло
 *число К. Отместете всички елементи на редицата с K позиции, като използвате правилото за
 *превъртане (когато елемент от последна позиция трябва да се измести то той трябва да отиде
 *на първа позиция в редицата).
*/

#include <stdio.h>

int main() {

    int N, K;
    printf("Vuvedete broi na elementite N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Nevaliden broi elementi. N trqbva da e polozhitelno chislo.\n");
    }
    int arr[100];
    printf("Vuvedete %d elementa:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Vuvedete broi pozicii za otmestenite nadqsno (K): ");
    scanf("%d", &K);
    K = K % N;

    if (K < 0) {
        K = K + N;
    }
    if (K > 0) {
        int tempArr[100];
        for (int i = 0; i < N; i++) {

            int new_index = (i + K) % N;
            tempArr[new_index] = arr[i];
        }
        for (int i = 0; i < N; i++) {
            arr[i] = tempArr[i];
        }
    }
    printf("\nIzmestvaniqt masiv e:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}


// Created by Admin on 3/26/2026.
