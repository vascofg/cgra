#include "myCylinder.h"
#include <iostream>
using namespace std;
myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->stacks = stacks;

}

void myCylinder::draw() {
	// WARNING: muse have float or will use the quocient
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);
	double baseWidth = sin(2 * acos(-1) / (float)slices);
	double apothem = (tan(baseAngleR / 2));

	for( int j=0; j<stacks; j++){
		glPushMatrix();
		glTranslated(0, j, 0);
		for (int i = 0; i < slices; i++) {
			glPushMatrix();

			// Face rectangle

			glNormal3f(1, 0, 0); // need to define normal to x
			glRotated(i * baseAngle, 0, 1, 0);
			glTranslated((baseWidth / 2) / apothem, 0, 0);
			glRotated(-90, 0, 1, 0);
			glRectd(baseWidth / 2, 0, -baseWidth / 2, 1);

			// Top triangle
			glNormal3f(0, 1, 0); // need to define normal to y
			glBegin(GL_TRIANGLES);
			glVertex3d(baseWidth / 2, 1, 0);
			glVertex3d(-baseWidth / 2, 1, 0);
			glVertex3d(0, 1, 1);
			glEnd();

			// Bottom triangle
			glNormal3f(0,-1,0);// need to define normal to -y
			glBegin(GL_TRIANGLES);
			glVertex3d(baseWidth / 2, 0, 0);
			glVertex3d(0, 0, 1);
			glVertex3d(-baseWidth / 2, 0, 0);
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
	}
}
