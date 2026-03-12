/*
*5.	Трима спортни състезатели финишират за някакъв брой секунди (между 1 и 50).
*Да се напише програма, която чете времената на състезателите, въведени от потребителя,
*и пресмята сумарното им време във формат "минути:секунди". Секундите да се изведат
*с водеща нула (2 🡪 "02", 7 🡪 "07", 35 🡪 "35"). Примери:
вход	изход		вход	изход		вход	изход		вход	изход
35
45
44	2:04		22
7
34	1:03		50
50
49	2:29		14
12
10	0:36
*/

#include <stdio.h>

int main() {
    int t1, t2, t3;
    int total, minutes, seconds;

    printf("Vuvedete vremeto na purviq sustezatel (v sekundi): ");
    scanf("%d", &t1);

    printf("Vuvedete vremeto na vtoriq sustezatel (v sekundi): ");
    scanf("%d", &t2);

    printf("Vuvedete vremeto na tretiq sustezatel (v sekundi): ");
    scanf("%d", &t3);

    total = t1 + t2 + t3;

    minutes = total / 60;
    seconds = total % 60;

    printf("Obshtoto vreme e: %d:%02d\n", minutes, seconds);

    return 0;
}

//
// Created by Admin on 3/12/2026.
//