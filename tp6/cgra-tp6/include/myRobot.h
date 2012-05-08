
#ifndef MYROBOT_H
#define	MYROBOT_H

#include "CGFobject.h"
#include "cmath"

class myRobot : public CGFobject {
    
public:
    double rotAngle;
    float moveX, moveZ;
    myRobot();
    void draw();
    void update(long milis);

};



#endif	

