/*
*2.	Да се напише програма, която проверява дали между елементите на редицата
*a0, a1, ..., an са изпълнени релациите: a0 < a1 > a2 < a3…
(въвеждат се N и елементите на редицата)
*/

#include <stdio.h>

int main() {
    int n;

    printf("Vuvedete N: ");
    scanf("%d", &n);

    int a[100];

    printf("Vuvedete elementite:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int valid = 1;

    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            if (a[i] <= a[i-1]) {
                valid = 0;
                break;
            }
        } else {
            if (a[i] >= a[i-1]) {
                valid = 0;
                break;
            }
        }
    }

    if (valid) {
        printf("Redicata izpulnqva uslovieto.\n");
    } else {
        printf("Redicata NE izpulnqva uslovieto.\n");
    }

    return 0;
}


//
// Created by Admin on 3/26/2026.
//