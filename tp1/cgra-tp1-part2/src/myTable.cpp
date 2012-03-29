#include "myTable.h"
#include "myUnitCube.h"

void myTable::draw() {
	myUnitCube p1, p2, p3, p4, t;
	glPushMatrix();
	glTranslated(-2, 1.75, -1);
	glScaled(0.3, 3.5, 0.3);
	p1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 1.75, 1);
	glScaled(0.3, 3.5, 0.3);
	p2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 1.75, 1);
	glScaled(0.3, 3.5, 0.3);
	p3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 1.75, -1);
	glScaled(0.3, 3.5, 0.3);
	p4.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 3.5, 0);
	glScaled(5, 0.3, 3);
	t.draw();
	glPopMatrix();
}
