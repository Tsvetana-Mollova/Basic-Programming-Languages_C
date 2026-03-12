// 7.	Напишете конвертор от градуси в радиани

#include <stdio.h>
int main() {
    double degrees, radians;
    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);
    radians = degrees * (3.14159265358979323846 / 180.0);
    printf("Angle in radians: %6lf\n", radians);

    return 0;
}








//
// Created by Admin on 2/26/2026.
//