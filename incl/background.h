#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "initialize.h"


// alias of texture we use
#define TEXTURE "assets/Leather0085_1_S.bmp"

GLuint names[1];

// speed of color changing (left and right portion of background)
extern float colorChange;

// how much colorChange speeds up when player hits object/mushroom
extern float colorChangeSpeedUpdate;


// Function used to draw game track
void drawTrack(void);















#endif