#include "myFloor.h"
#include "myUnitCube.h"

void myFloor::draw() {
	myUnitCube f;
	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(8, 0.1, 6);
	f.draw();
	glPopMatrix();
}
