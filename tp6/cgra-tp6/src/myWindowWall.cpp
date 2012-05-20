#include "myWindowWall.h"
void myWindowWall::draw() {
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
}
