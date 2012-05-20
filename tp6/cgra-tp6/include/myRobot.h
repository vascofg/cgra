
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

public:
    double rotAngle;
    float moveX, moveZ;
    myRobot(int stacks);
    void draw();
    void update(long milis);
    void setDrawmode(int mode);
};

void computeUVPoints(vector<myVertex> &squareVertexs,vector<myVertex> &circleVertex);

#endif	

