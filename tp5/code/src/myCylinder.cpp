#include "myCylinder.h"
#include <iostream>
using namespace std;
myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->stacks = stacks;
	this->smooth=smooth;

}

void myCylinder::draw() {
	// WARNING: muse have float or will use the quocient
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);
	double baseWidth = sin(2 * acos(-1) / (float)slices);
	double apothem = (tan(baseAngleR / 2));
	if(smooth)glShadeModel(GL_SMOOTH);
	else glShadeModel(GL_FLAT);
	for( int j=0; j<stacks; j++){
		glPushMatrix();
		glTranslated(0, j, 0);
		for (int i = 0; i < slices; i++) {
			glPushMatrix();

			// Face rectangle
			
			glNormal3f(1, 0, 0); // need to define normal to x
			glRotated(i * baseAngle, 0, 1, 0);
			glTranslated((baseWidth / 2) / apothem, 0, 0);
			glRotated(-90, 0, 1, 0);
			//glRectd(baseWidth / 2, 0, -baseWidth / 2, 1);
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
