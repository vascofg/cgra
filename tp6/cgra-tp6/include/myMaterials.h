/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/

#ifndef MYMATERIALS_H
#define MYMATERIALS_H
#include "CGFappearance.h"

/**
 * Material for the top of the table
 */
class tableAppearance: public CGFappearance{
	public:
	/* Empty constructor */
	tableAppearance();
};


/**
 * Material for the slides
 */
class slidesAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	slidesAppearance();

};

/**
 * Material for the board
 */
class boardAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	boardAppearance();

};

/**
 * Material for the window
 */
class windowAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	windowAppearance();

};

/**
 * Material for the floor
 */
class floorAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	floorAppearance();

};

/**
 * Material for the wall
 */
class wallAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	wallAppearance();

};

/**
 * Material for the columns
 */
class marbleAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	marbleAppearance();

};

/**
 * Material for the clock
 */
class clockAppearance : public CGFappearance{
	public:
	/* Empty constructor */
	clockAppearance();

};

/**
 * Material for the pointer
 */
class pointerAppearance: public CGFappearance{
public:
    public:
	/* Empty constructor */
    pointerAppearance();
};

/**
 * Material for the robot
 */
class robotAppearance: public CGFappearance{
public:
    public:
	/* Constructor
	 * @param textureID receives the initial texture id
	 */
	robotAppearance(int textureID);
	/* Changes the texture
	* @param textureID receives the texture number
	*/
	void setTextureID(int textureID);
};

/**
 * Material for the landscape
 */
class landscapeAppearance: public CGFappearance{
public:
    public:
	/* Empty constructor */
	landscapeAppearance();
};
#endif
