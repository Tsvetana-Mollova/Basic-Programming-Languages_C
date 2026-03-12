/*
 *6.	Напишете програма, която проверява дали точка {x, y} се намира вътре
 *в правоъгълник {x1, y1} – {x2, y2}. Входните данни се четат от конзолата и се
 *състоят от 6 реда, въведени от потребителя: десетичните числа x1, y1, x2, y2,
 *x и y (като се гарантира, че x1 < x2 и y1 < y2). Една точка е вътрешна за даден
 *правоъгълник, ако се намира някъде във вътрешността му или върху някоя от страните
 *му. Отпечатайте “Inside” или “Outside”.
 */

#include <stdio.h>

int main() {

    double x1, y1, x2, y2;
    double x, y;

    printf("x1 = ");
    scanf("%lf", &x1);

    printf("y1 = ");
    scanf("%lf", &y1);

    printf("x2 = ");
    scanf("%lf", &x2);

    printf("y2 = ");
    scanf("%lf", &y2);

    printf("x = ");
    scanf("%lf", &x);

    printf("y = ");
    scanf("%lf", &y);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        printf("Inside");
    else
        printf("Outside");

    return 0;
}

//
// Created by Admin on 3/12/2026.
//