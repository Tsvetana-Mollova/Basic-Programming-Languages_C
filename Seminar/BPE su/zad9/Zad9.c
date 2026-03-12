// 9.	По въведени параметри за лице на трапец пресметнете лицето му.

#include <stdio.h>

int main(void) {
    double a, b, h, S;

    printf("Vuvedete osnova a: ");
    scanf("%lf", &a);

    printf("Vuvedete osnova b: ");
    scanf("%lf", &b);

    printf("Vuvedete visochina h: ");
    scanf("%lf", &h);

    S = (a + b) * h / 2.0;

    printf("Liceto na trapeca e: %.2f\n", S);

    return 0;
}