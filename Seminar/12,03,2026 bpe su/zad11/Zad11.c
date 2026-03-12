/*
*11.	Да се напише програма, която прочита от конзолата цяло число n,
*въведено от потребителя, и чертае крепост с ширина 2 * n колони и височина n
*реда като в примерите по-долу. Лявата и дясната колона във вътрешността си са широки n / 2.
вход
3
изход
/^\/^\
|      |
\_/\_/
*/


#include <stdio.h>

int main() {
    int n;

    printf("Vuvedete cqlo chislo n: ");
    scanf("%d", &n);

    int tower = n / 2;
    int middle = 2 * n - 2 * tower - 4;

    // горен ред
    printf("/");
    for(int i = 0; i < tower; i++) printf("^");
    printf("\\");
    for(int i = 0; i < middle; i++) printf("_");
    printf("/");
    for(int i = 0; i < tower; i++) printf("^");
    printf("\\\n");

    // средни редове
    for(int r = 0; r < n - 2; r++) {
        printf("|");
        for(int i = 0; i < 2 * n - 2; i++) printf(" ");
        printf("|\n");
    }

    // долен ред
    printf("\\");
    for(int i = 0; i < tower; i++) printf("_");
    printf("/");
    for(int i = 0; i < middle; i++) printf(" ");
    printf("\\");
    for(int i = 0; i < tower; i++) printf("_");
    printf("/\n");

    return 0;
}


//
// Created by Admin on 3/12/2026.
//