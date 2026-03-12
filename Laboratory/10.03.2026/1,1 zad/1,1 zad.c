/*1.	Да се напише програма, която прочита от клавиатурата едно цяло
число и изкарва числова пирамида:
1
2 2
3 3 3
.....  */

#include <stdio.h>
int main(){
    int number;

    printf("Vuvedete polozhitelno chislo: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}