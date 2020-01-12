#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

#include "functions.h"
#include "playerAndObjects.h"


#define TIMER_ID 0
#define TIME 50



extern float animationSpeedParameter;
extern int animationActive;
extern int animationActiveRight;
extern int animationActiveLeft;



void glutInitNew(int *argc, char **argv);
void funcInit();







#endif