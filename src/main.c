#include <stdio.h>

#include "display_lib/display_lib.h"

int main() {
    if(!init_console()) {
        printf("ERROR: can't open the console.");
        return -1;
    }

    int input = ',';
    bool keep_going = true;

    clear_console();

    while(keep_going) {
        //input = blocking_input();

        put_char('a', 0, 0);
    }

    return 0;
}