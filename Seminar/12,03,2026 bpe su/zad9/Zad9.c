/*
*9.	От лозе с площ X квадратни метри се заделя 40% от реколтата за производство
*на вино. От 1 кв.м лозе се изкарват Y килограма грозде. За 1 литър вино са
*нужни 2,5 кг. грозде. Желаното количество вино за продан е Z литра.
Напишете програма, която пресмята колко вино може да се произведе и дали това
количество е достатъчно. Ако е достатъчно, остатъкът се разделя по равно между
работниците на лозето.
*/

#include <stdio.h>

int main() {
    double X, Y, Z;
    int N;

    printf("Vuvedete ploshtta na lozeto v kvadratni metri (X): ");
    scanf("%lf", &X);

    printf("Vuvedete kilogrami grozde ot 1 kv.m (Y): ");
    scanf("%lf", &Y);

    printf("Vuvedete jelanoto kolichestvo vino za prodan v litri (Z): ");
    scanf("%lf", &Z);

    printf("Vuvedete broi rabotnici (N): ");
    scanf("%d", &N);

    double grapes = X * Y;
    double grapes_for_wine = grapes * 0.40;
    double wine = grapes_for_wine / 2.5;

    if (wine < Z) {
        printf("Ne stiga vino. Trqbvat oshte %.2f litra.\n", Z - wine);
    } else {
        double remaining = wine - Z;
        double per_worker = remaining / N;

        printf("Dostatuchno vino!\n");
        printf("Obshto proizvedeno vino: %.2f litra\n", wine);
        printf("Ostatuk sled prodan: %.2f litra\n", remaining);
        printf("Po %.2f litra za vseki rabotnik\n", per_worker);
    }

    return 0;
}



//
// Created by Admin on 3/12/2026.
//