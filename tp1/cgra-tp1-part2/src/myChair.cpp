#include "myChair.h"
#include "myUnitCube.h"

myChair::myChair() {
	angle=rand()%41-20;
}

void myChair::draw() {
	myUnitCube p1, p2, p3, p4, a, c;
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	glPushMatrix();
	glTranslated(-0.75, 1.25, -0.75);
	glScaled(0.3, 2.5, 0.3);
	p1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.75, 1.25, 0.75);
	glScaled(0.3, 2.5, 0.3);
	p2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.75, 1.25, 0.75);
	glScaled(0.3, 2.5, 0.3);
	p3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.75, 1.25, -0.75);
	glScaled(0.3, 2.5, 0.3);
	p4.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.5, 0);
	glScaled(2, 0.3, 2);
	a.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 3.85, -0.85);
	glScaled(2, 3, 0.3);
	c.draw();
	glPopMatrix();
	glPopMatrix();
}
