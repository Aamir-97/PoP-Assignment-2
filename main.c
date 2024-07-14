// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bts.h"

int main() {
    int choice;
    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addTheatreShow();
                break;
            case 2:
                displayTheatreSchedule();
                break;
            case 3:
                displayTheatreReservations();
                break;
            case 4:
                reserveSeats();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
