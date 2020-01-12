#ifndef PLAYER_AND_OBJECTS_H
#define PLAYER_AND_OBJECTS_H


#include "initialize.h"

// parameter which determines speed of wheels turning around
extern float wheelAngle;

// struct that represents object in game
typedef struct object{

    // array which determines whether in given lane (0/1/2) is object drawn
    unsigned obj[3];

    // position of that obj (where is on track)
    float objPos;
} Object;


// playerLane:
// 0 - first lane (left)
// 3 - second lane (middle)
// 6 - third lane (right)
extern int playerLaneGoingTo;
extern float playerLane;

extern Object allObjects[100];



// functions declarations
void goRight();
void goLeft();
void initObjects();
void onTimer(int value);
Object newObject();

void drawBarrelPig();
void drawSkateboard();











#endif