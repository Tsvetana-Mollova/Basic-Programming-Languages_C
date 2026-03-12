/*
16.	Иван е програмист в американска компания и работи от вкъщи средно N дни в месеца като изкарва средно по M долара на ден. 
В края на годината Иван получава бонус, който е равен на 2.5 месечни заплати. От спечеленото през годината му се удържат 25% данъци. 
Напишете програма, която да пресмята, колко е чистата средна печалба на Иван на ден в лева, тъй като той харчи изкараното в България. 
Приема се, че в годината има точно 365 дни. Курсът на долара спрямо лева ще се чете от конзолата.
*/

/*
Вход	| Изход
21      |
75.00   |
1.59	| 74.61
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    double M, exchangeRate;

    printf("Enter the average number of days Ivan works from home in a month: ");
    scanf("%d", &N);

    printf("Enter the average amount of money Ivan earns per day in dollars: ");
    scanf("%lf", &M);

    printf("Enter the exchange rate from dollars to leva: ");
    scanf("%lf", &exchangeRate);

    double monthlyEarnings = N * M;
    double annualEarnings = monthlyEarnings * 12;
    double bonus = 2.5 * monthlyEarnings;
    double totalEarnings = annualEarnings + bonus;

    double netEarnings = totalEarnings * 0.75;

    double netEarningsInLeva = netEarnings * exchangeRate;

    double averageDailyProfitInLeva = netEarningsInLeva / 365;

    printf("The average daily profit for Ivan in leva is: %.2lf\n", averageDailyProfitInLeva);

    return 0;
}