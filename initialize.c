#include "initialize.h"
// #include "playerAndObjects.h"


float animationSpeedParameter=1;
int animationActive=0;
int animationActiveRight=0;
int animationActiveLeft=0;



void glutInitNew(int *argc, char **argv){
    // GLUT init
    glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // creating window with desired size and name
    glutInitWindowSize(800, 450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Infinity race");

    // OpenGL init
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);

}

void funcInit(){

    // callback init
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);
    glutKeyboardFunc(onKeyboard);

    // initialize rand for all calls
    srand(time(NULL));

    // initialize objects array
    initObjects();
}

