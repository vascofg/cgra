
#ifndef MYROBOT_H
#define	MYROBOT_H

#include "CGFobject.h"
#include "cmath"

class myRobot : public CGFobject {
    
public:
    double rotAngle;
    int moveDist;
    myRobot();
    void draw();
    void update(long milis);

};



#endif	

