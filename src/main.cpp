#include "display_lib/display_lib.h"

#include <iostream>

int main() {
    if(!init_console()) {
        std::cerr << "ERROR: can't open the console." << std::endl;
        return -1;
    }

    int input = ',';
    bool keep_going = true;

    while(keep_going) {
        input = blocking_input();

        put_char(input, 0, 0);
    }

    return 0;
}