#ifndef __DISPLAY_LIB_H__
#define __DISPLAY_LIB_H__

#ifdef _WIN32
    #include <stdlib.h>
    #include <Windows.h>
    #include <Tchar.h>

    HANDLE w_con_w; // Handle to write to the console
    HANDLE w_con_r; // Handle to read from the console   
#endif

#ifdef __unix__
    #include <ncurses.h>
#endif

#include "display_constants.h"

bool init_console();
void clear_console();
void close_console();

int non_blocking_input();
int blocking_input();

void move_cursor(int x, int y);

void put_char(char chr, int x, int y);
void put_string(char* message, int x, int y);

void default_colours();
void change_colour(Colour colour, Plan plan);

#endif