/*
*8.	Потребителя въвежда 10 числа в масив от 20 елемента. След това въвежда числа,
*като с всяко въведено число указва индекса, където да бъде вмъкнато това число
*(числото избутва останалите) . Въвеждането спира при вход 0 (нула) или при запълване на масива.

Примерен вход: 5   1   3   6   2   6         // първоначални данни
77  0         //число   позиция
33  2
88  5
0
Изход: 77   5   33   1   3   88   6   2   6
*/

#include <stdio.h>

int main() {
    int n;
    printf("Vuvedete razmer na masiva: ");
    scanf("%d", &n);
    int arr[100];
    printf("Vuvedete elementi v masiva: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int number, position;
    while (1)
    {
        printf("Vuvedete chislo i negovata poziciq (0 za krai): ");
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        }
        scanf("%d", &position);

        if (position < 0 || position >= 20)
        {
            printf("Nevalidna positsiya.\n");
            continue;
        }

        for (int i = n; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[position] = number;
        n++;

        if (n >= 20)
        {
            printf("Masiva e pulen. Krai na vuvejdaneto.\n");
            break;
        }
    }

    printf("Finalniya masiv: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}





//
// Created by Admin on 3/26/2026.
//