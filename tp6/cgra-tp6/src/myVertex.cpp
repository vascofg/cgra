
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
