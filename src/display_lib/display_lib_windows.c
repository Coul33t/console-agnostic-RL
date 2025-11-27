#include "display_lib.h"

bool init_console() {
    // Set up the handles for reading/writing:
    w_con_w = GetStdHandle(STD_OUTPUT_HANDLE);
    w_con_r = GetStdHandle(STD_INPUT_HANDLE);

    // https://learn.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions
    if (w_con_r == INVALID_HANDLE_VALUE || w_con_w == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Console Error"),
            MB_OK);
        return 1;
    }

    

}

void clear_console() {

}

void close_console() {

}

void non_blocking_input() {

}

void blocking_input() {

}

void move_cursor(int x, int y) {

}

void put_char(char chr, int x, int y) {

}

void put_string(char* message, int x, int y) {

}

void default_colours() {

}

void change_colour(Colour colour, Plan plan) {
    
}