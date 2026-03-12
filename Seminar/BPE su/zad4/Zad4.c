// 4.	Направете програма, която рисува триъгълник с въведен знак от потребителя:
// вход: §
// изход:
//             §
//          §    §
//       §          §
//    §                §
// § § § § § § § § §
//
// Направете триъгълника и наобратно

#include <stdio.h>
int main() {
        char symbol;
        int height = 5;

        printf("Enter symbol: ");
        scanf(" %c", &symbol);

        printf("\nUpright:\n");
        for (int i = 1; i <= height; i++) {

            for (int j = 1; j <= height - i; j++) {
                printf(" ");
            }

            for (int j = 1; j <= (2 * i - 1); j++) {
                if (j == 1 || j == (2 * i - 1) || i == height) {
                    printf("%c", symbol);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("\nInverted:\n");
        for (int i = height; i >= 1; i--) {
            // Print leading spaces
            for (int j = 1; j <= height - i; j++) {
                printf(" ");
            }

            for (int j = 1; j <= (2 * i - 1); j++) {
                if (j == 1 || j == (2 * i - 1) || i == height) {
                    printf("%c", symbol);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        return 0;
    }