#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>


#define TIMER_ID 0
#define TIME 50



// struct that represents object in game
typedef struct object{

    // array which determines whether in given lane (0/1/2) is object drawn
    unsigned obj[3];

    // position of that obj (where is on track)
    float objPos;
} Object;


/*callback function declarations*/
static void onDisplay(void);
static void onReshape(int width, int height);
static void onKeyboard(unsigned char key, int x, int y);


float animationSpeedParameter=1;
int animationActive=0;
int animationActiveRight=0;
int animationActiveLeft=0;


// playerLane:
// 0 - first lane (left)
// 3 - second lane (middle)
// 6 - third lane (right)
int playerLaneGoingTo=3;
float playerLane=3;


// functions declarations
void goRight();
void goLeft();
void initObjects();
void onTimer(int value);
Object newObject();



Object allObjects[100];




int main(int argc, char **argv){

    // GLUT init
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // creating window with desired size and name
    glutInitWindowSize(800, 450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Infinity race");

    // callback init
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);
    glutKeyboardFunc(onKeyboard);

    // OpenGL init
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);

    // initialize rand for all calls
    srand(time(NULL));

    // initialize objects array
    initObjects();


    // starting main loop
    glutMainLoop();

  return 0;
}

static void onDisplay(void){

    // clears the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // next transformations affects the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    // clear the matrix
    glLoadIdentity();
    // positions and aims the camera towards where we want (viewing transformation)
    gluLookAt(3, 6, 8, 3, 1, -2, 0, 1, 0);
    // gluLookAt(xCam+rCam*sin(phiCam), yCam, zCam+rCam*cos(phiCam)-10, 3, 1, -2, 0, 1, 0);


    // position of light source ((x, y, z, w) position of light)
    GLfloat lightPosition[] = { 1, 1, 1, 0 };

    // ambient RGBA intensity of light
    GLfloat lightAmbient[] = { 0, 1, 0, 1 };

    // diffuse RGBA intensity of light
    GLfloat lightDiffuse[] = { 0, 0, 0, 1 };

    // specular RGBA intensity of light
    GLfloat lightSpecular[] = { 1, 1, 1, 1 };

    // ambient color of material
    GLfloat ambientMaterial[] = { 0, 0, 1, 1 };

    // diffuse color of material
    GLfloat diffuseMaterial[] = { 0, 1, 0, 1 };

    // specular color of material
    GLfloat specularMaterial[] = { 1, 1, 1, 1 };

    // specular exponent
    GLfloat shininess = 10;

    // enable and set light parameters
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // set material parameters
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    // create objects
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(playerLane, 0, 0);
    glutSolidSphere(0.4, 100, 100);
    glPopMatrix();


    

    // create path/borders
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex3f(-1, 0, 100);
    glVertex3f(-1, 0, -100);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(7, 0, 100);
    glVertex3f(7, 0, -100);
    glEnd();


    // create objects
    for (int i = 0; i < 100; i++){
        if (allObjects[i].objPos < 100){

            for (int j = 0; j < 3; j++){

                if (allObjects[i].obj[j] == 1){

                    // drawing/putting object in his lane  
                    int objectLane = 3 * j;

                    // Drawing obstacles
                    glPushMatrix();

                    glTranslatef(objectLane, 0, allObjects[i].objPos);
                    glutSolidCube(0.5);

                    glPopMatrix();


                }
             }
        }
    }
    



    glShadeModel(GL_SMOOTH);



    // send new image to screen
    glutSwapBuffers();
}

static void onReshape(int width, int height){

    // set the viewport
    glViewport(0, 0, width, height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) width / height, 1, 100);
    glMatrixMode (GL_MODELVIEW);
}


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


void onTimer(int value){
    if (value != TIMER_ID){
        return;
    }


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



static void onKeyboard(unsigned char key, int x, int y){
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
            if(!animationActive){
                animationActive=1;
                glutTimerFunc(TIME, onTimer, TIMER_ID);
                break;
            }
    }
}