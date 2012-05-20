#ifndef MYWINDOWWALL_H_
#define MYWINDOWWALL_H_

#include "Plane.h"
class myWindowWall: public CGFobject {
	Plane* leftWall;
public:
	myWindowWall(){};
	void draw();

};

#endif /* MYWINDOWWALL_H_ */
