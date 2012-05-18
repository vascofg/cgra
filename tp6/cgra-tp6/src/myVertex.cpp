
#include "myVertex.h"
#include "math.h"
myVertex::myVertex(double x, double y, double z) {
	this->x=x;
	this->y=y;
	this->z=z;

}
void myVertex::rotateY(double angleRad){
	x=x*cos(angleRad)+z*sin(angleRad);
	z=-x*sin(angleRad)+z*cos(angleRad);

}
