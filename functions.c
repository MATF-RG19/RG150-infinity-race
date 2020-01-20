#include "functions.h"




// skloniti
float xCam=3;
float yCam=6;
float zCam=8;
float rCam=10;
float phiCam=0;
float thetaCam=0;
// float phiCam=1.5;
// float thetaCam=-2.5;
float p=45;

void onDisplay(void){

    // clears the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // next transformations affects the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    // clear the matrix
    glLoadIdentity();
    // positions and aims the camera towards where we want (viewing transformation)
    // gluLookAt(3, 6, 8, 3, 1, -2, 0, 1, 0);
    // gluLookAt(xCam+rCam*sin(phiCam), yCam, zCam+rCam*cos(phiCam)-10, 3, 1, -2, 0, 1, 0);
    // gluLookAt(xCam+rCam*sin(phiCam)+rCam*sin(thetaCam), yCam+rCam*cos(thetaCam), zCam+rCam*cos(phiCam)-10, 3, 1, -2, 0, 1, 0);
    gluLookAt(xCam+rCam*sin(phiCam)+rCam*sin(thetaCam), yCam+rCam*cos(thetaCam)-10, zCam+rCam*cos(phiCam)-10, 3, 1, -2, 0, 1, 0);
    // printf("%f,%f\n",phiCam,thetaCam);

    printf("BOOL %d animation %d\n",endGame,animationActive);

    // position of light source ((x, y, z, w) position of light)
    GLfloat lightPosition[] = { 1, 1, 1, 0 };

    // ambient RGBA intensity of light
    GLfloat lightAmbient[] = { 1, 1, 1, 1 };

    // diffuse RGBA intensity of light
    GLfloat lightDiffuse[] = { 0, 0, 0, 1 };

    // specular RGBA intensity of light
    // GLfloat lightSpecular[] = { 1, 1, 1, 1 };

    // ambient color of material
    GLfloat ambientMaterial[] = { 0, 0, 1, 1 };

    // diffuse color of material
    GLfloat diffuseMaterial[] = { 0, 1, 0, 1 };

    // specular color of material
    // GLfloat specularMaterial[] = { 1, 1, 1, 1 };

    // specular exponent
    GLfloat shininess = 10;

    // enable and set light parameters
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // // set material parameters
    // glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    // glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    // create objects
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(playerLane, 0, 0);
    // glTranslatef(-3,0,0);
    drawBarrelPig();
    drawSkateboard();
    // glutSolidSphere(0.4, 100, 100);
    glPopMatrix();


    // if(scaleParameterBody>1.2 || scaleParameterEars>1.5 || scaleParameterEyes>1.5){
        
    //     glutTimerFunc(TIME,endGameAnimation,TIMER_ID);
    // }

    // create path/borders
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex3f(-1, -0.5, 100);
    glVertex3f(-1, -0.5, -100);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(7, -0.5, 100);
    glVertex3f(7, -0.5, -100);
    glEnd();

    
    drawObjects();
    



    glShadeModel(GL_SMOOTH);



    // send new image to screen
    glutSwapBuffers();
}


void onReshape(int width, int height){

    // set the viewport
    glViewport(0, 0, width, height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) width / height, 1, 100);
    glMatrixMode (GL_MODELVIEW);
}


void onTimer(int value){
    if (value != TIMER_ID){
        return;
    }
    glPushMatrix();
    glTranslatef(1,4,-10);
    glutSolidCube(5);
    glPopMatrix();
    wheelAngle=wheelAngle+1;

    // moving objects as time goes by
    for (int i = 0; i < 100; i++){
        if (allObjects[i].objPos < 3){

            allObjects[i].objPos =allObjects[i].objPos+animationSpeedParameter * .5;
        } else{
            // return objects behind all others so they all loop
            allObjects[i].objPos = -2000.0;
        }
    }
    
    glutPostRedisplay();

    // calling onTimer again if the animation/game is still active
    if (animationActive){
        glutTimerFunc(TIME, onTimer, TIMER_ID);
    }
}

void endGameAnimation(int value){
    if (value != TIMER_ID){
        return;
    }

    
    phiCam=-3;
    thetaCam=0;
    endGame=true;

    animationActive=0;
    
    glutPostRedisplay();
    // if (animationActive){
    //     glutTimerFunc(TIME, onTimer, TIMER_ID);
    // }

    
}

void resetEverything(){
    // animationActive=0;

    phiCam=0;
    thetaCam=0;
    
    playerLaneGoingTo=3;
    playerLane=3;
    

    scaleParameterBody=1;
    scaleParameterBodyEnd=1;
    scaleParameterEars=1;
    scaleParameterEyes=1;
    scaleParameterEyesPupils=1;

    wheelAngle=0;


    // phiCam=0;
    // thetaCam=0;
    // glutPostRedisplay();
    endGame=false;

    initObjects();
    // glutPostRedisplay();
}


void onKeyboard(unsigned char key, int x, int y){
    switch (key) {
        // end program (ESC)
        case 27:
            exit(0);
            break;
        // move player left if game is running/animation is active
        case 'q':
            if (animationActive == 1){

                animationActiveRight = 0;
                if (animationActiveLeft == 0 && playerLaneGoingTo > 0){
                    playerLaneGoingTo -= 3;
                    animationActiveLeft = 1;
                    glutTimerFunc(TIME, goLeft, TIMER_ID);
                }
            }
            break;
        // move player right if game is running/animation is active
        case 'e':
            if (animationActive == 1){

                animationActiveLeft = 0;
                if (animationActiveRight == 0 && playerLaneGoingTo < 6){

                    playerLaneGoingTo += 3;
                    animationActiveRight = 1;
                    glutTimerFunc(TIME, goRight, TIMER_ID);
                }
            }
            break;
        // start the game
        case 'u':
            if(!animationActive && !endGame){
                animationActive=1;
                glutTimerFunc(TIME, onTimer, TIMER_ID);
            // pause the game
            }else if(animationActive && !endGame){
                animationActive=0;
            }
                // glutTimerFunc(TIME, onTimer, TIMER_ID);
                glutPostRedisplay();
            
            break;
        // restart the game
        case 'r':
            if(!animationActive){
                resetEverything();
                // endGame=false;
                // animationActive=0;
                // endGame=false;
                
                glutPostRedisplay();
                
                // glutTimerFunc(TIME, onTimer, TIMER_ID);
            }
            break;

        case 'a':
            phiCam=phiCam+0.5;
            glutPostRedisplay();
            break;
        case 'd':
            phiCam=phiCam-0.5;
            glutPostRedisplay();
            break;
        case 'w':
            thetaCam=thetaCam+0.5;
            glutPostRedisplay();
            break;
        case 's':
            thetaCam=thetaCam-0.5;
            glutPostRedisplay();
            break;
    }
}