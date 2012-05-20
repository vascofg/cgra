/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#include "myTable.h"
#include "myUnitCube.h"
#include "myMaterials.h"
myTable::myTable(){
	// Material of top table
	materialTop = new tableAppearance();

	// Coefficients for material of feets
	float amb1[3] = { 0.11875, 0.11875, 0.11875 };
	float dif1[3] = { 0.11875, 0.11875, 0.11875};
	float spec1[3] = {0.93, 0.93, 0.93 };
	float shininess1 = 12.f;
	materialFeets = new CGFappearance(amb1, dif1, spec1, shininess1);

	// objects
	p1=new myUnitCube();
	p2=new myUnitCube();
	p3=new myUnitCube();
	p4=new myUnitCube();
	t=new myUnitCube();
}
void myTable::draw() {
	// The feets
	glPushMatrix();
		materialFeets->apply();
		glPushMatrix();
		glTranslated(-2, 1.75, -1);
		glScaled(0.3, 3.5, 0.3);
		p1->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2, 1.75, 1);
		glScaled(0.3, 3.5, 0.3);
		p2->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslated(2, 1.75, 1);
		glScaled(0.3, 3.5, 0.3);
		p3->draw();
		glPopMatrix();

		glPushMatrix();
		glTranslated(2, 1.75, -1);
		glScaled(0.3, 3.5, 0.3);
		p4->draw();
		glPopMatrix();
	glPopMatrix();
	
	// the table
	glPushMatrix();
		materialTop->apply();
		glPushMatrix();
		glTranslated(0, 3.5, 0);
		glScaled(5, 0.3, 3);
		t->draw();
		glPopMatrix();

	glPopMatrix();

}
