
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
public:
    double rotAngle;
    float moveX, moveZ;
    myRobot(int stacks);
    void draw();
    void update(long milis);
    GLUquadricObj* quadric;
	vector<myVertex> UVsquareVertexs, UVcircleVertexs;
};

void computeUVPoints(vector<myVertex> &squareVertexs,vector<myVertex> &circleVertex);

#endif	

