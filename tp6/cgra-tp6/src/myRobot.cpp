#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
using namespace std;

myRobot::myRobot(int stacks) {
    rotAngle = -157.5;
    quadric = gluNewQuadric();
    this->stacks=stacks;
}

void myRobot::draw() {
    //DRAW THE TRIANGLE
    
    glPushMatrix();
        glTranslated(moveX, 0, moveZ);
        glRotated(rotAngle, 0, 1, 0);
        /*glBegin(GL_TRIANGLES);
        glVertex3d(0.5, 0.3, 0);
        glVertex3d(-0.5, 0.3, 0);
        glVertex3d(0, 0.3, 2);
        glEnd();*/
        glPushMatrix();
            glRotated(-90,1,0,0);
            glPushMatrix();
                glTranslated(0, 0, 1);
                gluDisk(quadric,0, 0.5, 12, 1);
            glPopMatrix();
            gluCylinder(quadric,1, 0.5, 1, 4, stacks);
        glPopMatrix();
    glPopMatrix();

}

void myRobot::update(long milis) {

}