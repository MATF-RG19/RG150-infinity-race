#ifndef PLAYER_H
#define PLAYER_H


#include "initialize.h"


// parameter used for wheels turning around animation
extern float wheelAngle;




// playerLane:
// 0 - first lane (left)
// 3 - second lane (middle)
// 6 - third lane (right)
extern int playerLaneGoingTo;

// playerLane is float because of possibility of changing speed of changing lanes but after finishing changing value of playerLane it has to be whole number
extern float playerLane;

// position of player (always same)
extern float playerPos;

// parameters for scaling player after hitting object/mushroom
extern float scaleParameterBody;
extern float scaleParameterBodyEnd;
extern float scaleParameterEars;
extern float scaleParameterEyes;
extern float scaleParameterEyesPupils;



// parameter for player's animation
extern float pomeriY;




// functions declarations
void goRight();
void goLeft();


void drawBarrelPig();
void drawSkateboard();
bool collisionDetection(float playerPos, float playerCurrentLane, float objectPos, int objectCurrentLane);










#endif