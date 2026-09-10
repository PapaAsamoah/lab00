// PID: 730875102
// I pledge the COMP211 honor code.

#include <stdio.h>
#include <stdlib.h>

typedef enum { STATE_NORMAL, STATE_STRING, STATE_COMMENT } State;

int main(void) {
    State state = STATE_NORMAL;
    int c;

    while ((c = getchar()) != EOF) {
        if (state == STATE_NORMAL) {
            if (c == '"') {
                state = STATE_STRING;
                putchar(c);
            } else if (c == '#') {
                state = STATE_COMMENT;
            } else {
                putchar(c);
            }
        } else if (state == STATE_STRING) {
            if (c == '"') {
                state = STATE_NORMAL;
            }
            putchar(c);
        } else {
            if (c == '\n') {
                state = STATE_NORMAL;
                putchar(c);
            }
        }
    }

    return EXIT_SUCCESS;
}
