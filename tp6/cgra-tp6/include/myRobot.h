
#ifndef MYROBOT_H
#define	MYROBOT_H
#include <vector>
#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"
#include "myVertex.h"
using namespace std;
class myRobot : public CGFobject {
    int stacks;
    int drawMode;
    int slices;
    double baseAngle;
    double baseAngleR;
    double baseWidth;
    double apothem;
    double heightTop;
    double topRadius;
    vector<myVertex*> coords;
    vector<myVertex*> UVCoords;
    vector<myVertex*> normals;
    void drawTop();
    void drawBottom();
    void computeCoords(vector<myVertex*> &coords,vector<myVertex*> &UVCoords,vector<myVertex*> &normals);
public:
    double rotAngle;
    float moveX, moveZ;
    myRobot(int stacks);
    void draw();
    void update(long milis);
    void setDrawmode(int mode);
};


#endif	

