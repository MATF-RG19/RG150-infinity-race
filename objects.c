#include "incl/objects.h"


Object allObjects[numberOfObjects];


// create new object (row of objects)
Object newObject(){

    Object object;

    int i;

    for (i = 0; i < 3; i++){
        // randomize in which lanes object exists
        // if random lane for given parameter i is 0 then in that lane object doesnt exist
        // if random lane for given parameter i is 1 then in that lane object does exist
        int randomLane = rand() % 2;
        object.obj[i] = randomLane;
    }
    // randomize type of object
    int randomType=rand()%3;
    object.objType=randomType;

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

void drawObjects(){
    GLfloat shininess = 100;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    // glMaterialfv(GL_FRONT, GL_SPECULAR, materialBlack1);
    // create objects
    int objectLane;
    for (int i = 0; i < numberOfObjects; i++){
        
        if (allObjects[i].objPos >-70){

            for (int j = 0; j < 3; j++){

                if (allObjects[i].obj[j] == 1){

                    // drawing/putting object in his lane  
                    objectLane = 3 * j;
                    
                    // drawing objects
                    glPushMatrix();

                    glTranslatef(objectLane, 0, allObjects[i].objPos);
                    
                    
                    if(allObjects[i].objType==0){
                        drawMushroom1();
                    }else if(allObjects[i].objType==1){
                        drawMushroom2();
                    }else{ //if(allObjects[i].objType==2)
                        drawMushroom3();
                    }

                    glPopMatrix();
                    
                    if(collisionDetection(playerPos,playerLane,allObjects[i].objPos,objectLane)){
                        // remove object if player hits it
                        allObjects[i].obj[j]=0;

                        // if player eats/hits first object (mushroom) player's body will get larger
                        if(allObjects[i].objType==0){
                            scaleParameterBody=scaleParameterBody+0.2;
                            // if player hits any shroom color change speeds up
                            colorChangeSpeedUpdate=colorChangeSpeedUpdate+0.1;

                        // if player eats/hits second object (mushroom) player's ears will get larger
                        }else if(allObjects[i].objType==1){
                            scaleParameterEars=scaleParameterEars+0.5;
                            colorChangeSpeedUpdate=colorChangeSpeedUpdate+0.1;

                        // if player eats/hits third object (mushroom) player's eyes will get larger
                        }else if(allObjects[i].objType==2){
                            scaleParameterEyes=scaleParameterEyes+0.8;
                            colorChangeSpeedUpdate=colorChangeSpeedUpdate+0.1;
                        }
                        // if player hits 2 red shrooms or 2 purple shrooms or 2 green shrooms game is over
                        if(scaleParameterBody>1.25 || scaleParameterEars>1.6 || scaleParameterEyes>2){
                            strcpy(text,"GAME OVER | Press R to restart game or ESC to quit");
                            glutTimerFunc(TIME,endGameAnimation,TIMER_ID);
                        }
                        
                    }


                }
             }
        }
    }
}

void drawMushroom1(){

    glPushMatrix();
    
        GLUquadric* mushroom=gluNewQuadric();
            glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialRed1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialRed1);
                
                glTranslatef(0,1,0);
                
                
                double clip_plane[] = {0, 2, 0, 0};

                glClipPlane(GL_CLIP_PLANE0, clip_plane);
                // clipping half sphere
                glEnable(GL_CLIP_PLANE0);
                
                    glRotatef(90,1,0,0);
                    
                    glutSolidSphere(1,100,100);

                glDisable(GL_CLIP_PLANE0);

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialWhite);

                gluCylinder(mushroom,0.3,0.3,1.5,100,100);
                

            glPopMatrix();
            gluDeleteQuadric(mushroom);
    glPopMatrix();

                
          
}

void drawMushroom2(){


    glPushMatrix();
    
        GLUquadric* mushroom=gluNewQuadric();
            glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialPurple1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialPurple1);
                
                glTranslatef(0,1,0);
                
                glPushMatrix();
                    glScalef(0.5,1,0.5);
                    double clip_plane[] = {0, 2, 0, 0};

                    glClipPlane(GL_CLIP_PLANE0, clip_plane);
                    glEnable(GL_CLIP_PLANE0);
                    
                    glRotatef(90,1,0,0);
                    
                    glutSolidSphere(1,100,100);

                    glDisable(GL_CLIP_PLANE0);
                glPopMatrix();
                
                
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGray1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGray1);
                glRotatef(90,1,0,0);
                gluCylinder(mushroom,0.1,0.1,1.5,100,100);
                

            glPopMatrix();
            gluDeleteQuadric(mushroom);
    glPopMatrix();
                
          
}


void drawMushroom3(){

    glPushMatrix();
    
        GLUquadric* mushroom=gluNewQuadric();
            glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen1);
                
                glTranslatef(0,0,0);
                
                
                glPushMatrix();
                    glScalef(1,0.4,1);
                    double clip_plane[] = {0, 2, 0, 0};

                    glClipPlane(GL_CLIP_PLANE0, clip_plane);
                    glEnable(GL_CLIP_PLANE0);
                    
                    glRotatef(90,1,0,0);
                    
                    glutSolidSphere(1,100,100);

                    glDisable(GL_CLIP_PLANE0);
                glPopMatrix();
                

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialBrown1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialBrown1);
                glRotatef(90,1,0,0);
                gluCylinder(mushroom,0.5,0.5,0.5,100,100);
                

            glPopMatrix();
            gluDeleteQuadric(mushroom);
    glPopMatrix();
                
          
}

