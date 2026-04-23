/*
 *4.Напишете програма , която кодира информацията в текстов файл символ по символ с ключ въведен
 *от потребителя и записва кодираното съдържание в друг файл. Ключът е цяло число между 2 и 10.
 *Името на файла, който ще бъде кодиран се чете от клавиатурата.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inFile, *outFile;
    char inputFileName[100], outputFileName[100];
    int key;
    char ch;

    printf("Vuvedete imeto na faila za kodirane: ");
    scanf("%s", inputFileName);

    printf("Vuvedete imeto na faila za zapis na kodiranata informaciq: ");
    scanf("%s", outputFileName);

    printf("Vuvedete kluch (cqlo chislo mezdu 2 i 10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10) {
        printf("Greshka: Kluchut trqbva e mezhdu 2 i 10!\n");
        return 1;
    }

    inFile = fopen(inputFileName, "r");
    if (inFile == NULL) {
        printf("Greshka pri otvarqne na vhodniq fail!\n");
        return 1;
    }

    outFile = fopen(outputFileName, "w");
    if (outFile == NULL) {
        printf("Greshka pri suzdavane na izhodniq fail!\n");
        fclose(inFile);
        return 1;
    }

    printf("Kodiraneto zapochna...\n");

    while ((ch = fgetc(inFile)) != EOF) {
        char encoded = ch + key;
        fputc(encoded, outFile);
    }

    printf("Kodiraneto zavurshi uspeshno!\n");

    fclose(inFile);
    fclose(outFile);

    return 0;
}






























//
// Created by Admin on 4/23/2026.
//