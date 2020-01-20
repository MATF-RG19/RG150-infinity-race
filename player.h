#ifndef PLAYER_H
#define PLAYER_H


#include "initialize.h"


// parameter which determines speed of wheels turning around
extern float wheelAngle;




// playerLane:
// 0 - first lane (left)
// 3 - second lane (middle)
// 6 - third lane (right)
extern int playerLaneGoingTo;

// playerLane is float because of possibility of changing speed of changing lanes but after finishing changing value of playerLane it has to be whole number
extern float playerLane;

extern float playerPos;


extern float scaleParameterBody;
extern float scaleParameterBodyEnd;
extern float scaleParameterEars;
extern float scaleParameterEyes;
extern float scaleParameterEyesPupils;



// functions declarations
void goRight();
void goLeft();


void drawBarrelPig();
void drawSkateboard();
bool collisionDetection(float playerPos, float playerCurrentLane, float objectPos, int objectCurrentLane);










#endif