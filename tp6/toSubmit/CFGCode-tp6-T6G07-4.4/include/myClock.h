
#ifndef MYCLOCK_H
#define	MYCLOCK_H

#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"
#include"MyClockHand.h"

class myClock : public CGFobject {
    myCylinder *c;
    MyClockHand *seconds;
    MyClockHand *minutes;
    MyClockHand *hours;
    float angleSeconds;
    float angleMinutes;
    float angleHours;
public:
    myClock();
    void draw();
    void update(long milis);

};



#endif	

