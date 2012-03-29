#include "myUnitCube.h"

void myUnitCube::draw() {

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glTranslated(-0.5, -0.5, 0.5);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glRotated(90, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glRotated(180, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glRotated(270, 1, 0, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glRotated(90, 0, 1, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glRotated(270, 0, 1, 0);
	glTranslated(-0.5, -0.5, 0.5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();

}
