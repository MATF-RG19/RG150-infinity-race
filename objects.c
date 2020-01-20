#include "objects.h"

#define PI 3.14
Object allObjects[100];


// create new object
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
    for (int i = 0; i < 100; i++){
        
        if (allObjects[i].objPos >-70){

            for (int j = 0; j < 3; j++){

                if (allObjects[i].obj[j] == 1){

                    // drawing/putting object in his lane  
                    objectLane = 3 * j;
                    
                    // Drawing obstacles
                    glPushMatrix();

                    glTranslatef(objectLane, 0, allObjects[i].objPos);
                    // glutSolidCube(0.5);
                    
                    if(allObjects[i].objType==0){
                        drawMushroom1();
                    }else if(allObjects[i].objType==1){
                        drawMushroom2();
                    }else{ //if(allObjects[i].objType==2)
                        drawMushroom3();
                    }

                    glPopMatrix();
                    // printf("PLAYERPOS %f OBJECTPOS %f  PLAYERLANE %f OBJECTLANE %d\n\n",playerPos,allObjects[i].objPos,playerLane,objectLane);
                    // printf("BODY %f EYES %f EARS %f\n",scaleParameterBody,scaleParameterEyes,scaleParameterEars);
                    if(collisionDetection(playerPos,playerLane,allObjects[i].objPos,objectLane)){
                        allObjects[i].obj[j]=0;
                        // if player eats/hits first object (mushroom) player's body will get larger
                        if(allObjects[i].objType==0){
                            scaleParameterBody=scaleParameterBody+0.3;
                        }else if(allObjects[i].objType==1){
                            scaleParameterEars=scaleParameterEars+0.3;
                        }else if(allObjects[i].objType==2){
                            scaleParameterEyes=scaleParameterEyes+0.5;
                        }

                        if(scaleParameterBody>1.2 || scaleParameterEars>1.5 || scaleParameterEyes>1.5){
        
                            glutTimerFunc(TIME,endGameAnimation,TIMER_ID);
                        }
                        // printf("DADADADADA\nDADADADADA\nDADADADADA\nDADADADADA\n");
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
                // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialWhite);
                // glLightfv(GL_LIGHT0, GL_SPECULAR, materialWhite);
                
                // glColor3f(0,0,0);
                // glTranslatef(0,-0.15,-1);
                // glScalef(1,3,1);
                // // glutSolidCube(0.1);
    
                // glTranslatef(0,-0.05,-0.5);
                // glRotatef(90,0,1,0);
                // glTranslatef(-0.5,0,-0.4);
                glTranslatef(0,1,0);
                // glRotatef(90,1,0,0);
                
                double clip_plane[] = {0, 2, 0, 0};

                glClipPlane(GL_CLIP_PLANE0, clip_plane);
                glEnable(GL_CLIP_PLANE0);
                // glTranslatef(0,3,0);
                glRotatef(90,1,0,0);
                // glRotatef(animation_parameter * 60, 1, 0, 0);
                // glutSolidSphere(1.5, 20, 20);
                glutSolidSphere(1,100,100);

                glDisable(GL_CLIP_PLANE0);

                // glutSolidSphere(1,100,100);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialWhite);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialWhite);

                gluCylinder(mushroom,0.3,0.3,1.5,100,100);
                

            glPopMatrix();
            gluDeleteQuadric(mushroom);
glPopMatrix();

                // float x;
                // float y;
                // float z;
                // float r=1;
                // int k1=0;
                // int k2=0;
                // glBegin(GL_TRIANGLES);
                // for(k1=-PI/2;k1<PI/2;k1+=0.1){
                //     // for(k2=-PI;k2<PI;k2+=0.1){
                        
                //         x=r*sin(k1)*cos(k2);
                //         y=r*sin(k1)*sin(k2);
                //         z=r*cos(k1);
                //         glVertex3f(x,y,z);

                //     // }
                // }
                // glEnd();
                

//             // number of latitudes (parallels)
//             float numberOfLatitudes=10;
//             // number of longitudes (meridians)
//             float numberOfLongitudes=10;
            
//             float radius=1;
//             float x, y, z, xy;                              // vertex position
// float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
// float s, t;                                     // vertex texCoord

// float sectorStep = 2 * PI / numberOfLatitudes;
// float stackStep = PI / numberOfLongitudes;
// float sectorAngle, stackAngle;
// glBegin(GL_TRIANGLE_STRIP);
// for(int i = 0; i <= numberOfLongitudes; ++i)
// {
//     stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
//     xy = radius * cosf(stackAngle);             // r * cos(u)
//     z = radius * sinf(stackAngle);              // r * sin(u)

//     // add (numberOfLatitudes+1) vertices per stack
//     // the first and last vertices have same position and normal, but different tex coords
//     for(int j = 0; j <= numberOfLatitudes; ++j)
//     {
//         sectorAngle = j * sectorStep;           // starting from 0 to 2pi

//         // vertex position (x, y, z)
//         x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
//         y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
//         glVertex3f(x,y,z);
//         // vertices.push_back(x);
//         // vertices.push_back(y);
//         // vertices.push_back(z);

//         // normalized vertex normal (nx, ny, nz)
//         nx = x * lengthInv;
//         ny = y * lengthInv;
//         nz = z * lengthInv;
//         glNormal3f(nx,ny,nz);
//         // normals.push_back(nx);
//         // normals.push_back(ny);
//         // normals.push_back(nz);

//         // vertex tex coord (s, t) range between [0, 1]
//         // s = (float)j / numberOfLatitudes;
//         // t = (float)i / numberOfLongitudes;
//         // texCoords.push_back(s);
//         // texCoords.push_back(t);
//     }
// }
// glEnd();


                
          
}

void drawMushroom2(){


    glPushMatrix();
    
        GLUquadric* mushroom=gluNewQuadric();
            glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialPurple1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialPurple1);
                // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialPurple2);
                // glLightfv(GL_LIGHT0, GL_SPECULAR, materialPurple2);

                
                // glColor3f(0,0,0);
                // glTranslatef(0,-0.15,-1);
                // glScalef(1,3,1);
                // // glutSolidCube(0.1);
    
                // glTranslatef(0,-0.05,-0.5);
                // glRotatef(90,0,1,0);
                // glTranslatef(-0.5,0,-0.4);
                glTranslatef(0,1,0);
                // glRotatef(90,1,0,0);
                
                glPushMatrix();
                    glScalef(0.5,1,0.5);
                    double clip_plane[] = {0, 2, 0, 0};

                    glClipPlane(GL_CLIP_PLANE0, clip_plane);
                    glEnable(GL_CLIP_PLANE0);
                    // glTranslatef(0,3,0);
                    glRotatef(90,1,0,0);
                    // glRotatef(animation_parameter * 60, 1, 0, 0);
                    // glutSolidSphere(1.5, 20, 20);
                    glutSolidSphere(1,100,100);

                    glDisable(GL_CLIP_PLANE0);
                glPopMatrix();
                // glutSolidSphere(1,100,100);
                
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
                // glMaterialfv(GL_FRONT, GL_SPECULAR, materialBrown2);
                // glLightfv(GL_LIGHT0, GL_SPECULAR, materialBrown2);
                // glColor3f(0,0,0);
                // glTranslatef(0,-0.15,-1);
                // glScalef(1,3,1);
                // // glutSolidCube(0.1);
    
                // glTranslatef(0,-0.05,-0.5);
                // glRotatef(90,0,1,0);
                // glTranslatef(-0.5,0,-0.4);
                glTranslatef(0,0,0);
                // glRotatef(90,1,0,0);
                
                glPushMatrix();
                    glScalef(1,0.4,1);
                    double clip_plane[] = {0, 2, 0, 0};

                    glClipPlane(GL_CLIP_PLANE0, clip_plane);
                    glEnable(GL_CLIP_PLANE0);
                    // glTranslatef(0,3,0);
                    glRotatef(90,1,0,0);
                    // glRotatef(animation_parameter * 60, 1, 0, 0);
                    // glutSolidSphere(1.5, 20, 20);
                    glutSolidSphere(1,100,100);

                    glDisable(GL_CLIP_PLANE0);
                glPopMatrix();
                // glutSolidSphere(1,100,100);

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialBrown1);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialBrown1);
                glRotatef(90,1,0,0);
                gluCylinder(mushroom,0.5,0.5,0.5,100,100);
                

            glPopMatrix();
            gluDeleteQuadric(mushroom);
glPopMatrix();
                
          
}

