#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"

void open_display(void);

void close_display(void);

void display_letter(char letter, int xOffset, int yOffset);

void dot_roll(void);

void clear_display(void);

void open_input(void);

void close_input(void);

void check_input(void (*callback)(unsigned int code), int delay);

void handler(unsigned int code);
