#include "sense.h"
#include <stddef.h>
#include "scroll.h"
#include <stdio.h>
#include <linux/input.h>
#include <sense.h>
#include <stdlib.h> // For testing purposes

#define BLACK 0x0000
#define WHITE 0xFFFF

void handler(unsigned int code);
pi_joystick_t* joystick = NULL;

void open_input(void) {
    if (joystick == NULL) {
        joystick = getJoystickDevice();
    }
}

void close_input(void) {
    if (joystick != NULL) {
        freeJoystick(joystick);
        joystick = NULL;
    }
}

void check_input(void (*callback)(unsigned int code), int delay) {
    if (joystick != NULL) {
        pollJoystick(joystick, handler, 1000);
    }
    usleep(delay * 1000); // Convert milliseconds to microseconds
}
