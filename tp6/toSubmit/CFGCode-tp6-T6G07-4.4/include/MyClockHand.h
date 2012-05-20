#ifndef MYCLOCKHAND_H
#define	MYCLOCKHAND_H

#include "CGFobject.h"
#include "cmath"
#include "myUnitCube.h"
#include "MyClockHand.h"
#include "CGF/CGFappearance.h"
class MyClockHand: public CGFobject {
    float angle;
    myUnitCube *pointer;
    CGFappearance *pointerMaterial;
    float xScale,yScale,zScale;
    
public:
	MyClockHand();
        void setAngle(float angle);
        void setScale(float x,float y, float z);
	void draw();
        
};

#endif	/* MYCLOCKHAND_H */

