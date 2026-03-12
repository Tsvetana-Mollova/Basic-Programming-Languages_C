//Да се напише програма, в която се въвежда цяло число, което представлява код
//на геометрична фигура – 1 – квадрат,
//2 – правоъгълник, 3 – правоъгълен триъгълник, 4 – окръжност.
//След това се въвеждат размерите на избраната геометрична фигура.
//Програмата трябва да изведе типа на геометричната фигура,
//както и нейното лице. За пресмятането на лицето да се напишат подходящи функции

#include <stdio.h>

int kvadrat() {
    float a;
    scanf("Vuvedi strana a: %f\n", a);
    float p = 4 * a;
    float s = a * a;
    printf("Obikolka: %f\n", p);
    printf("Lice: %f\n", s);
}

int main() {
    int n;
    printf("Vuvedi chislo (1-4):\n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            int kv = kvadrat();
            break;
            //case 2:


        default:
            printf("greshka!");
            break;
    }
    return 0;
}
