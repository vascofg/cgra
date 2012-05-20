/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#include "myVertex.h"
#include "math.h"
#include <iostream>

using namespace std;
myVertex::myVertex(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;

}
void myVertex::rotateY(double angleRad) {
	double xtemp = x; // one does not simply use the changed x in the z equation
	x = x * cos(angleRad) + z * sin(angleRad);
	z = -xtemp * sin(angleRad) + z * cos(angleRad);

}

void myVertex::rotateZ(double angleRad){
	double xtemp=x;
	x = x * cos(angleRad) - y * sin(angleRad);
	y = xtemp * sin(angleRad) + y * cos(angleRad);
}

void myVertex::translate(double dx, double dy, double dz){
	x=x+dx;
	y=y+dy;
	z=z+dz;
}
mySemiRect::mySemiRect(myVertex *begin, myVertex *end, double divideStep) {
	this->begin = begin;
	this->end = end;
	this->divideStep = divideStep;

	deltaX = end->x - begin->x;
	deltaX = deltaX / divideStep;

	deltaY = end->y - begin->y;
	deltaY = deltaY / divideStep;

	deltaZ = end->z - begin->z;
	deltaZ = deltaZ / divideStep;
}

myVertex mySemiRect::getVertexT(int t) {
	return myVertex(begin->x + deltaX * t, begin->y + deltaY * t,
			begin->z + deltaZ * t);
}

myVertex computeNormalNewel(vector<myVertex> vertexList) {
	// initial normal
	myVertex normal(0, 0, 0);
	for (int unsigned i = 0; i < vertexList.size(); i++) {
		myVertex current = vertexList[i];
		myVertex next = vertexList[(i + 1) / vertexList.size()];
		normal.x = normal.x + ((current.y - next.y) * (current.z + next.z));
		normal.y = normal.y + ((current.z - next.z) * (current.x + next.x));
		normal.z = normal.z + ((current.x - next.x) * (current.y + next.y));
	}
	return normal;

}


