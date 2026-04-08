/*
*9.	Напишете програма, която намира  максималната редица от                    последователни еднакви елементи в масив и ги отпечатва.
Примерен вход : 2   1   1   2   3   3   2   2   2   1
Изход :  2   2   2
Сканирате масива . Всеки път , когато текущото число е различно от следващото
от него започва нова поредица, а всеки път когато текущото число съвпада със
следващото , то е продължение на текущата поредица.
*/

#include <stdio.h>

int main() {
    int n;
    int arr[100];
    printf("Vuvedete razmer na masiva: ");
    scanf("%d", &n);
    printf("Vuvedete elementi v masiva: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxLen = 1;
    int currLen = 1;
    int maxElement = arr[0];

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            currLen++;
        } else {

            if (currLen > maxLen) {
                maxLen = currLen;
                maxElement = arr[i]; 
            }
            currLen = 1;
        }
    }


    if (currLen > maxLen) {
        maxLen = currLen;
        maxElement = arr[n - 1];
    }


    printf("Izhod: ");
    for (int i = 0; i < maxLen; i++) {
        printf("%d ", maxElement);
    }

    return 0;
}































//
// Created by Admin on 3/26/2026.
//