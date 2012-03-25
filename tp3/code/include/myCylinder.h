#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"
#include "cmath"

class myCylinder: public CGFobject {

	int slices, stacks;

public:
	myCylinder(int slices, int stacks, bool smooth=0);
	void draw();

};

#endif
