#include "initialize.h"













int main(int argc, char **argv){

    glutInitNew(&argc,argv);
    funcInit();

    // starting main loop
    glutMainLoop();

  return 0;
}










