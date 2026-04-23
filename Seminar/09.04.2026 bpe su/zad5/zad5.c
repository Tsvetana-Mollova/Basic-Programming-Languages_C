/*
5з. Наум пише софтуер за малки деца, който има следните команди:
1: add(x) - добавяне на елемент Х към съществуващите до момента
2: delete(x) – изтрива всички срещания на елемента Х
3: smallest(x)  принтира Х тото най-малко число от наличните
Помогнете на Наум да напише своя софтуер, ако знаете, че Х е цяло число.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 100000;
    int *arr = (int *)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        printf("Greshka pri pametta.\n");
        return 1;
    }

    int n = 0;
    int q;

    printf("Vuvedi broi komandi: ");
    scanf("%d", &q);

    printf("Komandi:\n1 x  -> add(x)\n2 x  -> delete(x)\n3 x  -> smallest(x)\n");

    for (int i = 0; i < q; i++) {
        int cmd, x;

        printf("\nVuvedi komanda i chislo: ");
        scanf("%d %d", &cmd, &x);

        if (cmd == 1) {
            if (n < capacity) {
                arr[n++] = x;
                printf("Dobaveno %d\n", x);
            }
        }
        else if (cmd == 2) {
            int j = 0;
            for (int k = 0; k < n; k++) {
                if (arr[k] != x) {
                    arr[j++] = arr[k];
                }
            }
            n = j;
            printf("Iztrito.\n");
        }
        else if (cmd == 3) {
            if (x < 1 || x > n) {
                printf("Nqma takova chislo.\n");
            } else {
                int *temp = (int *)malloc(n * sizeof(int));

                for (int k = 0; k < n; k++) {
                    temp[k] = arr[k];
                }

                for (int a = 0; a < n - 1; a++) {
                    for (int b = 0; b < n - a - 1; b++) {
                        if (temp[b] > temp[b + 1]) {
                            int t = temp[b];
                            temp[b] = temp[b + 1];
                            temp[b + 1] = t;
                        }
                    }
                }

                printf("%d-to nai-malko chislo e: %d\n", x, temp[x - 1]);

                free(temp);
            }
        }
    }

    free(arr);
    return 0;
}