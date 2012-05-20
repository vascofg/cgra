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
    double rotAngle;				/* rotation angle of the robot */
    float moveX;					/* the x translation of robot */
    float moveZ;					/* the z translation of robot */
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
    /**
     * The constructor
     * @param stacks the number of stacks
     */
    myRobot(int stacks);

    /**
     * Set the angle of the rotation
     * @param angle the rotation angle
     */
    void setRotAngle(double angle);
    /**
     * Get the rotation angle in degrees
     * @return a double
     */
    double getRotAngle();

    /**
     * Set the x translatrion
     * @param moveX the x value
     */
    void setMoveX(float moveX);

    /**
     * Set the z translation
     * @param moveX the z value
     */
    void setMoveZ(float moveZ);

    /**
     * Get the X translation
     * @return a float
     */
    float getMoveX();

    /**
     * Get the Z translation
     * @return a float
     */
    float getMoveZ();

    /* Draw the top, the bottom and the sides of the robot */
    void draw();
    /**
     * Update function (not necessary)
     * @param milis the elapsed time
     */
    void update(long milis);

    /**
     * Sets the draw mode of the robot to wired or not
     * @param mode the mode of draw (0=texture, 1=wired)
     */
    void setDrawmode(int mode);
};


#endif	

