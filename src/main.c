#include <stdio.h>

#include "display_lib/display_lib.h"

int main() {
    if(!init_console()) {
        printf("ERROR: can't open the console.");
        return -1;
    }

    int input = ',';
    bool keep_going = true;

    put_char('a', 10, 10);

    clear_console();

    put_char('b', 10, 10);

    while(keep_going) {
        //input = blocking_input();

        put_char('c', 10, 10);
    }

    printf("Wtf");

    return 0;
}