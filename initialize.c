#include "incl/initialize.h"


float animationSpeedParameter=1;
int animationActive=0;
int animationActiveRight=0;
int animationActiveLeft=0;
bool endGame=false;
float score=0;
char text[SIZE]="Press U to start / pause game or ESC to quit"; 
char textCam[SIZE]="Press C to change camera"; 


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

void initTexture(){
    /* Objekat koji predstavlja teskturu ucitanu iz fajla */
    Image * image;

    /* Ukljucuju se teksture. */
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    /*
     * Inicijalizuje se objekat koji ce sadrzati teksturu ucitanu iz
     * fajla
     */
    image = imageInit(0, 0);

    /* Kreira se tekstura*/
    imageRead(image, TEXTURE);

    /* Generisu se identifikatori tekstura. */
    glGenTextures(1, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    /*Iskljucujemo aktivnu teksturu*/
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    imageDone(image);
    // glDisable(GL_TEXTURE_2D);
}