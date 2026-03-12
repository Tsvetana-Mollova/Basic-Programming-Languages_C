/*5.	Да се прочете от клавиатурата едно число от 1 до 7 и да се изведе
 *на екрана кой ден от седмицата съответства на това число. Да се предвиди
 *случай, когато не е въведено валидно число. */

#include <stdio.h>
int main() {
    int number;
    printf("Vuvedete cifra: ");
    scanf("%d", &number);

    switch (number) {
        case 1:
            printf("Ponedelnik\n");
            break;
        case 2:
            printf("Vtornik\n");
            break;
        case 3:
            printf("Srqda\n");
            break;
        case 4:
            printf("Chetvurtuk\n");
            break;
        case 5:
            printf("Petuk\n");
            break;
        case 6:
            printf("Subota\n");
            break;
        case 7:
            printf("Nedelq\n");
            break;
        default:
            printf("Ne e vuvedeno validno chislo!");
            break;
    }
    return 0;
}