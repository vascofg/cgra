#include "myUnitCube.h"

void myUnitCube::draw() {

	glPushMatrix();
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(270, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glRotated(270, 0, 1, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glRectf(0, 0, 1, 1);
	glPopMatrix();

}
