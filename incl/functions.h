#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "initialize.h"
#include "player.h"
#include "objects.h"






// callback function declarations
void onDisplay(void);
void onReshape(int width, int height);
void onKeyboard(unsigned char key, int x, int y);

void onTimer(int value);
void endGameAnimation(int value);

void resetEverything();

void displayScore();
void displayText();










#endif