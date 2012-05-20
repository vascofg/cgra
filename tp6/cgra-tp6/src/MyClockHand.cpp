#include "MyClockHand.h"
#include "myMaterials.h"

void MyClockHand::setAngle(float angle) {
    this->angle = angle;
}

void MyClockHand::setScale(float x,float y, float z) {
    xScale=x;
    yScale=y;
    zScale=z;
}

MyClockHand::MyClockHand() {
    // Variables initialization
    xScale=1;
    yScale=1;
    zScale=1;
}

void MyClockHand::draw() {
    
    // Rotate in clockwise
    glRotated(-angle, 0, 0, 1);
    pointerAppearance material;
    material.apply();

    // Basic Shape
    glPushMatrix();
    glScaled(xScale,yScale,zScale);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.05, 0, 0);
        glVertex3f(0.05, 0, 0);
        glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();

}
