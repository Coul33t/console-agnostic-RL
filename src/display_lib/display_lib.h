#ifndef __DISPLAY_LIB_H__
#define __DISPLAY_LIB_H__

#ifdef _WIN32
    #include <windows.h>
    #include <Tchar.h>

    // if SDK is too old, define it 
    // https://stackoverflow.com/questions/38772468/setconsolemode-and-enable-virtual-terminal-processing
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif

    HANDLE w_con_w; // Handle to write to the console
    HANDLE w_con_r; // Handle to read from the console  

    VOID ErrorExit(LPSTR); 
#endif

#ifdef __unix__
    #define DWORD unsigned long;
    #include <ncurses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "display_constants.h"

bool init_console();
DWORD clear_console();
void close_console();

int non_blocking_input();
int blocking_input();

void move_cursor(int x, int y);

void put_char(char chr, int x, int y);
void put_string(char* message, int x, int y);

void default_colours();
void change_colour(enum Colour colour, enum Plan plan);

#endif