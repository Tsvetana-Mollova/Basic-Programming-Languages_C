//2.	Да се прочете от клавиатурата едно целочислено число и да се изведе на
//екрана съобщение,
//ако остатъкът от делението му с 8 е по-голям от 4.

#include <stdio.h>
int main() {
    int number;
    printf("Vuvedete edno celochisleno chislo: ");
    scanf("%d", &number);

    if (number % 8 > 4) {
        printf("Ostatukut ot delenieto e po-golqm ot 4.\n");
    } else {
        printf("Ostatukut ne e po-golqm ot 4.\n");
    }
    return 0;
}
