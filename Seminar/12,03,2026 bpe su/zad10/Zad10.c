/*
 *10.	Дадени са n цели числа в интервала [1…1000]. От тях някакъв процент p1
 *са под 200, друг процент p2 са от 200 до 399, друг процент p3 са от 400 до 599,
 *друг процент p4 са от 600 до 799 и останалите p5 процента са от 800 нагоре.
 *Да се напише програма, която изчислява и отпечатва процентите p1, p2, p3, p4 и p5.
*/

#include <stdio.h>

int main() {
    int n, x;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    printf("Vuvedete broq na chislata (n): ");
    scanf("%d", &n);

    printf("Vuvedete %d celi chisla v intervala [1..1000]:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        if(x < 200)
            c1++;
        else if(x <= 399)
            c2++;
        else if(x <= 599)
            c3++;
        else if(x <= 799)
            c4++;
        else
            c5++;
    }

    double p1 = (double)c1 / n * 100;
    double p2 = (double)c2 / n * 100;
    double p3 = (double)c3 / n * 100;
    double p4 = (double)c4 / n * 100;
    double p5 = (double)c5 / n * 100;

    printf("\nRezultati:\n");
    printf("Pod 200: %.2f%%\n", p1);
    printf("Ot 200 do 399: %.2f%%\n", p2);
    printf("Ot 400 do 599: %.2f%%\n", p3);
    printf("Ot 600 do 799: %.2f%%\n", p4);
    printf("800 i nagore: %.2f%%\n", p5);

    return 0;
}



//
// Created by Admin on 3/12/2026.
//