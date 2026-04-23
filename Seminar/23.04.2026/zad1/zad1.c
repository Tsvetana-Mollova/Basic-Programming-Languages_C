/*
*1. Харалампий иска да организира рождения си ден, но за целта трябва да закупи инвентар за
*провеждането, който се изразява в следните предмети:
Стол – 13,99; Маса за 8 човека – 42,00; комплект от 6 чаши – 5,98; комплект от 6 чинии с
прибори – 21,02.
От клавиатурата се въвеждат броя на гостите. Следват редове с неща, които до момента е купил
Харалампий за партито до въвеждане на команда PARTY!. Сметнете колко пари е похарчил до момента
Харалампий и колко още неща трябва да купи за да може да реализира своето парти и всички гости
да имат стол, да седят на маса и да разполагат с чаша и прибори.
Пример:
10
Table
Chair
Chair
Chair
Cups
Cups
Dishes
PARTY!
Изход:
116,95
1 Table
7 Chairs
1 Dishes
(пояснение – поръчаните неща са на стойност 116,95. Има закупена една маса, а за сядането на
10 човека са нужни 2 маси. Има закупени 3 стола – нужни са още 7 за да може всеки да седи на стол.
Приборите, които са нужни са още 4 броя, което значи закупуване на още един комплект).
*/

#include <stdio.h>
#include <string.h>

int main() {
    const double CHAIR_PRICE = 13.99;
    const double TABLE_PRICE = 42.00;
    const double CUPS_PRICE = 5.98;      // комплект от 6 чаши
    const double DISHES_PRICE = 21.02;   // комплект от 6 чинии с прибори

    int guests;
    char item[50];

    int boughtChairs = 0;
    int boughtTables = 0;
    int boughtCupsSets = 0;
    int boughtDishesSets = 0;

    double totalSpent = 0.0;

    printf("Vuvedete broi gosti: ");
    scanf("%d", &guests);

    printf("Vuvezhdaite zakupenite neshta edno po edno (Table, Chair, Cups, Dishes).\n");
    printf("Za krai vuvedete PARTY!\n");

    while (1) {
        printf("Vuvedete artikul: ");
        scanf("%s", item);

        if (strcmp(item, "PARTY!") == 0) {
            break;
        }

        if (strcmp(item, "Chair") == 0) {
            boughtChairs++;
            totalSpent += CHAIR_PRICE;
        }
        else if (strcmp(item, "Table") == 0) {
            boughtTables++;
            totalSpent += TABLE_PRICE;
        }
        else if (strcmp(item, "Cups") == 0) {
            boughtCupsSets++;
            totalSpent += CUPS_PRICE;
        }
        else if (strcmp(item, "Dishes") == 0) {
            boughtDishesSets++;
            totalSpent += DISHES_PRICE;
        }
        else {
            printf("Nevaliden artikul. Opitaite otnovo.\n");
        }
    }

    int neededTables = (guests + 7) / 8;
    int neededChairs = guests;
    int neededCupsSets = (guests + 5) / 6;
    int neededDishesSets = (guests + 5) / 6;

    int moreTables = neededTables - boughtTables;
    int moreChairs = neededChairs - boughtChairs;
    int moreCupsSets = neededCupsSets - boughtCupsSets;
    int moreDishesSets = neededDishesSets - boughtDishesSets;

    if (moreTables < 0) moreTables = 0;
    if (moreChairs < 0) moreChairs = 0;
    if (moreCupsSets < 0) moreCupsSets = 0;
    if (moreDishesSets < 0) moreDishesSets = 0;

    printf("\nDo momenta Haralampii e poharchil: %.2f lv.\n", totalSpent);
    printf("Ostava da kupi:\n");
    printf("%d Table\n", moreTables);
    printf("%d Chairs\n", moreChairs);
    printf("%d Cups\n", moreCupsSets);
    printf("%d Dishes\n", moreDishesSets);

    return 0;
}































//
// Created by Admin on 4/23/2026.
//