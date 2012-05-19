
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
	//cout <<" AngleRad= " << angleRad << endl;
	double xtemp=x;
	x=x*cos(angleRad)+z*sin(angleRad);
	z=-xtemp*sin(angleRad)+z*cos(angleRad);
	cout << "x: " << x << endl;
	cout << "z: " << z << endl;

}
