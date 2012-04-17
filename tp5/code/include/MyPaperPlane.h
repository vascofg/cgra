#ifndef MYPAPERPLANE_H
#define	MYPAPERPLANE_H
#include "CGFobject.h"

class MyPaperPlane:public CGFobject{
    // Usefull for the plane movement
    double Xpos;
    double Ypos;
    double Zpos;
    public:
    MyPaperPlane();
    void draw();
    void update(long milis);
};

#endif	/* MYPAPERPLANE_H */

