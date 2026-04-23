/*
*2.Цецко е програмист и има хоби да прави сладкарски изделия. Помогнете му да напише програма,
*с която да менажира произведените сладка и техните доставки. За целта трябва да създадете
*структура за продукт, която да описва име на продукта, цена и уникален номер. Създайте и структура
*за поръчки, която да описва адрес на клиент и номер на продукт.
От стандартния вход постъпват множество продукти и поръчки. Когато Цецко прави сладко той го добавя
в списък на създадените сладка, а когато се пуска поръчка тя се изпълнява при наличие на продукт,
иначе чака до създаването му.
За входни данни ще получавате две команди:
Product
<име на продукт>
<цена>
<номер на продукта>
Тази команда създава нов продукт и го добавя в списъка с продукти. Ако има поръчка за този продукт
то поръчката се изпълнява незабавно и се маха от чакащите за изпълнение.
Order
<адрес>
<номер на продукт>
Ако има наличен вече произведен продукт се изпълнява поръчката, в противен случай чака за създаване
на продукта.
При всяко изпълнение на поръчка изписвайте: Client <address> ordered <product name>
Програмата приключва работа при въвеждане на команда END
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    float price;
    int id;
    struct Product* next;
} Product;

typedef struct Order {
    char address[100];
    int product_id;
    struct Order* next;
} Order;

void addProduct(Product** products, Order** orders) {
    Product* newProduct = (Product*)malloc(sizeof(Product));

    printf("Vuvedi ime na produkt: ");
    scanf(" %[^\n]", newProduct->name);

    printf("Vuvedi cena: ");
    scanf("%f", &newProduct->price);

    printf("Vuvedi nomer na produkt: ");
    scanf("%d", &newProduct->id);

    newProduct->next = *products;
    *products = newProduct;

    Order* current = *orders;
    Order* prev = NULL;

    while (current != NULL) {
        if (current->product_id == newProduct->id) {
            printf("Client %s ordered %s\n", current->address, newProduct->name);

            if (prev == NULL) {
                *orders = current->next;
            } else {
                prev->next = current->next;
            }

            Order* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

Product* findProduct(Product* products, int id) {
    while (products != NULL) {
        if (products->id == id) {
            return products;
        }
        products = products->next;
    }
    return NULL;
}

void addOrder(Product* products, Order** orders) {
    Order* newOrder = (Order*)malloc(sizeof(Order));

    printf("Vuvedi adres: ");
    scanf(" %[^\n]", newOrder->address);

    printf("Vuvedi nomer na produkt: ");
    scanf("%d", &newOrder->product_id);

    Product* product = findProduct(products, newOrder->product_id);

    if (product != NULL) {
        printf("Client %s ordered %s\n", newOrder->address, product->name);
        free(newOrder);
    } else {
        newOrder->next = *orders;
        *orders = newOrder;
    }
}

int main() {
    Product* products = NULL;
    Order* orders = NULL;

    char command[20];

    while (1) {
        printf("\nVuvedi komanda (Product, Order, END): ");
        scanf("%s", command);

        if (strcmp(command, "Product") == 0) {
            addProduct(&products, &orders);
        } else if (strcmp(command, "Order") == 0) {
            addOrder(products, &orders);
        } else if (strcmp(command, "END") == 0) {
            printf("Krai na programata.\n");
            break;
        } else {
            printf("Nevalidna komanda!\n");
        }
    }

    return 0;
}




































//
// Created by Admin on 4/23/2026.
//