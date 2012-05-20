/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/

#ifndef MYROBOT_H
#define	 MYROBOT_H
#include <vector>
#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"
#include "myVertex.h"
using namespace std;

/**
 * myRobot - A class for defining a robot with its shapes and textures.
 */
class myRobot : public CGFobject {
    int stacks;						/* height stacks */
    int drawMode;					/* drawmode 1=wireframe, 0=textured */
    int slices;						/* top circle side slices */
    double baseAngle;				/* angle in degrees of the triangles in the top */
    double baseAngleR;				/* angle in radians of the triangles in the top */
    double baseWidth;				/* base width of the triangles in the top */
    double apothem;					/* base width of the triangles in the top */
    double heightTop;				/* height to the top */
    double topRadius;				/* top radius */
    vector<myVertex*> coords;		/* coordinates of the robot sides */
    vector<myVertex*> UVCoords;		/* uv coordinates */
    vector<myVertex*> normals;		/* normals coordinates */
    void drawTop();				/* draw the top circle */
    void drawBottom();				/* draw the bottom unitary square */
    void drawSides();				/* draw the sided rectangles */
    /**
     * Compute all the necessary coordinates of the robot like uvs, normals and vertexs.
     * @param coords the robot vertexs vector
     * @param uvcoords the robot uv vertex vector
     * @param normals the robot side normals vector
     */
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

