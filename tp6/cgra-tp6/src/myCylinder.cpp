/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#include "myCylinder.h"
#include <iostream>
#define PI acos(-1)
using namespace std;
myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->stacks = stacks;
	this->smooth=smooth;
	baseAngle = (360 / (float)slices);
	baseAngleR = (2 * PI / (float)slices);
	baseWidth = sin(2 * PI / (float)slices);
	apothem = (tan(baseAngleR / 2));
}

void myCylinder::draw() {

	// Smoothing
	if(smooth) glShadeModel(GL_SMOOTH);
	else glShadeModel(GL_FLAT);

	// Draw the cylinder
	for( int j=0; j<stacks; j++){ // for every stack
		glPushMatrix();
		glTranslated(0, j, 0);

		for (int i = 0; i < slices; i++) { // for every cylinder face
			glPushMatrix();

			// Face rectangle
			glNormal3f(1, 0, 0); // need to define normal to x
			glRotated(i * baseAngle, 0, 1, 0);
			glTranslated((baseWidth / 2) / apothem, 0, 0);
			glRotated(-90, 0, 1, 0);

			glBegin(GL_QUADS);
				glTexCoord2f(0,0.3); glVertex3d(-baseWidth / 2, 0,0);
				glTexCoord2f(0.2,0.3); glVertex3d(-baseWidth / 2, 1,0);			
				glTexCoord2f(0.2,0); glVertex3d(baseWidth / 2, 1,0);
				glTexCoord2f(0,0.1); glVertex3d(baseWidth / 2, 0,0);
			glEnd();

			// Top triangle
			glNormal3f(0, 1, 0); // need to define normal to y
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0,360/(float)slices); glVertex3d(baseWidth / 2, 1, 0);
				glTexCoord2f(0.5,0.5); glVertex3d(-baseWidth / 2, 1, 0);
				glTexCoord2f(360/(float)slices,360/(float)slices); glVertex3d(0, 1, 1);
			glEnd();

			// Bottom triangle
			glNormal3f(0,-1,0);// need to define normal to -y
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0,0);  glVertex3d(baseWidth / 2, 0, 0);
				glTexCoord2f(0.2,0.3); glVertex3d(0, 0, 1);
				glTexCoord2f(0,0.3); glVertex3d(-baseWidth / 2, 0, 0);
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
	}
}
