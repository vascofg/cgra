#ifndef MYMATERIALS_H
#define MYMATERIALS_H
#include "CGFappearance.h"

// Material for the top of the table
class tableAppearance: public CGFappearance{
	public:
	tableAppearance();

};


// Material for the slides
class slidesAppearance : public CGFappearance{
	public:
	slidesAppearance();

};

// Material for the board
class boardAppearance : public CGFappearance{
	public:
	boardAppearance();

};

// Material for the window
class windowAppearance : public CGFappearance{
	public:
	windowAppearance();

};

// Material for the floor
class floorAppearance : public CGFappearance{
	public:
	floorAppearance();

};

// Material for the wall
class wallAppearance : public CGFappearance{
	public:
	wallAppearance();

};

// Material for the columns
class marbleAppearance : public CGFappearance{
	public:
	marbleAppearance();

};

// Material for the clock
class clockAppearance : public CGFappearance{
	public:
	clockAppearance();

};

// Material for the pointer
class pointerAppearance: public CGFappearance{
public:
    public:
    pointerAppearance();
};

#endif
