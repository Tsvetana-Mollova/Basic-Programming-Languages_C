/*
 *8.	Басейн с обем V(кубични  метра) има две тръби от които се пълни. Всяка
 *тръба има определен дебит (литрите вода минаващи през една тръба за един час).
 *Работникът пуска тръбите едновременно и излиза за N часа. Напишете програма,
 *която изкарва състоянието на басейна, в момента, когато работникът се върне.
*/

#include <stdio.h>

int main() {
    double V;      // обем на басейна в кубични метра
    double P1, P2; // дебит на двете тръби (литри на час)
    double N;      // време в часове

    printf("Vuvedete obema na baseina (v kubichni metra): ");
    scanf("%lf", &V);

    printf("Vuvedete debita na purvata truba (litri na chas): ");
    scanf("%lf", &P1);

    printf("Vuvedete limita na vtorata truba (litri na chas): ");
    scanf("%lf", &P2);

    printf("Vuvedete vremeto, za oeto rabotnikut otsustva (chasove): ");
    scanf("%lf", &N);

    double poolLiters = V * 1000;      // превръщаме m3 в литри
    double water = (P1 + P2) * N;      // общо вода от двете тръби

    if (water <= poolLiters) {
        double percent = (water / poolLiters) * 100;
        double fromP1 = (P1 * N / water) * 100;
        double fromP2 = (P2 * N / water) * 100;

        printf("Baseinut e pulen %.2f%%.\n", percent);
        printf("Prinos na truba 1: %.2f%%\n", fromP1);
        printf("Prinos na truba 2: %.2f%%\n", fromP2);
    }
    else {
        double overflow = water - poolLiters;
        printf("Sled %.2f chasa baseinut preliva s %.2f litra.\n", N, overflow);
    }

    return 0;
}



//
// Created by Admin on 3/12/2026.
//