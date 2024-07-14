// bts.h

#ifndef BTS_H
#define BTS_H

#define ROWS 16
#define COLS 20

// Seat Categories
#define ECONOMY 500
#define TWIN 1000
#define VIP 2000
#define VVIP 5000

typedef struct {
    char showID[20];
    char dramaName[50];
    char startTime[10];
    char date[12];
    char seats[ROWS][COLS];
} TheatreShow;

void initializeSeats(char seats[ROWS][COLS]);
void displayMainMenu();
void addTheatreShow();
void displayTheatreSchedule();
void displayTheatreReservations();
void reserveSeats();
void saveShow(TheatreShow show);
TheatreShow loadShow(char* showID);
void listShows();

#endif
