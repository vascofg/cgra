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
	//DRAW THE TRIANGLE
	double baseWidth = sin(2 * acos(-1) / (float) 12);
	//glPushMatrix();
	//glTranslated(moveX, 0, moveZ);
	//glRotated(rotAngle, 0, 1, 0);
	/*glBegin(GL_TRIANGLES);
	 glVertex3d(0.5, 0.3, 0);
	 glVertex3d(-0.5, 0.3, 0);
	 glVertex3d(0, 0.3, 2);
	 glEnd();*/
	glPushMatrix();
	// circle
	glPushMatrix();
	glRotated(180 / 12, 0, 1, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(0, 0, 1);
	gluDisk(quadric, 0, 0.25, 12, 1);
	glPopMatrix();

	// square
	glBegin(GL_QUADS);
	glVertex3d(-0.5, 0, -0.5);
	glVertex3d(-0.5, 0, 0.5);
	glVertex3d(0.5, 0, 0.5);
	glVertex3d(0.5, 0, -0.5);
	glEnd();

	// rectangle
	glBegin(GL_QUADS);
	glVertex3d(-0.5 + 1 / 3.0, 0, 0.5);
	glVertex3d(-0.5 + 2 / 3.0, 0, 0.5);
	glVertex3d(baseWidth / 8, 1, 0.25);
	glVertex3d(-baseWidth / 8, 1, 0.25);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(-0.5, 0, 0.5);
	glVertex3d(-0.5 + 1 / 3.0, 0, 0.5);
	glVertex3d(-baseWidth / 8, 1, 0.25);
	glVertex3d(-baseWidth / 4, 1, 0.125);
	glEnd();
	glPopMatrix();

}

void myRobot::update(long milis) {

}
