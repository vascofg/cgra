#include "myCylinder.h"
#include <iostream>

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
	this->slices = slices;
	this->stacks = stacks;
}

void myCylinder::draw() {
	double baseAngle = (360 / slices);
	double baseAngleR = (2 * acos(-1) / slices);
	double baseWidth = sin(2 * acos(-1) / slices);
	double apothem = (tan(baseAngleR / 2));

	for (int i = 0; i < slices; i++) {
		glPushMatrix();
		glRotated(i * baseAngle, 0, 1, 0);
		glTranslated((baseWidth / 2) / apothem, 0, 0);
		glRotated(-90, 0, 1, 0);
		glRectd(baseWidth / 2, 0, -baseWidth / 2, 1);
		glBegin(GL_TRIANGLES);
		glVertex3d(baseWidth / 2, 1, 0);
		glVertex3d(-baseWidth / 2, 1, 0);
		glVertex3d(0, 1, 1);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3d(baseWidth / 2, 0, 0);
		glVertex3d(0, 0, 1);
		glVertex3d(-baseWidth / 2, 0, 0);
		glEnd();
		glPopMatrix();
	}
}
