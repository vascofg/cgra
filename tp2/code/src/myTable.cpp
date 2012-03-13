#include "myTable.h"
#include "myUnitCube.h"

void myTable::draw() {
	myUnitCube p1, p2, p3, p4, t;
	// Coefficients for material
	float amb[3] = { 0.6, 0.41, 0.094 };
	float dif[3] = { 0.3, 0.205, 0.047 };
	float spec[3] = { 0, 0, 0 };
	float shininess = 12.f;
	material = new CGFappearance(amb, dif, spec, shininess);
	glPushMatrix();
		material->apply();

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
	glPopMatrix();

}
