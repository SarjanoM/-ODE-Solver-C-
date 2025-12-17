#include <stdio.h>
#include "models.h"

void clear(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int validity(int min, int max){
    int readSuccess, choice;
    while (1) {
        readSuccess = scanf("%d", &choice);
        if (readSuccess != 1 || choice < min || choice > max) {
            clear();
            printf("Invalid input, Enter a number: ");
            continue;
        }
        return choice;
    }
}

void population_menu(void) {
    int choice;

    printf("1) Exponential growth\n2) Logistic growth\n");
    choice = validity(1, 2);

    if (choice == 1)
        exponential_growth_solver();
    else
        logistic_growth_solver();
}

void first_order_menu(void) {
    int choice;

    printf("1) RL circuit\n2) Population model\n3) Newton's law of cooling\n");
    choice = validity(1, 3);

    switch (choice) {
        case 1: RL_solver(); break;
        case 2: population_menu(); break;
        case 3: Newton_cooling_solver(); break;
    }
}

void second_order_menu(void) {
    int choice;

    printf("1) LCR circuit\n2) Mass-spring system\n");
    choice = validity(1, 2);

    if (choice == 1)
        LCR_current_finder();
    else
        Mass_spring_finder();
}

int main(void) {
    int choice;

    printf("1) First-order differential equation\n"
           "2) Second-order differential equation\n");

    choice = validity(1, 2);

    if (choice == 1)
        first_order_menu();
    else
        second_order_menu();

    return 0;
}




