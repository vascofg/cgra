#include "myCylinder.h"
#include <iostream>

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
	this->slices = slices;
	this->stacks = stacks;
}

void myCylinder::draw() {
	float baseAngle = (360 / slices);
	float baseAngleR = (2*acos(-1) / slices);
	float baseWidth = sin(2*acos(-1) / slices);
	float apothem = (tan(baseAngleR / 2));

	for (int i = 0; i < slices; i++) {
		glPushMatrix();
		glRotatef(i * baseAngle, 0, 1, 0);
		glTranslatef((baseWidth / 2) / apothem, 0, 0);
		glRotatef(-90, 0, 1, 0);
		glBegin(GL_TRIANGLES);
			glVertex3f(0, 1, 0);
			glVertex3f(apothem, 1, baseWidth/2);
			glVertex3f(apothem, 1, -baseWidth/2);
		glEnd();
		glRectf(baseWidth / 2, 0, -baseWidth / 2, 1);
		glPopMatrix();
	}
}
