
#ifndef MYCLOCK_H
#define	MYCLOCK_H

#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"

class myClock: public CGFobject {
  myCylinder *c;

public:
	myClock();
	void draw();

};



#endif	

