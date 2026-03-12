/*
12.	Да се напише програма, която прочита от конзолата цяло число n, въведено от потребителя,
и чертае пеперуда с ширина 2 * n - 1 колони и височина 2 * (n - 2) + 1 реда като
в примерите по-долу.  Лявата и дясната ѝ част са широки n - 1.
вход
3
изход
   \ /*
    @
*/// \*
/*вход
5
изход
***\ /***
---\ /---
***\ /***
    @
***/ // \***
// ---/ \---
// ***/ \***


#include <stdio.h>

int main() {
    int n;

    printf("Vuvedete cqlo chislo n: ");
    scanf("%d", &n);

    int i, j;

    // Горна част на пеперудата
    for(i = 0; i < n-2; i++) {
        char symbol;

        if(i % 2 == 0)
            symbol = '*';
        else
            symbol = '-';

        for(j = 0; j < n-1; j++)
            printf("%c", symbol);

        printf("\\ /");

        for(j = 0; j < n-1; j++)
            printf("%c", symbol);

        printf("\n");
    }

    // Среден ред
    for(j = 0; j < n-1; j++)
        printf(" ");
    printf("@\n");

    // Долна част
    for(i = 0; i < n-2; i++) {
        char symbol;

        if(i % 2 == 0)
            symbol = '*';
        else
            symbol = '-';

        for(j = 0; j < n-1; j++)
            printf("%c", symbol);

        printf("/ \\");

        for(j = 0; j < n-1; j++)
            printf("%c", symbol);

        printf("\n");
    }

    printf("Figurata e nachertana uspeshno.\n");

    return 0;
}



//
// Created by Admin on 3/12/2026.
//