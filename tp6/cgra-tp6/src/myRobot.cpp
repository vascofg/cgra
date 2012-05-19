#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
#include <myVertex.h>
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
	double baseWidth = sin(2 * acos(-1) *0.25/ (float)slices); // 0.25 is the radius
	double apothem = (tan(baseAngleR / 2));
	double heightTop=1;

	// (1) The robot translations and rotations
	glTranslated(moveX, 0, moveZ);
	glRotated(rotAngle, 0, 1, 0);

	// (2) Let the Robot draw begin
	glPushMatrix();
	// ->

	for (int i = 0; i < 12; i++) {
		glPushMatrix();
		glNormal3f(1, 0, 0); // need to define normal to x
		glRotated((i-2) * baseAngle, 0, 1, 0);
		glTranslated((baseWidth / 2) / apothem, 0, 0);
		glRotated(-90, 0, 1, 0);
		// Top triangle
					glNormal3f(0, 1, 0); // need to define normal to y
					glBegin(GL_TRIANGLES);
						glTexCoord2f(0,360/(float)slices); glVertex3d(baseWidth / 2, 1, 0);
						glTexCoord2f(0.5,0.5); glVertex3d(-baseWidth / 2, 1, 0);
						glTexCoord2f(360/(float)slices,360/(float)slices); glVertex3d(0, 1, 0.25);
					glEnd();
		glPopMatrix();
	}


		// square
		glBegin(GL_QUADS);
			glVertex3d(-0.5, 0, -0.5);
			glVertex3d(-0.5, 0, 0.5);
			glVertex3d(0.5, 0, 0.5);
			glVertex3d(0.5, 0, -0.5);
		glEnd();

		/* circle
		glPushMatrix();
			glRotated(180 / 12, 0, 1, 0);
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, 1);
			gluDisk(quadric, 0, 0.25, 12, 1);
		glPopMatrix();
		*/

		// Compute the first triangle points
		double zl=0.25*cos(baseAngleR*3/2.0);
		double zr=0.25*cos(baseAngleR*1/2.0);
		double xl=0.25*sin(baseAngleR*3/2.0);
		double xr=0.25*sin(baseAngleR*1/2.0);


		// side rectangles
		for( int j=0; j<stacks; j++){
				glPushMatrix();
					glTranslated(0, j, 0);
					// Rotate and copy the 3 faces
					for(int l=0; l<4; l++){
						glPushMatrix();
						glRotated(90*l,0,1,0);
						for (int i = 0; i < 3; i++) {
							myVertex triangleLeft(xl,1,zl);
							triangleLeft.rotateY(-baseAngleR*i);
							myVertex triangleRight(xr,1,zr);
							triangleRight.rotateY(-baseAngleR*i);
							   // Draw one face
								glNormal3f(0,1,0);
								glBegin(GL_QUADS);
									// Computing the connections on top
									glVertex3d(0.5-1/3.0*i , 0 ,0.5);
									glVertex3d(triangleLeft.x, 1 ,triangleLeft.z);
									glVertex3d(triangleRight.x, 1 ,triangleRight.z);
									glVertex3d((0.5-1/3.0)-1/3.0*i, 0,0.5);
								glEnd();

						}
						glPopMatrix();
					}
				glPopMatrix();
			}
	// ->
	glPopMatrix();

}

void myRobot::update(long milis) {

}
