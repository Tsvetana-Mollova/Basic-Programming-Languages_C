// 8.	Напишете конвертор от левове в долари, евро и паундове

#include <stdio.h>
int main() {
    double lev, dolars, euros, pounds;
    printf("Enter amount in levs: ");
    scanf("%lf", &lev);
    dolars = lev * 0.56;
    euros = lev * 0.51;
    pounds = lev * 0.45;
    printf("Amount in dolars: %.2lf\n", dolars);
    printf("Amount in euroes: %.2lf\n", euros);
    printf("Amount in pounds: %.2lf\n", pounds);
    return 0;
}






//
// Created by Admin on 2/26/2026.
//