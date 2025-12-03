#include "display_lib.h"

VOID ErrorExit (LPSTR lpszMessage) {
    fprintf(stderr, "%s\n", lpszMessage);
    ExitProcess(0);
}

bool init_console() {
    // Set up the handles for reading/writing:
    w_con_w = GetStdHandle(STD_OUTPUT_HANDLE);
    w_con_r = GetStdHandle(STD_INPUT_HANDLE);

    // https://learn.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions
    if (w_con_r == INVALID_HANDLE_VALUE || w_con_w == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Console Error"), MB_OK);
        return false;
    }

    return true;
}

DWORD clear_console() {
    DWORD mode = 0;

    if (!GetConsoleMode(w_con_w, &mode)) {
        return GetLastError();
    }

    // Hold original mode to restore on exit to be cooperative with other command-line apps.
    const DWORD originalMode = mode;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    DWORD written = 0;
    PCWSTR sequence = L"\x1b[2J";

    if (!WriteConsoleW(w_con_w, sequence, (DWORD)wcslen(sequence), &written, NULL)) {
        // If we fail, try to restore the mode on the way out.
        SetConsoleMode(w_con_w, originalMode);
        return GetLastError();
    }

    SetConsoleMode(w_con_w, originalMode);

    return 0;
}

void close_console() {

}

int non_blocking_input() {
    return 0;
}

// https://learn.microsoft.com/en-us/windows/console/reading-input-buffer-events
int blocking_input() {
    DWORD cNumRead, fdwSaveOldMode, fdwMode;
    INPUT_RECORD irInBuf[128];
    int counter = 0;

    // Save the current input mode, to be restored on exit.
    if (! GetConsoleMode(w_con_r, &fdwSaveOldMode) ) {
        ErrorExit("GetConsoleMode");
    }

    // Enable the window and mouse input events.
    // Disable quick edit mode because it interfers with receiving mouse inputs.
    fdwMode = (ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE;
    if (!SetConsoleMode(w_con_r, fdwMode)) {
        ErrorExit("SetConsoleMode");
    }

    while (counter++ <= 100)
    {
        // Wait for the events.

        if (!ReadConsoleInput(
            w_con_r,      // input buffer handle
            irInBuf,     // buffer to read into
            128,         // size of read buffer
            &cNumRead)) 
        { // number of records read
            ErrorExit("ReadConsoleInput");
        } 
            

        // Dispatch the events to the appropriate handler.
        for (unsigned int i = 0; i < cNumRead; i++) {
            switch(irInBuf[i].EventType) {
                case KEY_EVENT: // keyboard input
                    if(irInBuf[i].Event.KeyEvent.bKeyDown) {
                        SetConsoleMode(w_con_r, fdwSaveOldMode);
                        return irInBuf[i].Event.KeyEvent.wVirtualKeyCode;
                    }
                    break;

                case MOUSE_EVENT: // mouse input
                    //MouseEventProc(irInBuf[i].Event.MouseEvent);
                    break;

                case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
                    //ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
                    break;

                case FOCUS_EVENT:  // disregard focus events
                    break;

                case MENU_EVENT:   // disregard menu events
                    break;

                default:
                    ErrorExit("Unknown event type");
                    break;
            }
        }
    }

    // Restore input mode on exit.

    SetConsoleMode(w_con_r, fdwSaveOldMode);

    return 0;
}

void move_cursor(int x, int y) {

}

void put_char(char chr, int x, int y) {
    COORD coords = {x, y};
    LPDWORD* nb_chr_written = nullptr;

    WriteConsoleOutputCharacter(
    w_con_w, // handle to the console output
    chr, // char to write
    1, // nb chars to write
    coords, //coords to the position
    nb_chr_written// pointer to the actual number of char written to the terminal
    );
}

void put_string(char* message, int x, int y) {

}

void default_colours() {

}

void change_colour(enum Colour colour, enum Plan plan) {
    
}