/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#include "MyClockHand.h"

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

    // material
    pointerMaterial= new pointerAppearance();
}

void MyClockHand::draw() {
    
    // Rotate in clockwise
    glRotated(-angle, 0, 0, 1);
    pointerMaterial->apply();

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
