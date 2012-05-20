#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
#include <myVertex.h>
using namespace std;

myRobot::myRobot(int stacks) {
	rotAngle = -157.5;
	this->stacks = stacks;
	// Some pre-calculus
	slices=12;
	topRadius=0.25;
	baseAngle = (360 / (float)slices);
    baseAngleR = (2 * acos(-1) / (float)slices);
	baseWidth = sin(2 * acos(-1) *topRadius/ (float)slices); // 0.25 is the radius
    apothem = (tan(baseAngleR / 2));
	heightTop=1;
	computeCoords(coords,UVCoords,normals);
}

void myRobot::draw() {
	// (1) Specify the draw mode of the robot (texture of wireframe)
	if(drawMode==1) glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	// (2) The robot translations and rotations
	glTranslated(moveX, 0, moveZ);
	glRotated(rotAngle, 0, 1, 0);

	// (3) Let the Robot draw begin
	glPushMatrix();
		drawTop();
		drawBottom();

	// The necessary index
	int UVIndex=0, coordIndex=0, normalsIndex=0;
	for( int j=0; j<stacks; j++){ // stacks
		glPushMatrix();

			for(int l=0; l<4; l++){ // the 4 square faces
				glPushMatrix();
					glRotated(-90*l,0,1,0);

						for (int i = 0; i < 3; i++) { // a face set of rectangles

							glNormal3f(normals[normalsIndex]->x,normals[normalsIndex]->y,normals[normalsIndex]->z);
							normalsIndex++;


							// Reactangle draw
							glBegin(GL_QUADS);
								glTexCoord2f(UVCoords[UVIndex]->x,UVCoords[UVIndex]->y ); glVertex3d(coords[coordIndex]->x , coords[coordIndex]->y ,coords[coordIndex]->z);
								UVIndex++; coordIndex++;
								glTexCoord2f(UVCoords[UVIndex]->x,UVCoords[UVIndex]->y );  glVertex3d(coords[coordIndex]->x , coords[coordIndex]->y ,coords[coordIndex]->z);
								UVIndex++; coordIndex++;
								glTexCoord2f(UVCoords[UVIndex]->x,UVCoords[UVIndex]->y );  glVertex3d(coords[coordIndex]->x , coords[coordIndex]->y ,coords[coordIndex]->z);
								UVIndex++; coordIndex++;
								glTexCoord2f(UVCoords[UVIndex]->x,UVCoords[UVIndex]->y ); glVertex3d(coords[coordIndex]->x , coords[coordIndex]->y ,coords[coordIndex]->z);
								UVIndex++; coordIndex++;
							glEnd();

						}
				glPopMatrix(); // matrix of face set of rectangles
					}
		glPopMatrix(); //  matrix of the 4 square faces
			}


	// END ROBOT DRAW ->
	glPopMatrix();
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void myRobot::update(long milis) {

}

void myRobot::computeCoords(vector<myVertex*> &coords,vector<myVertex*> &UVCoords,vector<myVertex*> &normals){
	// Compute the top triangle joint initial poins
	double zl=0.25*cos(baseAngleR*3/2.0);
	double zr=0.25*cos(baseAngleR*1/2.0);
	double xl=0.25*sin(baseAngleR*3/2.0);
	double xr=0.25*sin(baseAngleR*1/2.0);

	for( int j=0; j<stacks; j++){ // stacks
		for(int l=0; l<4; l++){ // the 4 square faces
			for (int i = 0; i < 3; i++) { // a face set of rectangles
				// Compute the triangle joints
				myVertex triangleLeft(xl,1,zl);
				triangleLeft.rotateY(-baseAngleR*i);
				myVertex triangleRight(xr,1,zr);
				triangleRight.rotateY(-baseAngleR*i);

				// Draw a rectangle from the square to the triangle joint
				// Compute a semi rect from the square to triangle
				myVertex *v1,*v2,*v3,*v4;
				v1=new myVertex(0.5-1/3.0*i,0,0.5);
				v2=new myVertex(triangleLeft.x, 1 ,triangleLeft.z);
				v3=new myVertex((0.5-1/3.0)-1/3.0*i, 0,0.5);
				v4=new myVertex(triangleRight.x, 1 ,triangleRight.z);
				mySemiRect left(v1,v2,stacks);
				mySemiRect right(v3,v4,stacks);

				// Compute the normal
				vector <myVertex> polVertexs;
				polVertexs.push_back(*v1);
				polVertexs.push_back(*v2);
				polVertexs.push_back(*v3);
				polVertexs.push_back(*v4);
				myVertex normal=computeNormalNewel(polVertexs);

				// Compute the UV coordinates
				myVertex s1=*v1; s1.translate(0.5,0,0); s1.y=0;
				myVertex c1=*v2; c1.translate(0.5,-0.5,0);
				myVertex s2=*v3; s2.translate(0.5,0,0); s2.y=0;
				myVertex c2=*v4; c2.translate(0.5,-0.5,0);

				// Transformations of UV
				s1.translate(-0.5,-0.5,0);
				s2.translate(-0.5,-0.5,0);
				c1.translate(-0.5,-0.5,0);
				c2.translate(-0.5,-0.5,0);
				s1.rotateZ(-l*acos(-1)/2.0);
				s2.rotateZ(-l*acos(-1)/2.0);
				c1.rotateZ(-l*acos(-1)/2.0);
				c2.rotateZ(-l*acos(-1)/2.0);
				s1.translate(0.5,0.5,0);
				s2.translate(0.5,0.5,0);
				c1.translate(0.5,0.5,0);
				c2.translate(0.5,0.5,0);

				// Parametric semi-rects
				mySemiRect UVleft(&s1,&c1,stacks);
				mySemiRect UVright(&s2,&c2,stacks);

				// Save the computed coords
				glTexCoord2f(UVleft.getVertexT(j).x,UVleft.getVertexT(j).y ); glVertex3d(left.getVertexT(j).x , left.getVertexT(j).y ,left.getVertexT(j).z);
				glTexCoord2f(UVleft.getVertexT(j+1).x,UVleft.getVertexT(j+1).y); glVertex3d(left.getVertexT(j+1).x , left.getVertexT(j+1).y ,left.getVertexT(j+1).z);
				glTexCoord2f(UVright.getVertexT(j+1).x,UVright.getVertexT(j+1).y); glVertex3d(right.getVertexT(j+1).x , right.getVertexT(j+1).y ,right.getVertexT(j+1).z);
				glTexCoord2f(UVright.getVertexT(j).x , UVright.getVertexT(j).y); glVertex3d(right.getVertexT(j).x , right.getVertexT(j).y ,right.getVertexT(j).z);

				// Normals
				myVertex *normalP= new myVertex(-normal.x,-normal.y,-normal.z);
				normals.push_back(normalP);

				// UV
				myVertex *uv1,*uv2,*uv3,*uv4;
				uv1=new myVertex(UVleft.getVertexT(j).x,UVleft.getVertexT(j).y,UVleft.getVertexT(j).z);
				uv2=new myVertex(UVleft.getVertexT(j+1).x,UVleft.getVertexT(j+1).y,UVleft.getVertexT(j+1).z);
				uv3=new myVertex(UVright.getVertexT(j+1).x,UVright.getVertexT(j+1).y,UVright.getVertexT(j+1).z);
				uv4=new myVertex(UVright.getVertexT(j).x,UVright.getVertexT(j).y,UVright.getVertexT(j).z);
				UVCoords.push_back(uv1);
				UVCoords.push_back(uv2);
				UVCoords.push_back(uv3);
				UVCoords.push_back(uv4);

				// Coords
				myVertex *coord1,*coord2,*coord3,*coord4;
				coord1=new myVertex(left.getVertexT(j).x,left.getVertexT(j).y,left.getVertexT(j).z);
				coord2=new myVertex(left.getVertexT(j+1).x,left.getVertexT(j+1).y,left.getVertexT(j+1).z);
				coord3=new myVertex(right.getVertexT(j+1).x,right.getVertexT(j+1).y,right.getVertexT(j+1).z);
				coord4=new myVertex(right.getVertexT(j).x,right.getVertexT(j).y,right.getVertexT(j).z);
				coords.push_back(coord1);
				coords.push_back(coord2);
				coords.push_back(coord3);
				coords.push_back(coord4);


			}
		}
	}

}
void myRobot::setDrawmode(int mode){
	drawMode=mode;
}
void myRobot::drawTop(){
	// Draw the top circle
		for (int i = 0; i < 12; i++) {
			glPushMatrix();
				// Apply the necessary transformations
				glNormal3f(1, 0, 0);
				glRotated((i-2) * baseAngle, 0, 1, 0);
				glTranslated((baseWidth / 2) / apothem, 0, 0);
				glRotated(-90, 0, 1, 0);

				// Normal to the surface
				glNormal3f(0, 1, 0);

				// Draw a triangle
				glBegin(GL_TRIANGLES);
					glVertex3d(baseWidth / 2, 1, 0);
					glVertex3d(-baseWidth / 2, 1, 0);
				    glVertex3d(0, 1, 0.25);
				glEnd();
			glPopMatrix();
		}
}
void myRobot::drawBottom(){
	glBegin(GL_QUADS);
			glVertex3d(-0.5, 0, -0.5);
			glVertex3d(-0.5, 0, 0.5);
			glVertex3d(0.5, 0, 0.5);
			glVertex3d(0.5, 0, -0.5);
		glEnd();
}
