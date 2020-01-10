#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


/*callback function declarations*/
static void onDisplay(void);
static void onReshape(int width, int height);
static void onKeyboard(unsigned char key, int x, int y);

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

    

    // create objects
    
    

    glColor3f(0, 1, 0);

    // create path/borders
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex3f(-1, 0, 10);
    glVertex3f(-1, 0, -100);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(7, 0, 10);
    glVertex3f(7, 0, -100);
    glEnd();


    glShadeModel(GL_SMOOTH);



    // send new image to screen
    glutSwapBuffers();
}

static void onReshape(int width, int height){

    // set the viewport
    glViewport(0, 0, width, height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width / height, 1, 100);
    glMatrixMode (GL_MODELVIEW);
}

static void onKeyboard(unsigned char key, int x, int y){
    switch (key) {
        // end program (ESC)
        case 27:
            exit(0);
            break;
    }
}