#ifndef __DISPLAY_CONSTANTS_H__
#define __DISPLAY_CONSTANTS_H__

// -------------------
// ----- COLOURS -----
// -------------------
enum Colour {
    DEFAULT, RED, GREEN, BLUE, YELLOW
};

enum Plan {
    BACK, FORE
};

#define DEFAULT_COLOURS 1

#define RED_FOREGROUND 2
#define RED_BACKGROUND 3

#define YELLOW_FOREGROUND 4
#define YELLOW_BACKGROUND 5

#define BLUE_FOREGROUND 6
#define BLUE_BACKGROUND 7

#define GREEN_FOREGROUND 8
#define GREEN_BACKGROUND 9
// -------------------

// ------------------------
// ----- CONSOLE SIZE -----
// ------------------------
#define CONSOLE_X_SIZE 80
#define CONSOLE_Y_SIZE 24
// -------------------
#endif