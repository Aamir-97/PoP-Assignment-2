// bts.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bts.h"

void initializeSeats(char seats[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            seats[i][j] = '*';
        }
    }
}

void displayMainMenu() {
    printf("\n--- ByScope Theatre System ---\n");
    printf("1. Add Theatre Show\n");
    printf("2. Display Theatre Schedule\n");
    printf("3. Display Theatre Reservations\n");
    printf("4. Reserve Seats\n");
    printf("5. Exit\n");
}

void addTheatreShow() {
    TheatreShow show;
    printf("Enter Show ID: ");
    scanf("%s", show.showID);
    printf("Enter Drama Name: ");
    scanf("%s", show.dramaName);
    printf("Enter Start Time (HH:MM): ");
    scanf("%s", show.startTime);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", show.date);
    initializeSeats(show.seats);
    saveShow(show);
    printf("Theatre Show added successfully.\n");
}

void displayTheatreSchedule() {
    listShows();
}

void displayTheatreReservations() {
    char showID[20];
    printf("Enter Show ID: ");
    scanf("%s", showID);
    TheatreShow show = loadShow(showID);
    if (strlen(show.showID) == 0) {
        printf("Show not found.\n");
        return;
    }
    printf("\nSeating Layout for Show ID: %s\n", show.showID);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", show.seats[i][j]);
        }
        printf("\n");
    }
}

void reserveSeats() {
    char showID[20];
    int numSeats;
    char seatCategory[10];
    printf("Enter Show ID: ");
    scanf("%s", showID);
    TheatreShow show = loadShow(showID);
    if (strlen(show.showID) == 0) {
        printf("Show not found.\n");
        return;
    }
    printf("Enter number of seats to reserve: ");
    scanf("%d", &numSeats);
    printf("Enter seat category (ECONOMY, TWIN, VIP, VVIP): ");
    scanf("%s", seatCategory);

    // Implement the reservation logic here

    saveShow(show);
    printf("Seats reserved successfully.\n");
}

void saveShow(TheatreShow show) {
    FILE *file = fopen("show_schedules.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", show.showID, show.dramaName, show.startTime, show.date);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%c", show.seats[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

TheatreShow loadShow(char* showID) {
    TheatreShow show = {0};
    FILE *file = fopen("show_schedules.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return show;
    }
    while (fscanf(file, "%[^,],%[^,],%[^,],%s\n", show.showID, show.dramaName, show.startTime, show.date) != EOF) {
        if (strcmp(show.showID, showID) == 0) {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    fscanf(file, "%c", &show.seats[i][j]);
                }
                fgetc(file);  // Read the newline character
            }
            break;
        }
    }
    fclose(file);
    return show;
}

void listShows() {
    TheatreShow show;
    FILE *file = fopen("show_schedules.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Show Schedule:\n");
    while (fscanf(file, "%[^,],%[^,],%[^,],%s\n", show.showID, show.dramaName, show.startTime, show.date) != EOF) {
        printf("Show ID: %s, Drama: %s, Time: %s, Date: %s\n", show.showID, show.dramaName, show.startTime, show.date);
    }
    fclose(file);
}
