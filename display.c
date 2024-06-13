#include "scroll.h"
#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#define BLACK 0x0000
#define WHITE 0xFFFF
#include "sense.h"

// Global variable to store the Pi Framebuffer device
pi_framebuffer_t *fb = NULL;
void open_display(void) {
    // Allocate the Pi Framebuffer device
    if(fb == NULL) {
        fb = getFrameBuffer();
    }
}

// Function to deallocate the Pi Framebuffer device
void close_display(void) {
    // Deallocate the Pi Framebuffer device
        if(fb != NULL){
        clearFrameBuffer(fb,BLACK);
        sleep(1);
//        printf("Framebuffer freed.\n");
        freeFrameBuffer(fb);
        fb = NULL;
    }
}



void display_letter(char letter, int xOffset, int yOffset) {
	sense_fb_bitmap_t *bm=fb->bitmap;
//    clearFrameBuffer(fb,BLACK);
//    fb->bitmap->pixel[yOffset][xOffset] = WHITE;
    xOffset = (xOffset + 8) % 8;
    yOffset = (yOffset + 8) % 8;
    // Clear previous dot at (xOffset, yOffset)
//    clear_display();
     clearFrameBuffer(fb,BLACK);

	if((letter == 'm' || letter == 'M')&& fb!= NULL){
	bm->pixel[0][1]=WHITE;
	bm->pixel[0][2]=WHITE;
    	bm->pixel[0][3]=WHITE;
    	bm->pixel[0][4]=WHITE;
    	bm->pixel[0][5]=WHITE;
    	bm->pixel[0][6]=WHITE;
    	bm->pixel[0][7]=WHITE;
    	bm->pixel[1][2]=WHITE;
    	bm->pixel[2][3]=WHITE;
    	bm->pixel[3][4]=WHITE;
    	bm->pixel[4][4]=WHITE;
    	bm->pixel[5][3]=WHITE;
    	bm->pixel[7][1]=WHITE;
    	bm->pixel[7][2]=WHITE;
    	bm->pixel[7][3]=WHITE;
    	bm->pixel[7][4]=WHITE;
    	bm->pixel[7][5]=WHITE;
    	bm->pixel[7][6]=WHITE;
    	bm->pixel[7][7]=WHITE;
    	bm->pixel[6][2]=WHITE;

	} else if ((letter == 'p' || letter == 'P')&& fb != NULL) {
	bm->pixel[6][0]=WHITE;
        bm->pixel[5][0]=WHITE;
        bm->pixel[4][0]=WHITE;
        bm->pixel[3][0]=WHITE;
        bm->pixel[7][0]=WHITE;
        bm->pixel[7][1]=WHITE;
        bm->pixel[7][2]=WHITE;
        bm->pixel[7][3]=WHITE;
        bm->pixel[7][4]=WHITE;
        bm->pixel[7][5]=WHITE;
        bm->pixel[7][6]=WHITE;
        bm->pixel[7][7]=WHITE;
        bm->pixel[3][1]=WHITE;
        bm->pixel[3][2]=WHITE;
        bm->pixel[3][3]=WHITE;
        bm->pixel[3][4]=WHITE;
        bm->pixel[4][4]=WHITE;
        bm->pixel[5][4]=WHITE;
        bm->pixel[6][4]=WHITE;

	} else if ((letter == 'e' || letter == 'E')&& fb != NULL) {
	bm->pixel[7][0] = WHITE;
	bm->pixel[6][0] = WHITE;
 	bm->pixel[5][0] = WHITE;
 	bm->pixel[4][0] = WHITE;
 	bm->pixel[3][0] = WHITE;
 	bm->pixel[7][1] = WHITE;
 	bm->pixel[7][2] = WHITE;
 	bm->pixel[7][3] = WHITE;
 	bm->pixel[7][4] = WHITE;
 	bm->pixel[6][4] = WHITE;
 	bm->pixel[5][4] = WHITE;
 	bm->pixel[4][4] = WHITE;
 	bm->pixel[3][4] = WHITE;
 	bm->pixel[7][5] = WHITE;
 	bm->pixel[7][6] = WHITE;
 	bm->pixel[7][7] = WHITE;
 	bm->pixel[6][7] = WHITE;
 	bm->pixel[5][7] = WHITE;
 	bm->pixel[4][7] = WHITE;
 	bm->pixel[3][7] = WHITE;

	} else if ((letter == 'j' || letter == 'J')&& fb!= NULL) {
	bm->pixel[0][0] = WHITE;
	bm->pixel[1][0] = WHITE;
	bm->pixel[2][0] = WHITE;
	bm->pixel[0][1] = WHITE;
	bm->pixel[0][2] = WHITE;
	bm->pixel[0][3] = WHITE;
	bm->pixel[0][4] = WHITE;
	bm->pixel[0][5] = WHITE;
	bm->pixel[0][6] = WHITE;
	bm->pixel[1][7] = WHITE;
	bm->pixel[2][7] = WHITE;
	bm->pixel[3][6] = WHITE;
	}

}

void dot_roll(void) {
    clearFrameBuffer(fb, BLACK);
    int vx, vy; //, scrollSpeedX, scrollSpeedY;
//    printf("Enter the velocity in the X and Y directions, separated by a space: ");
// completed in milestone

    float x = 7.0; // Initial x position (fractional)
    float y = 1.0; // Initial y position (fractional)
    
    float dt = 0.1; // Time interval in seconds (adjust as needed for desired smoothness)
 
    while (1) {
        // Draw dot at current position
        y -= dt * vy;
        x -= dt * vx;
        // Wrap around to the opposite edge if the dot reaches the edge of the display
        if (x >= 8) {
            x -= 8;
        } else if (x < 0) {
            x += 8;
        }

        if (y >= 8) {
            y -= 8;
        } else if (y < 0) {
            y += 8;
        }
	display_letter('m', (int)y, (int)x);
        // Pause for a short duration
        usleep(250000);

	}
}


// clear_display function
void clear_display(void) {
    if(fb != NULL){
        clearFrameBuffer(fb,BLACK);
        sleep(1);
        freeFrameBuffer(fb);
        fb = NULL;
    }
}
