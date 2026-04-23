/*
*3.Имате текстов файл, в който имате думи (на английски език и не повече от 50 знака).
Прочетете думите, и в динамичен масив запишете тези думи, които започват с последния знак на предходната
дума(думите се гледат поред, записва за първата дума от файла след което се записва първата която се
срещне и отговаря на условието и т.н).
В бинарен файл запишете така направения масив от думи.
Направете  възможност за изкарване на екрана съдържанието на бинарния файл.

изход на файла input.txt:   apple  car price elephant head tire cool soft eleven output night tent
story  movies  pleasure memory  time search  shortcut  river  compare evening
apple elephant tire eleven night tent time evening

Пояснение - думите в бинарния файла за разделени със знака “ ” (интервал).
Използвайте  го за разделител и четете знак по знак.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **words;
    int size;
    int capacity;
} DynamicArray;

const char *inputFileName = "input.txt";
const char *binaryFileName = "output.bin";

void initArray(DynamicArray *arr) {
    arr->size = 0;
    arr->capacity = 4;
    arr->words = (char **)malloc(arr->capacity * sizeof(char *));
    if (arr->words == NULL) {
        printf("Greshka pri zadelqne na pamet!\n");
        exit(1);
    }
}

void addWord(DynamicArray *arr, const char *word) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->words = (char **)realloc(arr->words, arr->capacity * sizeof(char *));
        if (arr->words == NULL) {
            printf("Greshka pri preorazmerqvane na pametta!\n");
            exit(1);
        }
    }

    arr->words[arr->size] = (char *)malloc((strlen(word) + 1) * sizeof(char));
    if (arr->words[arr->size] == NULL) {
        printf("Greshka pri zadelqne na pamet za duma!\n");
        exit(1);
    }

    strcpy(arr->words[arr->size], word);
    arr->size++;
}

void freeArray(DynamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        free(arr->words[i]);
    }
    free(arr->words);
}

int startsWithLastChar(const char *previous, const char *current) {
    int lenPrev = strlen(previous);
    if (lenPrev == 0 || strlen(current) == 0) {
        return 0;
    }

    char lastChar = previous[lenPrev - 1];
    char firstChar = current[0];

    return lastChar == firstChar;
}

void readWordsAndBuildArray(const char *inputFileName, DynamicArray *arr) {
    FILE *fp = fopen(inputFileName, "r");
    if (fp == NULL) {
        printf("Ne moje da se otvori failut %s\n", inputFileName);
        exit(1);
    }

    char currentWord[51];
    int index = 0;
    int ch;
    int firstSelected = 1;
    char lastSelectedWord[51] = "";

    printf("Chetene na dumite ot faila %s ...\n", inputFileName);

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r') {
            if (index < 50) {
                currentWord[index++] = (char)ch;
            }
        } else {
            if (index > 0) {
                currentWord[index] = '\0';

                if (firstSelected) {
                    addWord(arr, currentWord);
                    strcpy(lastSelectedWord, currentWord);
                    firstSelected = 0;
                    printf("Dobavena purva duma: %s\n", currentWord);
                } else if (startsWithLastChar(lastSelectedWord, currentWord)) {
                    addWord(arr, currentWord);
                    strcpy(lastSelectedWord, currentWord);
                    printf("Dobavena duma po uslovie: %s\n", currentWord);
                }

                index = 0;
            }
        }
    }

    if (index > 0) {
        currentWord[index] = '\0';

        if (firstSelected) {
            addWord(arr, currentWord);
            strcpy(lastSelectedWord, currentWord);
            printf("Dobavena puva duma: %s\n", currentWord);
        } else if (startsWithLastChar(lastSelectedWord, currentWord)) {
            addWord(arr, currentWord);
            strcpy(lastSelectedWord, currentWord);
            printf("Dobavena duma po uslovie: %s\n", currentWord);
        }
    }

    fclose(fp);
}

void writeBinaryFile(const char *binaryFileName, DynamicArray *arr) {
    FILE *fp = fopen(binaryFileName, "wb");
    if (fp == NULL) {
        printf("Ne moje da se suzdade binarniqt fail %s\n", binaryFileName);
        exit(1);
    }

    printf("\nZaps v binarniq fail %s ...\n", binaryFileName);

    for (int i = 0; i < arr->size; i++) {
        fwrite(arr->words[i], sizeof(char), strlen(arr->words[i]), fp);

        if (i < arr->size - 1) {
            char space = ' ';
            fwrite(&space, sizeof(char), 1, fp);
        }
    }

    fclose(fp);
    printf("Zapisut prikluchi uspeshno.\n");
}

void printBinaryFile(const char *binaryFileName) {
    FILE *fp = fopen(binaryFileName, "rb");
    if (fp == NULL) {
        printf("Ne moje da se otvori binarniqt fail %s\n", binaryFileName);
        return;
    }

    printf("\nSudurjanie na binarniq fail %s:\n", binaryFileName);

    char ch;
    while (fread(&ch, sizeof(char), 1, fp) == 1) {
        printf("%c", ch);
    }

    printf("\n");
    fclose(fp);
}

int main() {

    DynamicArray arr;
    initArray(&arr);

    printf("=== PROGRAMA ZA OBRABOTKA NA DUMI OT FAIL ===\n\n");

    readWordsAndBuildArray(inputFileName, &arr);

    printf("\nPolucheniqt masiv ot dumi e:\n");
    for (int i = 0; i < arr.size; i++) {
        printf("%s ", arr.words[i]);
    }
    printf("\n");

    writeBinaryFile(binaryFileName, &arr);

    printBinaryFile(binaryFileName);

    freeArray(&arr);

    printf("\nProgramata zavurshi uspeshno.\n");
    return 0;
}






























//
// Created by Admin on 4/23/2026.
//