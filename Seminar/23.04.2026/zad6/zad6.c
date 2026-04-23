/*
*6.Напишете функция, която проверява дали два низа са анаграма. Функцията има два параметъра ,двата
*низа и връща като резултат 1 ако низовете са анаграма и 0 ако не са.
Пояснение -  анаграма е дума или фраза, образувана от буквите на друга дума или фраза
Например    listen=silent  ,  peach = cheap,   players = parsley
*/

#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[]) {
    int count1[256] = {0};
    int count2[256] = {0};
    int i;

    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)str1[i]]++;
        count2[(unsigned char)str2[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Vuvedete purviq niz: ");
    scanf("%s", str1);

    printf("Vuvedete vtoriq niz: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("Nizovete SA anagrama.\n");
    } else {
        printf("Nizovete NE SA anagrama.\n");
    }

    return 0;
}































//
// Created by Admin on 4/23/2026.
//