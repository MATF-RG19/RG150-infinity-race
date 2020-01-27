#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <GL/glut.h>

#include "functions.h"
#include "player.h"
#include "objects.h"
#include "colors.h"
#include "img.h"
#include "background.h"

#define SIZE 256

#define TIMER_ID 0
#define TIME 50


// speed of objects/animation moving
extern float animationSpeedParameter;

// indicator that shows if game is active
extern int animationActive;

// indicator that shows if player is moving to right at the moment
extern int animationActiveRight;

// indicator that shows if player is moving to left at the moment
extern int animationActiveLeft;

// indicator that shows if game is ended
extern bool endGame;

extern float score;

extern char text[SIZE];

extern char textCam[SIZE];


void glutInitNew(int *argc, char **argv);
void funcInit();
void initTexture();





#endif