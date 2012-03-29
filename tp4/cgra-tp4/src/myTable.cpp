#include "myTable.h"
#include "myUnitCube.h"
#include "textures.h"

void myTable::draw() {
	myUnitCube p1, p2, p3, p4, t;
	tableAppearance *texture = new tableAppearance();
	// Coefficients for material of feets
	float amb1[3] = { 0.11875, 0.11875, 0.11875 };
	float dif1[3] = { 0.11875, 0.11875, 0.11875 };
	float spec1[3] = { 0.93, 0.93, 0.93 };
	float shininess1 = 12.f;
	CGFappearance *materialF = new CGFappearance(amb1, dif1, spec1, shininess1);
	materialF->apply();
	glPushMatrix();
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
	glPopMatrix();

	glPushMatrix();
	texture->apply();
	glPushMatrix();
	glTranslated(0, 3.5, 0);
	glScaled(5, 0.3, 3);
	t.draw();
	glPopMatrix();

	glPopMatrix();

}
