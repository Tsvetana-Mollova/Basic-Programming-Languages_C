/*
*5.Напишете програма за компютърен вариант на играта „Бесеница“. В тази игра на играча се показва
*дължината на определена дума( използват се подчертаващи тирета) и той се опитва да отгатне думата
*като въвежда букви. При всяко въвеждане на нова буква се проверява дали думата съдържа тази буква.
*Ако това е така , съответната буква се показва. Бройте буквите , въведени до завършване на думата.
*Играчът печели ако познае думата с въвеждане на брой букви не повече от дължината на търсената дума +2
*или по-малко от този брой.
Например , ако търсената дума е „concatenation“, то броят въведени букви трябва да е по-малък или равен
на 15.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int main() {

    printf("Besenica v C!\n Izberete duma: ");
    char chosenword[100];
    scanf("%s", chosenword);

    //system("cls");

    char secretWord[100];
    strcpy(secretWord, chosenword);
    int length = strlen(secretWord);
    char guessed[100];
    char input;
    int enteredLetters = 0;
    int guessedCount = 0;
    int alreadyUsed;

    for (int i = 0; i < length; i++) {
        guessed[i] = '_';
    }
    guessed[length] = '\0';

    printf("=== Igra Besenitsa ===\n");
    printf("{Poznaite dumata}, kato vuvezhdate po edna bukva.\n");
    printf("Dulzhina na dumata: %d bukvi\n", length);
    printf("Imate pravo na nai-mnogo %d vuvedeni bukvi, za da spechelite.\n\n", length + 2);

    while (guessedCount < length) {
        printf("Tekushto sustoqnie: ");
        for (int i = 0; i < length; i++) {
            printf("%c ", guessed[i]);
        }
        printf("\n");

        printf("Vuvedete bukva: ");
        scanf(" %c", &input);

        input = tolower(input);
        enteredLetters++;
        alreadyUsed = 0;

        for (int i = 0; i < length; i++) {
            if (guessed[i] == input) {
                alreadyUsed = 1;
                break;
            }
        }

        if (alreadyUsed) {
            printf("Tazi bukva veche e poznata.\n\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (secretWord[i] == input && guessed[i] == '_') {
                guessed[i] = input;
                guessedCount++;
                found = 1;
            }
        }

        if (found) {
            printf("Bukvata '%c' se sudurzha v dumata.\n\n", input);
        } else {
            printf("Bukvata '%c' NE se sudurzha v dumata.\n\n", input);
        }
    }

    printf("Pozdravleniq! Poznahte dumata: %s\n", secretWord);
    printf("Obsht broi vuvedeni bukvi: %d\n", enteredLetters);

    if (enteredLetters <= length + 2) {
        printf("Pechelite! Broqt vuvedeni bukvi e <= %d.\n", length + 2);
    } else {
        printf("Ne pechelite, zashtoto vuvedenite bukvi sa poveche ot %d.\n", length + 2);
    }

    return 0;
}































//
// Created by Admin on 4/23/2026.
//