#ifndef OBJECTS_H
#define OBJECTS_H

#include "initialize.h"

#define numberOfObjects 100


// struct that represents object in game
// struct represents 1 row of objects on track
typedef struct object{

    // array which determines whether in given lane (0/1/2) is object drawn
    unsigned obj[3];

    // type of object (object1/object2/object3)
    unsigned objType;

    // position of that obj (where is on track)
    float objPos;



} Object;




extern Object allObjects[numberOfObjects];


void initObjects();
Object newObject();
void drawObjects();
void drawMushroom1();
void drawMushroom2();
void drawMushroom3();











#endif