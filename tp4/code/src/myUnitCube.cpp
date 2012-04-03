#include "myUnitCube.h"

void myUnitCube::draw() {

	// side faces
	for(int i=0; i<4; i++){
		glPushMatrix();
			glRotated(90*i,0,1,0); // rotate in y-axis
			glNormal3f(0,0,1);
			glTranslated(-0.5, -0.5, 0.5);
			glBegin(GL_QUADS);
				// anti-clockwise
				glTexCoord2f(0,0); glVertex3f(0,0,0);
				glTexCoord2f(1,0); glVertex3f(1,0,0);
				glTexCoord2f(1,1); glVertex3f(1,1,0);
				glTexCoord2f(0,1); glVertex3f(0,1,0);
			glEnd();
		glPopMatrix();
	}
	
	// top and bottom
	for(int i=0; i<2; i++){
		glPushMatrix();
			glRotated(180*i,0,0,1); // rotate in z-axis
			glNormal3f(0,-1,0);
			glTranslated(-0.5, -0.5, -0.5);
			glBegin(GL_QUADS);
				// clockwise because it starts from the bottom
				glTexCoord2f(0,0); glVertex3f(0,0,0);
				glTexCoord2f(1,0); glVertex3f(1,0,0);
				glTexCoord2f(1,1); glVertex3f(1,0,1);
				glTexCoord2f(0,1); glVertex3f(0,0,1);
			glEnd();
		glPopMatrix();
	
	}

}
