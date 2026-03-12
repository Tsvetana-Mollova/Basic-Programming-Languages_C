/*
*7.	Студент трябва да пропътува n километра. Той има избор измежду три вида транспорт:
●	Такси. Начална такса: 0.70 лв. Дневна тарифа: 0.79 лв. / км. Нощна тарифа: 0.90 лв. / км.
●	Автобус. Дневна / нощна тарифа: 0.09 лв. / км. Може да се използва за разстояния
минимум 20 км.
●	Влак. Дневна / нощна тарифа: 0.06 лв. / км. Може да се използва за разстояния минимум 100 км.
Напишете програма, която чете броя километри n и период от деня (ден-D или нощ-N), въведени
от потребителя,  и изчислява цената на най-евтиния транспорт.
*/

#include <stdio.h>

int main()
{
    int n;
    char time;
    double taxi, bus, train, min;

    printf("Vuvedete razstoqnieto v kilometri: ");
    scanf("%d", &n);

    printf("Vuvedete period ot denq (D - den, N - nosht): ");
    scanf(" %c", &time);

    if(time == 'D')
        taxi = 0.70 + n * 0.79;
    else
        taxi = 0.70 + n * 0.90;

    bus = n * 0.09;
    train = n * 0.06;

    min = taxi;

    if(n >= 20 && bus < min)
        min = bus;

    if(n >= 100 && train < min)
        min = train;

    printf("Nai-evtinata cena za putuvane e: %.2f lv.\n", min);

    return 0;
}


//
// Created by Admin on 3/12/2026.
//