/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/

#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"
#include "cmath"

/**
 * MyCylinder - A class for defining a cylinder object
 * Notice that the circular shape is aproximated by triangles
 */
class myCylinder: public CGFobject {

	int slices; 		/* The number of side slices */
	int stacks;			/* The number of stacks */
	bool smooth; 		/* The smooth boolean value */
	double baseAngle; 	/* The triangle base Angle in degrees */
	double baseAngleR; /* The triangle baseAngle in radians*/
	double baseWidth;  /* The triangle base width  */
	double apothem;    /* The aphotem of the aproximated circle */


public:
	/** The constructor
	 * @param slices the number of side slices
	 * @param slices the number of stacks
	 * @param slices the smooth boolean value (false by default)
	 */
	myCylinder(int slices, int stacks, bool smooth=0);

	/* The draw method */
	void draw();

};

#endif
