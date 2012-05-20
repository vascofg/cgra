#ifndef MYWINDOWWALL_H_
#define MYWINDOWWALL_H_
#include "myMaterials.h"
#include "Plane.h"
class myWindowWall: public CGFobject {
	landscapeAppearance * landscapeMaterial;
public:
	myWindowWall();
	void draw();

};

#endif /* MYWINDOWWALL_H_ */
