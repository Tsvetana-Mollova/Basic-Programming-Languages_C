/*
*7. Да се състави програма на C, която:
•	създава двоичен файл със записи, представляващи данни за сътрудник във фирма: идентификационен
номер на сътрудника, почасово плащане, брой отработени часове за една седмица, седмична заплата;
•	Общият брой на сътрудниците да не превишава 30
•	включва възможност за допълване на нови записи във файла;
•	включва възможност за извеждане на изчислената седмична заплата на екрана. При изчисляване
на работната заплата е необходимо да се знае, че всеки извънреден час (над 40 часа седмично)
се заплаща 150%, а стойността на данъците е 3,65% от общата заработка.
•	включва меню в главната функция main().
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float hourlyPay;
    float workedHours;
    float weeklySalary;
} Employee;

float calculateSalary(float hourlyPay, float workedHours) {
    float grossSalary, netSalary, overtimeHours;

    if (workedHours <= 40) {
        grossSalary = hourlyPay * workedHours;
    } else {
        overtimeHours = workedHours - 40;
        grossSalary = (40 * hourlyPay) + (overtimeHours * hourlyPay * 1.5f);
    }

    netSalary = grossSalary - (grossSalary * 0.0365);
    return netSalary;
}

int countEmployees() {
    FILE *fp;
    Employee emp;
    int count = 0;

    fp = fopen("employees.bin", "rb");
    if (fp == NULL) {
        return 0;   // ако файлът още не съществува
    }

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        count++;
    }

    fclose(fp);
    return count;
}

void createFile() {
    FILE *fp;
    int n, i;
    Employee emp;

    fp = fopen("employees.bin", "wb");
    if (fp == NULL) {
        printf("Greshka pri suzdavane na faila!\n");
        return;
    }

    printf("Kolko sutrudnika iskate da vuvedete (maksimum %d): ", 30);
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("Nevaliden broi sutrudnici!\n");
        fclose(fp);
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Vuvezhdane na danni za sutrudnik %d ---\n", i + 1);

        printf("Identifikacionen nomer: ");
        scanf("%d", &emp.id);

        printf("Pochasovo zaplashtane: ");
        scanf("%f", &emp.hourlyPay);

        printf("Broi otraboteni chasove za sedmicata: ");
        scanf("%f", &emp.workedHours);

        emp.weeklySalary = calculateSalary(emp.hourlyPay, emp.workedHours);

        fwrite(&emp, sizeof(Employee), 1, fp);
    }

    fclose(fp);
    printf("\nFailut e suzdaden uspeshno.\n");
}

void appendRecords() {
    FILE *fp;
    int currentCount, n, i;
    Employee emp;

    currentCount = countEmployees();

    if (currentCount >= 30) {
        printf("Failut veche sudurzha maksimalniq broi sutrudnici (%d).\n", 30);
        return;
    }

    fp = fopen("employees.bin", "ab");
    if (fp == NULL) {
        printf("Greshka s faila!\n");
        return;
    }

    printf("Vuv Faila ima %d rabotnika.\n", currentCount);
    printf("Kolko novi rabotnika iskate da dobavite: ");
    scanf("%d", &n);

    if (n < 1 || currentCount + n > 30) {
        printf("Greshka! Tova e poveche ot %d.\n", 30);
        fclose(fp);
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Vuvedete danni za noviq rabotnik %d ---\n", i + 1);

        printf("id nomer: ");
        scanf("%d", &emp.id);

        printf("nadnika na chas: ");
        scanf("%f", &emp.hourlyPay);

        printf("Zaraboteni chasove za sedmicata: ");
        scanf("%f", &emp.workedHours);

        emp.weeklySalary = calculateSalary(emp.hourlyPay, emp.workedHours);

        fwrite(&emp, sizeof(Employee), 1, fp);
    }

    fclose(fp);
    printf("\nZapisa e dobaven uspeshno.\n");
}

/* Извеждане на седмичните заплати */
void displaySalaries() {
    FILE *fp;
    Employee emp;
    int count = 0;

    fp = fopen("employees.bin", "rb");
    if (fp == NULL) {
        printf("Ne susshtestvuva!\n");
        return;
    }

    printf("\n===== Spisuk s vskichi rabotnici =====\n");

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("\nRabotnik #%d\n", count + 1);
        printf("id nomer: %d\n", emp.id);
        printf("Nadnik/chas: %.2f lv.\n", emp.hourlyPay);
        printf("Chasove na rabota: %.2f\n", emp.workedHours);
        printf("Sedmichna zaplata: %.2f lv.\n", emp.weeklySalary);
        count++;
    }

    if (count == 0) {
        printf("Prazno.\n");
    }

    fclose(fp);
}

/* Главна функция с меню */
int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("        Menu\n");
        printf("========================================\n");
        printf("1. Suzdavane na .bin fail\n");
        printf("2. Dobavi nov zapis\n");
        printf("3. Spisuk s slujiteli\n");
        printf("0. Izhod\n");
        printf("========================================\n");
        printf("Izberete opciq: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                appendRecords();
                break;
            case 3:
                displaySalaries();
                break;
            case 0:
                printf("Izhod...\n");
                break;
            default:
                printf("Nevalidnen izbor! Opitaj pak.\n");
        }

    } while (choice != 0);

    return 0;
}































//
// Created by Admin on 4/23/2026.
//