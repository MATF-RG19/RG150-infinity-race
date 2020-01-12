#include "playerAndObjects.h"
#include "colors.h"

Object allObjects[100];
int playerLaneGoingTo=3;
float playerLane=3;


float wheelAngle=0;

// move player right
void goRight(int value){

    if (value != TIMER_ID){
        return;
    }

    // speed of player changing lanes
    playerLane = playerLane + 1;

    if (playerLane == playerLaneGoingTo){
        animationActiveRight = 0;
    }

    if (animationActiveRight){
        glutTimerFunc(TIME, goRight, TIMER_ID);
    }

    glutPostRedisplay();
}

// move player left
void goLeft(int value){

    if (value != TIMER_ID){
        return;
    }

    // speed of player changing lanes
    playerLane = playerLane - 1;

    if (playerLane == playerLaneGoingTo){
        animationActiveLeft = 0;
    }


    if (animationActiveLeft){
        glutTimerFunc(TIME, goLeft, TIMER_ID);
    }

    glutPostRedisplay();
}




// create new object
Object newObject(){

    Object object;

    int i;

    for (i = 0; i < 3; i++){
        // randomize in which lanes object exists
        int randomLane = rand() % 2;
        object.obj[i] = randomLane;
    }
    // just initializing objPos, later in initObjects it will be set correctly
    object.objPos = 0;

    return object;
}


// init array of objects
void initObjects(){
    
    
    
    for (int i = 0; i < 100; i++){
        allObjects[i] = newObject();
        
        
        // set correct values of objPos for each object (i parameter is used for setting distance between every row of objects)
        allObjects[i].objPos = - 80 - 20*i;

        
    }  
}


void drawBarrelPig(){

    

    glPushMatrix();
        

        
        glMaterialfv(GL_FRONT, GL_AMBIENT, materialPink1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, materialPink1);
        
        glTranslatef(0,0.8,-2);
        
        // body and head
        glPushMatrix();
            GLUquadric* pigBody=gluNewQuadric();
            glScalef(1,1,1.5);
            // body
            glPushMatrix();
                glTranslatef(0,0,-0.5);
                gluCylinder(pigBody,0.5,0.5,1,100,100);
                glColor3f(1,0,0);
                gluDisk(pigBody,0,0.5,100,100);
                glTranslatef(0,0,1);
                gluDisk(pigBody,0,0.5,100,100);
            glPopMatrix();
            // nose/head
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, materialPink2);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, materialPink2);
            
            
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialPink2);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialPink2);
                glScalef(1.8,1,1);
                glTranslatef(0,0,-0.5);
                glutSolidCube(0.2);
            glPopMatrix();
            // nostrils
            glPushMatrix();
                
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                glTranslatef(0.1,0,-0.55);
                glutSolidCube(0.1);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.1,0,-0.55);
                glutSolidCube(0.1);
            glPopMatrix();
            // eyes
            
            glPushMatrix();
                
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWhite);
                glTranslatef(-0.2,0.2,-0.5);
                glutSolidCube(0.1);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.2,0.2,-0.5);
                glutSolidCube(0.1);
            glPopMatrix();
            // pupils
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                glTranslatef(-0.2,0.2,-0.55);
                glutSolidCube(0.05);
            glPopMatrix();
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                glTranslatef(0.2,0.2,-0.55);
                glutSolidCube(0.05);
            glPopMatrix();
            // tail
            glMaterialfv(GL_FRONT, GL_AMBIENT, materialPink2);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, materialPink2);
            glColor3f(0,0,0);
            glPushMatrix();
                glTranslatef(0,0.2,0.5);
                glutSolidCube(0.1);
            glPopMatrix();
            // ears
            glColor3f(0,1,0);
            glPushMatrix();
                glTranslatef(-0.3,0.5,-0.35);
                glScalef(2,2,1);
                glutSolidCube(0.1);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.3,0.5,-0.35);
                glScalef(2,2,1);
                glutSolidCube(0.1);
            glPopMatrix();
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                glTranslatef(-0.3,0.5,-0.4);
                glutSolidCube(0.05);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.3,0.5,-0.4);
                glutSolidCube(0.05);
            glPopMatrix();
            gluDeleteQuadric(pigBody);
        glPopMatrix();
        
        // legs
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, materialPink2);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, materialPink2);
            glTranslatef(0,-0.3,0);
            glScalef(1,4,1);

            glPushMatrix();
                glTranslatef(0.35,0,-0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.35,0,-0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.35,0,0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.35,0,0.35);
                glutSolidCube(0.15);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, materialBrown1);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBrown1);
            glTranslatef(0,-0.6,0);
            
            glPushMatrix();
                glTranslatef(0.35,0,-0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.35,0,-0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.35,0,0.35);
                glutSolidCube(0.15);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.35,0,0.35);
                glutSolidCube(0.15);
            glPopMatrix();
        glPopMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);

    glPopMatrix();
}

