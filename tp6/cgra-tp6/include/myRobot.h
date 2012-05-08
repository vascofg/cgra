
#ifndef MYROBOT_H
#define	MYROBOT_H

#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"

class myRobot : public CGFobject {
    int stacks;
public:
    double rotAngle;
    float moveX, moveZ;
    myRobot(int stacks);
    void draw();
    void update(long milis);
    GLUquadricObj* quadric;
};



#endif	

