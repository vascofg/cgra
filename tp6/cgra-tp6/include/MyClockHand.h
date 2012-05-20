/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef MYCLOCKHAND_H
#define	 MYCLOCKHAND_H

#include "CGFobject.h"
#include "cmath"
#include "myUnitCube.h"
#include "MyClockHand.h"
#include "myMaterials.h"
#include "CGF/CGFappearance.h"

/**
 * MyClockHand - a class for defining a clock pointer with its shape
 */
class MyClockHand: public CGFobject {
    float angle;						/* The angle of the pointer for rotation */
    myUnitCube *pointer;				/* The pointer object*/
    pointerAppearance  *pointerMaterial;		/* The pointer material*/
    float xScale,yScale,zScale;			/* x, y and z scaling values*/
    
public:
    /* The empty constructor that initializes all the necessary variables */
	MyClockHand();

	/** Sets the pointer angle
	 * @param angle the angle in degrees
	 */
    void setAngle(float angle);

    /** Scales the pointer
     * @param x the x-axis scalling
     * @param y the y-axis scalling
     * @param z the z-axis scalling
     */
    void setScale(float x,float y, float z);

    /* The draw method that puts the pointer in the pretended position and applys texture */
	void draw();
        
};

#endif	/* MYCLOCKHAND_H */

