#include "myRobot.h"
#include "myMaterials.h"
#include <iostream>
#include <myVertex.h>
using namespace std;

myRobot::myRobot(int stacks) {
	rotAngle = -157.5;
	quadric = gluNewQuadric();
	this->stacks = stacks;

	// Compute the uv points
	computeUVPoints(UVsquareVertexs,UVcircleVertexs);

}

void myRobot::draw() {

	// (1) Some pre-calculus
	int slices=12;
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);
	double baseWidth = sin(2 * acos(-1) *0.25/ (float)slices); // 0.25 is the radius
	double apothem = (tan(baseAngleR / 2));
	double heightTop=1;

	// (2) The robot translations and rotations
	glTranslated(moveX, 0, moveZ);
	glRotated(rotAngle, 0, 1, 0);

	// (3) Let the Robot draw begin
	glPushMatrix();
	// ->

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


	// Draw the bottom square
	glBegin(GL_QUADS);
		glVertex3d(-0.5, 0, -0.5);
		glVertex3d(-0.5, 0, 0.5);
		glVertex3d(0.5, 0, 0.5);
		glVertex3d(0.5, 0, -0.5);
	glEnd();


	// Compute the top triangle joint initial poins
	double zl=0.25*cos(baseAngleR*3/2.0);
	double zr=0.25*cos(baseAngleR*1/2.0);
	double xl=0.25*sin(baseAngleR*3/2.0);
	double xr=0.25*sin(baseAngleR*1/2.0);


	// Draw all the side rectangles


	for( int j=0; j<stacks; j++){ // stacks
		glPushMatrix();
		int uvIndex=0;
			for(int l=0; l<4; l++){ // the 4 square faces
				glPushMatrix();
					glRotated(-90*l,0,1,0);

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
							glNormal3f(-normal.x,-normal.y,-normal.z);

							// Fecth the UV coordinates
							myVertex s1=UVsquareVertexs[uvIndex];
							myVertex c1=UVcircleVertexs[uvIndex];
							uvIndex++;
							myVertex s2=UVsquareVertexs[uvIndex];
							myVertex c2=UVcircleVertexs[uvIndex];

							// Reactangle draw
							glBegin(GL_QUADS);

								// Draw
								glTexCoord2f(s1.x,s1.y); glVertex3d(left.getVertexT(j).x , left.getVertexT(j).y ,left.getVertexT(j).z);
								glTexCoord2f(c1.x,c1.y); glVertex3d(left.getVertexT(j+1).x , left.getVertexT(j+1).y ,left.getVertexT(j+1).z);
								glTexCoord2f(c2.x,c2.y); glVertex3d(right.getVertexT(j+1).x , right.getVertexT(j+1).y ,right.getVertexT(j+1).z);
								glTexCoord2f(s2.x,s2.y); glVertex3d(right.getVertexT(j).x , right.getVertexT(j).y ,right.getVertexT(j).z);
							glEnd();

						}
				glPopMatrix(); // matrix of face set of rectangles
					}
		glPopMatrix(); //  matrix of the 4 square faces
			}


	// END ROBOT DRAW ->
	glPopMatrix();

}

void myRobot::update(long milis) {

}

void computeUVPoints(vector<myVertex> &squareVertexs,vector<myVertex> &circleVertex){
	int slices=12;
	double baseAngle = (360 / (float)slices);
	double baseAngleR = (2 * acos(-1) / (float)slices);

	// Compute UV initial points
	myVertex uvSquare(1,0,0);
	myVertex uvCircle(0.5+sin(3/2.0*baseAngleR)*0.25,0.5-cos(3/2.0*baseAngleR)*0.25,0);

	for(int unsigned i=0; i<4; i++){
		myVertex versor(-1/3.0,0,0);
		versor.rotateZ(-acos(-1)/2.0*i);
		for(int unsigned j=0; j<3; j++){
			// points 1
			myVertex s1=uvSquare;
			myVertex c1=uvCircle;

			// Transform the square vertex
			uvSquare.translate(versor.x,versor.y,0);

			// Rotate the circle vertex
			uvCircle.translate(-0.5,-0.5,0);
			uvCircle.rotateZ(-baseAngleR);
			uvCircle.translate(0.5,0.5,0);

			// points 2
			myVertex s2=uvSquare;
			myVertex c2=uvCircle;


			// add to the vectors
			squareVertexs.push_back(s1);
			squareVertexs.push_back(s2);
			circleVertex.push_back(c1);
			circleVertex.push_back(c2);
		}
	}

}
