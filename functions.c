#include "incl/functions.h"





float xCam=3;
float yCam=6;
float zCam=8;
float rCam=10;
float phiCam=0;
float thetaCam=0;


void onDisplay(void){

    // clears the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // next transformations affects the modelview matrix
    glMatrixMode(GL_MODELVIEW);

    // clear the matrix
    glLoadIdentity();

    // positions and aims the camera towards where we want (viewing transformation)
    // gluLookAt(3, 6, 8, 3, 1, -2, 0, 1, 0);
    gluLookAt(xCam+rCam*sin(phiCam)+rCam*sin(thetaCam), yCam+rCam*cos(thetaCam)-10, zCam+rCam*cos(phiCam)-10, 3, 1, -2, 0, 1, 0);
    

    // position of light source ((x, y, z, w) position of light)
    GLfloat lightPosition[] = { 1, 1, 1, 0 };

    // ambient RGBA intensity of light
    GLfloat lightAmbient[] = { 1, 1, 1, 1 };

    // diffuse RGBA intensity of light
    GLfloat lightDiffuse[] = { 0, 0, 0, 1 };

    // int result;
    // glGetIntegerv(GL_MAX_MODELVIEW_STACK_DEPTH, &result);
    // printf("%d\n",result);

    // specular exponent
    GLfloat shininess = 10;

    // enable and set light parameters
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);


    // // set material parameters
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glShadeModel(GL_SMOOTH);
    
    glPushMatrix();
    // create player
    glPushMatrix();
    
        glTranslatef(playerLane, 0, 0);
    
        glPushMatrix();
    // glTranslatef(0,sin(pomeriY)/10,0);
            drawBarrelPig();
            drawSkateboard();
        glPopMatrix();

    glPopMatrix();


    drawTrack();
    drawObjects();

    glPopMatrix();

    // glPushMatrix();
    // displayScore();
    displayScore();
    // glPopMatrix();
    displayText();


    // glShadeModel(GL_SMOOTH);



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

    // updating color
    if(colorChange<6){
        colorChange=colorChange+colorChangeSpeedUpdate;
    }else{
        colorChange=1;
    }

    // updating player animation
    if(pomeriY<360){   
        pomeriY=pomeriY+0.2;
    }else{
        pomeriY=0;
    }

    // updating wheel animation
    wheelAngle=wheelAngle+1;

    // updating score
    score=score+0.1;

    // updating speed of objects
    if(animationSpeedParameter<2){
        animationSpeedParameter=animationSpeedParameter+0.01;
    }

    // moving objects as time goes by
    for (int i = 0; i < numberOfObjects; i++){
        if (allObjects[i].objPos < 3){

            allObjects[i].objPos =allObjects[i].objPos+animationSpeedParameter * 0.5;
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

// animation when game is over
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

// function that resets everything to starting values
void resetEverything(){

    animationSpeedParameter=1;

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

    colorChange=1;
    colorChangeSpeedUpdate=0.1;

    score=0;
    strcpy(text,"Press U to start / pause game or ESC to quit");
    strcpy(textCam,"Press C to change camera");

    endGame=false;

    initObjects();

}

// function for displaying score in left right corner
void displayScore(){

    int currentWidth = glutGet(GLUT_WINDOW_WIDTH);
    int currentHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glDisable(GL_LIGHTING);
    glColor3f( 0, 0, 0 );
	
    glMatrixMode( GL_PROJECTION );
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D( 0, currentWidth, 0, currentHeight );
		glMatrixMode( GL_MODELVIEW );
		
		glPushMatrix();
			glLoadIdentity();
            char scoreText[20];
            int w = sprintf(scoreText, "SCORE: %.1f",score);
			glRasterPos2i(20, currentHeight-50);
			int len = (int)strlen(scoreText);
			for (int i = 0; i<len; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, scoreText[i]);
			}
		glPopMatrix();

	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glMatrixMode( GL_MODELVIEW );
}

// function for displaying text
void displayText(){

    int len1 = (int)strlen(text);
    int len2 = (int)strlen(textCam);
    int current_width = glutGet(GLUT_WINDOW_WIDTH);
    int current_height = glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();

            glLoadIdentity();
            glDisable(GL_LIGHTING);
            glOrtho(0, current_width, 0, current_height, -1, 1);
        
            glColor3f(0, 0, 0);
            glRasterPos2f(current_width/2 - 2.5*len1, current_height*.95);

            for (int i = 0; i < len1; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);

            glRasterPos2f(current_width-180,current_height-50);

            for (int j = 0; j < len2; j++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, textCam[j]);

        glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    // glMatrixMode(GL_PROJECTION);
    // glPopMatrix();
    // glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}





void onKeyboard(unsigned char key, int x, int y){
    switch (key) {
        // end program (ESC)
        case 27:
            exit(0);
            break;
        // move player left if game is running/animation is active
        case 'q':
        case 'Q':
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
        case 'E':
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
        case 'U':
            if(!animationActive && !endGame){
                animationActive=1;
                strcpy(text,"");
                strcpy(textCam,"");
                glutTimerFunc(TIME, onTimer, TIMER_ID);
            // pause the game
            }else if(animationActive && !endGame){
                strcpy(text,"Press R to restart or U to start or ESC to quit");
                strcpy(textCam,"Press C to change camera");
                animationActive=0;
            }
                // glutTimerFunc(TIME, onTimer, TIMER_ID);
                glutPostRedisplay();
            
            break;
        // restart the game
        case 'r':
        case 'R':
            if(!animationActive){
                resetEverything();
                // endGame=false;
                // animationActive=0;
                // endGame=false;
                
                glutPostRedisplay();
                
                // glutTimerFunc(TIME, onTimer, TIMER_ID);
            }
            break;
        // change camera view
        case 'c':
        case 'C':
            if(phiCam==0 && thetaCam==0){
                phiCam=-0.5;
            }else{
                phiCam=0;
            }
            glutPostRedisplay();
            break;
    }
}