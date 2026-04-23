/*
8з. Потребителя въвежда 10 числа в динамичен масив. След това въвежда числа, като с всяко въведено число указва индекса, където да бъде вмъкнато това число (числото избутва останалите) . Въвеждането спира при вход 0 .
Примерен вход: 5   1   3   6   2   6   4   7   2   9         // първоначални данни
77  0    //число   позиция     33  2       88  5      0
          Изход: 77   5   33   1   3   88   6   2   6   4   7   2   9
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Greshka pri pametta.\n");
        return 1;
    }

    printf("Vuvedi 10 nachalni chisla:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nVuvedi chislo i poziciq (0 za krai):\n");

    while (1) {
        int x, pos;

        scanf("%d", &x);

        if (x == 0) {
            break;
        }

        scanf("%d", &pos);

        if (pos < 0) pos = 0;
        if (pos > n) pos = n;

        // uvelichavame masiva s 1 element
        int *temp = (int *)realloc(arr, (n + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Greshka pri realloc.\n");
            free(arr);
            return 1;
        }
        arr = temp;

        // izmeстване nadqsno
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = x;
        n++;

        printf("Dobaveno %d na poziciq %d\n", x, pos);
    }

    printf("\nKraen masiv:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    return 0;
}