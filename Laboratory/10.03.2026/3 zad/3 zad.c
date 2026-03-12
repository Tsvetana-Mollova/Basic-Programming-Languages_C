//3.	Да се прочетат от клавиатурата 3 числа и да се изведе
//на екрана най-малкото от тях.

#include <stdio.h>
int main() {
    int num1, num2, num3;
    printf("Vuvedete 3 chisla: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int min = num1;

    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }
    printf("Nai-malkoto chislo e: %d\n", min);
    return 0;
}