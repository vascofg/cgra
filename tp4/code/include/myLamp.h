#ifndef MYLAMP_H
#define MYLAMP_H

#include "CGFobject.h"
#include "cmath"

class myLamp: public CGFobject {

	int slices;
	bool smooth;

public:
	myLamp(int slices, bool smooth=0);
	void draw();

};

#endif
