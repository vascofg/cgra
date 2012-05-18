#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
using namespace std;

myRobot::myRobot(int stacks) {
	rotAngle = -157.5;
	quadric = gluNewQuadric();
	this->stacks = stacks;
}

void myRobot::draw() {

	// Some pre-calculus
	int slices=12;
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);
	double baseWidth = sin(2 * acos(-1) *0.25/ (float)slices);
	double apothem = (tan(baseAngleR / 2));

	// (1) The robot translations and rotations
	glTranslated(moveX, 0, moveZ);
	glRotated(rotAngle, 0, 1, 0);

	// (2) Let the Robot draw begin
	glPushMatrix();
	// ->

		// square
		glBegin(GL_QUADS);
			glVertex3d(-0.5, 0, -0.5);
			glVertex3d(-0.5, 0, 0.5);
			glVertex3d(0.5, 0, 0.5);
			glVertex3d(0.5, 0, -0.5);
		glEnd();

		/* circle*/
		glPushMatrix();
			glRotated(180 / 12, 0, 1, 0);
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, 1);
			gluDisk(quadric, 0, 0.25, 12, 1);
		glPopMatrix();


		// side rectangles
		for( int j=0; j<stacks; j++){
				glPushMatrix();
				glTranslated(0, j, 0);
				for (int i = 0; i < 1; i++) {
					glPushMatrix();

					// Face rectangle

					glNormal3f(1, 0, 0); // need to define normal to x
					glRotated((i+3) * baseAngle, 0, 1, 0); // i-1 to align with the square
					glTranslated((baseWidth / 2) / apothem, 0, 0);
					glRotated(-90, 0, 1, 0);

					//glRectd(baseWidth / 2, 0, -baseWidth / 2, 1);
					glBegin(GL_QUADS);
						glTexCoord2f(0,0.3); glVertex3d(-0.5+1/3.0, 0,0);
						glTexCoord2f(0.2,0.3); glVertex3d(-baseWidth / 2, 1,0);
						glTexCoord2f(0.2,0); glVertex3d(baseWidth / 2, 1,0);
						glTexCoord2f(0,0.1); glVertex3d(-0.5+2/3.0, 0,0);
					glEnd();


					glPopMatrix();
				}
				glPopMatrix();
			}
	// ->
	glPopMatrix();

}

void myRobot::update(long milis) {

}
