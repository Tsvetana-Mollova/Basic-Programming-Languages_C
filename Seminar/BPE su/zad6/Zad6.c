//6.	Напишете програма, която чете градуси по скалата на Целзий и ги превръща в градуси по Фаренхайт

#include <stdio.h>
int main() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}