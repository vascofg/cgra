#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"

class myChair: public CGFobject {
public:
	float angle;
	myChair();
	void draw();
};

#endif
