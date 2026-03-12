/*
 *1.	Напишете функция, която получава две числа и връща по – голямото от тях.
 *Направете същото и за по -  малкото. Демонстрирайте работата на функциите като четете
 *множество числа до въвеждане на 0 и изкарате най – голямото въведено и най-малкото въведено
 *число.
 */

#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int main() {
    int num;
    int maxNum, minNum;
    int first = 1;

    printf("Vavejdaite chisla (0 za krai):\n");

    while (1) {
        scanf("%d", &num);

        if (num == 0)
            break;

        if (first) {
            maxNum = num;
            minNum = num;
            first = 0;
        } else {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
    }

    if (!first) {
        printf("Nai-golyamoto chislo: %d\n", maxNum);
        printf("Nai-malkoto chislo: %d\n", minNum);
    } else {
        printf("Ne sa vavedeni chisla.\n");
    }

    return 0;
}



//
// Created by Admin on 3/12/2026.
//