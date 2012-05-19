
#include "myVertex.h"
#include "math.h"
#include <iostream>
using namespace std;
myVertex::myVertex(double x, double y, double z) {
	this->x=x;
	this->y=y;
	this->z=z;

}
void myVertex::rotateY(double angleRad){
	double xtemp=x; // one does not simply use the changed x in the z equation
	x=x*cos(angleRad)+z*sin(angleRad);
	z=-xtemp*sin(angleRad)+z*cos(angleRad);

}
mySemiRect::mySemiRect(myVertex *begin, myVertex *end, double divideStep){
	this->begin=begin;
	this->end=end;
	this->divideStep=divideStep;

	deltaX=end->x - begin->x;
	deltaX=deltaX/divideStep;

	deltaY=end->y - begin->y;
	deltaY=deltaY/divideStep;

	deltaZ=end->z - begin->z;
	deltaZ=deltaZ/divideStep;
}

myVertex mySemiRect::getVertexT(int t){
	return myVertex(begin->x+deltaX*t,begin->y+deltaY*t,begin->z+deltaZ*t);
}
