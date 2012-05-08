#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
using namespace std;

myRobot::myRobot() {
    rotAngle = -157.5;
}

void myRobot::draw() {
    //DRAW THE TRIANGLE
    glPushMatrix();
        glTranslated(moveX, 0, moveZ);
        glRotated(rotAngle, 0, 1, 0);
        glBegin(GL_TRIANGLES);
        glVertex3d(0.5, 0.3, 0);
        glVertex3d(-0.5, 0.3, 0);
        glVertex3d(0, 0.3, 2);
        glEnd();
    glPopMatrix();

}

void myRobot::update(long milis) {

}