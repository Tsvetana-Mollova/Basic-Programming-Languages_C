//1.	Да се прочете от клавиатурата едно целочислено число
//и да се изведе съобщение, ако то е по-голямо от 6.
#include <stdio.h>
int main()
{
    int number;
    printf("Vuvedete edno celochisleno chislo");
    scanf("%d", &number);

    if (number > 6) {
        printf("Chisloto e po-golqmo ot 6.\n");
    } else {
        printf("Chisloto ne e po-golqmo ot 6.\n");
    }
    return 0;
}