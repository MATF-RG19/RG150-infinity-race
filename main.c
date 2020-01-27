#include "incl/initialize.h"













int main(int argc, char **argv){

    glutInitNew(&argc,argv);
    funcInit();
    initTexture();
    
    // starting main loop
    glutMainLoop();

  return 0;
}










