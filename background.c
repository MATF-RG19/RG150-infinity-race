#include "incl/background.h"

float colorChange=1;

float colorChangeSpeedUpdate=0.1;


void drawTrack(){

    // create path/borders
    glLineWidth(100);
    glBegin(GL_LINES);
        glVertex3f(-1, -0.5, 100);
        glVertex3f(-1, -0.5, -100);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(7, -0.5, 100);
        glVertex3f(7, -0.5, -100);
    glEnd();

    
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, names[0]);
        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);

            // first solution
            glTexCoord2f(0, 0);
            glVertex3f(-1, -0.5, 100);
            glTexCoord2f(0, 937);
            glVertex3f(-1, -0.5, -100);          
            glTexCoord2f(1317, 937);
            glVertex3f(7, -0.5, -100);
            glTexCoord2f(1317, 0);
            glVertex3f(7, -0.5, 100);



            // second solution
            // glTexCoord2f(0, 0.051);
            // glVertex3f(-1, -0.5, 100);
            // glTexCoord2f(0.5, 0.051);
            // glVertex3f(-1, -0.5, 0);          
            // glTexCoord2f(0.5, 0);
            // glVertex3f(7, -0.5, 0);
            // glTexCoord2f(0, 0);
            // glVertex3f(7, -0.5, 100);

            // glTexCoord2f(0, 0.051);
            // glVertex3f(-1, -0.5, 0);
            // glTexCoord2f(0.5, 0.051);
            // glVertex3f(-1, -0.5, -100);          
            // glTexCoord2f(0.5, 0);
            // glVertex3f(7, -0.5, -100);
            // glTexCoord2f(0, 0);
            // glVertex3f(7, -0.5, 0);
            


            // third solution
            // glTexCoord2f(0, 1);
            // glVertex3f(-1, -0.5, 100);
            // glTexCoord2f(1, 1);
            // glVertex3f(-1, -0.5, -100);          
            // glTexCoord2f(1, 0);
            // glVertex3f(7, -0.5, -100);
            // glTexCoord2f(0, 0);
            // glVertex3f(7, -0.5, 100);


            
        glEnd();
        glDisable(GL_TEXTURE_2D);

        
        
        int i=1;


        // color of left portion of background
        for (i = 1; i < 20; i++) {

            // setting color using i and colorChange parameter
            switch (i%(int)colorChange) {
                case 0:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen3);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen3);
                    break;
                case 1:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialYellow1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialYellow1);
                    break;
                case 2:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen1);
                    break;
                case 3:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialBlue1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialBlue1);
                    break;
                case 4:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialRed1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialRed1);
                    break;
                case 5:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen2);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen2);
                    break;
            }
        }

        // drawing polygon which represents left portion of background
        glBegin(GL_POLYGON);
        
            glVertex3f(-1, -0.5, 100);
            glVertex3f(-1, -0.5, -120);
            glVertex3f(-100, -0.5, -120);
            glVertex3f(-100, -0.5, 100);

        glEnd();


        int j=1;

        // color of right portion of background
        for(j=1;j<20;j++){
            switch (j%(int)(colorChange+1)) {
                case 0:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen3);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen3);
                    break;
                case 1:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialYellow1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialYellow1);
                    break;
                case 2:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialPurple1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialPurple1);
                    break;
                case 3:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialBlue1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialBlue1);
                    break;
                case 4:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialRed1);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialRed1);
                    break;
                case 5:
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialGreen2);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialGreen2);
                    break;
            }
        }
        
        // drawing polygon which represents right portion of background
        glBegin(GL_POLYGON);
        
            glVertex3f(7, -0.5, 100);
            glVertex3f(7, -0.5, -100);
            glVertex3f(100, -0.5, -100);
            glVertex3f(100, -0.5, 100);
            
        glEnd();

    

    glPopMatrix();

}
