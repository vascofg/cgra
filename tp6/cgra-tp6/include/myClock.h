/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef MYCLOCK_H
#define MYCLOCK_H

#include "CGFobject.h"
#include "cmath"
#include "myCylinder.h"
#include "MyClockHand.h"
#include "myMaterials.h"
/**
 * myClock - A class for defining a clock with movement and its pointers
 */
class myClock : public CGFobject {

    myCylinder *c; 					/* the clock base cylinder */
    MyClockHand *seconds;			/* the seconds pointers */
    MyClockHand *minutes;			/* the minutes pointerr */
    MyClockHand *hours;				/* the clock base cylinder */
    float angleSeconds;				/* the angle of the seconds pointer */
    float angleMinutes;				/* the angle of the minutes pointer */
    float angleHours;				/* the angle of the hours pointer */
    clockAppearance *clockMaterial; /* the clock texture */

public:

    /* The empty constructor that initializes all the necessary variables */
    myClock();

    /* The draw method that draws the bast cylinder, the pointers and applies the texture */
    void draw();
    /** Updates the pointers positions
     * @param milis the time elapsed since the begining of the scene
     */
    void update(long milis);

};

#endif	

