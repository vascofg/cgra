#include "myFloor.h"
#include "myUnitCube.h"

void myFloor::draw() {
	myUnitCube f;
	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(25, 0.1, 25);
	f.draw();
	glPopMatrix();
}
