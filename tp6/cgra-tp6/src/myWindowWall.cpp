/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#include "myWindowWall.h"
#include "myMaterials.h"
myWindowWall::myWindowWall(){
		landscapeMaterial= new landscapeAppearance();

};

void myWindowWall::draw() {

	// Plane with window
	for (int unsigned h = 0; h < 3; h++) {
		for (int unsigned i = 0; i < 3; i++) {
			if(!(h==1 && i==1)){
			glPushMatrix();
				glBegin(GL_QUADS);
						glTexCoord2f(1.75-i*0.825,0.1+h*0.85);glVertex3d(0, 8 / 3.0 + h * 8 / 3.0, 0 + i * 5);
						glTexCoord2f(0.90-i*0.825,0.1+h*0.85);glVertex3d(0, 8 / 3.0 + h * 8 / 3.0, 5 + i * 5);
						glTexCoord2f(0.90-i*0.825,-0.8+h*0.85);glVertex3d(0, 0 + h * 8 / 3.0, 5 + i * 5);
						glTexCoord2f(1.75-i*0.825,-0.8+h*0.85); glVertex3d(0, 0 + h * 8 / 3.0, 0 + i * 5);
				glEnd();
			glPopMatrix();
			}
		}
	}


	landscapeMaterial->apply();
	// Landscape
	glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(1,1); glVertex3d(-7,10,-5);
		glTexCoord2f(0,1); glVertex3d(-7,10,20);
		glTexCoord2f(0,0); glVertex3d(-7,-5,20);
		glTexCoord2f(1,0); glVertex3d(-7,-5,-5);
		glEnd();
	glPopMatrix();
}
