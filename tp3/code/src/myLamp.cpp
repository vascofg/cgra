#include "myLamp.h"
#include <iostream>
using namespace std;
myLamp::myLamp(int slices , bool smooth) {
	this->slices = slices;
	this->smooth = smooth;

}

void myLamp::draw() {
	// WARNING: muse have float or will use the quocient
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);
	double baseWidth = sin(2 * acos(-1) / (float)slices);
	double apothem = (tan(baseAngleR / 2));

	if(smooth)glShadeModel(GL_SMOOTH);
	else glShadeModel(GL_FLAT);

	int l=0; // used for translation
	// The function x=sqrt(1-y^2) , where the radius is 1, goes from 0 to 1, soo the step must be 0.01
	for( float j=0.01; j<=1; j=j+0.01,l++){
		glPushMatrix();
		// Translate 0.01 in y
		glTranslated(0, l*0.01, 0);
		// Here is where the magic goes :D
		glScaled(sqrt(1-j*j),0.01,sqrt(1-j*j));
		for (int i = 0; i < slices; i++) {
			glPushMatrix();

			// Face rectangle

			glNormal3f(1, 0, 0); // need to define normal to x
			glRotated(i * baseAngle, 0, 1, 0);
			glTranslated((baseWidth / 2) / apothem, 0, 0);
			glRotated(-90, 0, 1, 0);
			glRectd(baseWidth / 2, 0, -baseWidth / 2, 1);

			// Top triangle
			glNormal3f(0, 1, 0); // need to define normal to y
			glBegin(GL_TRIANGLES);
			glVertex3d(baseWidth / 2, 1, 0);
			glVertex3d(-baseWidth / 2, 1, 0);
			glVertex3d(0, 1, 1);
			glEnd();

			// Bottom triangle
			glNormal3f(0,-1,0);// need to define normal to -y
			glBegin(GL_TRIANGLES);
			glVertex3d(baseWidth / 2, 0, 0);
			glVertex3d(0, 0, 1);
			glVertex3d(-baseWidth / 2, 0, 0);
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
	}
}