void drawSkateboard(){

    glPushMatrix();
    
        glTranslatef(0,0,-2);
        // board
        glPushMatrix();
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, materialGray1);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, materialGray1);
            GLUquadric* skate=gluNewQuadric();
            glPushMatrix();
                
                glScalef(5,1,15);
                glutSolidCube(0.2);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0,0.1,-1.5);
                glRotatef(90,1,0,0);
                gluCylinder(skate,0.5,0.5,0.2,100,100);
                
                gluDisk(skate,0,0.5,100,100);
                glTranslatef(0,0,0.2);
                gluDisk(skate,0,0.5,100,100);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0,0.1,1.5);
                glRotatef(90,1,0,0);
                gluCylinder(skate,0.5,0.5,0.2,100,100);
                
                gluDisk(skate,0,0.5,100,100);
                glTranslatef(0,0,0.2);
                gluDisk(skate,0,0.5,100,100);
            glPopMatrix();
            gluDeleteQuadric(skate);
        glPopMatrix();
        // wheels
        glPushMatrix();
            
            
            GLUquadric* wheels=gluNewQuadric();
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                
                glTranslatef(-0.45,-0.30,1);
                glRotatef(90,0,1,0);
                
                // when animationActive==1 wheels are turning around
                glRotatef(wheelAngle,0,0,1);          
                gluCylinder(wheels,0.15,0.15,0.1,100,100);
                
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWhite);
                gluCylinder(wheels,0.05,0.05,0.1,100,100);
                
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                gluDisk(wheels,0.05,0.15,100,100);
                glTranslatef(0,0,0.1);
                gluDisk(wheels,0.05,0.15,100,100);
            glPopMatrix();
            glPushMatrix();
                
                glTranslatef(-0.45,-0.30,-1);
                glRotatef(90,0,1,0);
                
                glRotatef(wheelAngle,0,0,1);       
                gluCylinder(wheels,0.15,0.15,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWhite);
                gluCylinder(wheels,0.05,0.05,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                
                gluDisk(wheels,0.05,0.15,100,100);
                glTranslatef(0,0,0.1);
                gluDisk(wheels,0.05,0.15,100,100);
            glPopMatrix();
            glPushMatrix();
                glColor3f(0.9,0.9,0.9);
                glTranslatef(0.35,-0.30,1);
                glRotatef(90,0,1,0);
                
                glRotatef(wheelAngle,0,0,1);
                gluCylinder(wheels,0.15,0.15,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWhite);
                gluCylinder(wheels,0.05,0.05,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                
                gluDisk(wheels,0.05,0.15,100,100);
                glTranslatef(0,0,0.1);
                gluDisk(wheels,0.05,0.15,100,100);
            glPopMatrix();
            glPushMatrix();
                
                glTranslatef(0.35,-0.30,-1);
                glRotatef(90,0,1,0);
                
                glRotatef(wheelAngle,0,0,1);
                gluCylinder(wheels,0.15,0.15,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialWhite);
                gluCylinder(wheels,0.05,0.05,0.1,100,100);
                glMaterialfv(GL_FRONT, GL_AMBIENT, materialBlack1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, materialBlack1);
                
                gluDisk(wheels,0.05,0.15,100,100);
                glTranslatef(0,0,0.1);
                gluDisk(wheels,0.05,0.15,100,100);
            glPopMatrix();
            gluDeleteQuadric(wheels);
        glPopMatrix();
        // pins and pinholders
        glPushMatrix();
            GLUquadric* pins=gluNewQuadric();
            glPushMatrix();
                glColor3f(0,0,0);
                glTranslatef(0,-0.15,-1);
                glScalef(1,3,1);
                glutSolidCube(0.1);
    
                glTranslatef(0,-0.05,-0.5);
                glRotatef(90,0,1,0);
                glTranslatef(-0.5,0,-0.4);
                
                gluCylinder(pins,0.01,0.01,0.8,100,100);
                
                
            glPopMatrix();
            glPushMatrix();
                glColor3f(0,0,0);
                glTranslatef(0,-0.15,1);
                glScalef(1,3,1);
                glutSolidCube(0.1);
                glTranslatef(0,-0.05,-0.5);
                glRotatef(90,0,1,0);
                glTranslatef(-0.5,0,-0.4);
                
                gluCylinder(pins,0.01,0.01,0.8,100,100);
                
            glPopMatrix();
            gluDeleteQuadric(pins);
        glPopMatrix();
    glPopMatrix();
}