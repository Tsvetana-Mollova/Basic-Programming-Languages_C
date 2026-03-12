/*
 *3.	Да се напише програма, която чете 3 числа и отпечатва дали са еднакви
 *(yes / no).
 */

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}



//
// Created by Admin on 3/12/2026.
//