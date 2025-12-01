#include "display_lib.h"

bool init_console() {
    // Starts ncurse
    WINDOW* win = nullptr;
    win = initscr();

    // Prevent from immediately drawing on screen
    noecho();

    // Invisible cursor
    curs_set(0);

    if (has_colors()) {
        start_color();

        /* 1 */ init_pair(DEFAULT_COLOURS, COLOR_WHITE, COLOR_BLACK);

        /* 2 */ init_pair(RED_FOREGROUND, COLOR_RED, COLOR_BLACK);
        /* 3 */ init_pair(RED_BACKGROUND, COLOR_BLACK, COLOR_RED);

        /* 4 */ init_pair(YELLOW_FOREGROUND, COLOR_YELLOW, COLOR_BLACK);
        /* 5 */ init_pair(YELLOW_FOREGROUND, COLOR_BLACK, COLOR_YELLOW);

        /* 6 */ init_pair(BLUE_FOREGROUND, COLOR_BLUE, COLOR_BLACK);
        /* 7 */ init_pair(BLUE_BACKGROUND, COLOR_BLACK, COLOR_BLUE);

        /* 6 */ init_pair(GREEN_FOREGROUND, COLOR_GREEN, COLOR_BLACK);
        /* 7 */ init_pair(GREEN_BACKGROUND, COLOR_BLACK, COLOR_GREEN);
    }

    else {
        addstr("WARNING! Your console does not support colours.");
        getch();
        // TODO: print message
    }

    return (win != nullptr);
}

void clear_console() {
    erase();
}

void close_console() {
    endwin();
}

int non_blocking_input() {
    timeout(0);
    return getch();
}

int blocking_input() {
    timeout(-1);
    return getch();
}

void move_cursor(int x, int y) {
    move(y, x);
}

void put_char(char chr, int x, int y) {
    mvaddch(y, x, chr);
}

void put_string(char* message, int x, int y) {
    move_cursor(x, y);
    printw("%s", message);
}

void colour_defaut() {
    attron(COLOR_PAIR(DEFAULT_COLOURS));
}

void change_colour(enum Colour colour, enum Plan plan) {
    if (colour == DEFAULT) {
        attron(COLOR_PAIR(DEFAULT_COLOURS));
    }

    else if (colour == RED) {
        if (plan == FORE) {
            attron(COLOR_PAIR(RED_BACKGROUND));
        } 
        
        else {
            attron(COLOR_PAIR(RED_FOREGROUND));
        }
    }

    else if (colour == GREEN) {
        if (plan == FORE) {
            attron(COLOR_PAIR(GREEN_BACKGROUND));
        } 
        
        else {
            attron(COLOR_PAIR(GREEN_FOREGROUND));
        }
    }

    else if (colour == BLUE) {
        if (plan == FORE) {
            attron(COLOR_PAIR(BLUE_BACKGROUND));
        } 
        
        else {
            attron(COLOR_PAIR(BLUE_FOREGROUND));
        }
    }

    
    else if (colour == YELLOW) {
        if (plan == FORE) {
            attron(COLOR_PAIR(YELLOW_BACKGROUND));
        } 
        
        else {
            attron(COLOR_PAIR(YELLOW_FOREGROUND));
        }
    }
}