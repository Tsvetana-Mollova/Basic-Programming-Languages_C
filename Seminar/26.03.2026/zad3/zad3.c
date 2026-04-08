/*
 *3.	Напишете програма, която получава масив от N елемента и обръща реда
 *на елементите. Изкарайте ново полученият масив.
*/

#include <stdio.h>

int main() {
    int n;

    printf("Vuvedete broi elementi: ");
    scanf("%d", &n);

    int arr[100];

    printf("Vuvedete elementite:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("Oburni masiv:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


//
// Created by Admin on 3/26/2026.
//