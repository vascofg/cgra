/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myMaterials.h"
#include "myCylinder.h"
#include "myClock.h"
#include "MyClockHand.h"
#include "myRobot.h"
#include "myWindowWall.h"
#include <time.h>

/**
 * LightingScene - A class the implements a 3d OpenGL scene with lights
 */
class LightingScene: public CGFscene {

protected:
	// ---- lights
	CGFlight* light0;						/* light 0 that is near the window wall */
	CGFlight* lightBoardA;					/* light that is near the left board */
	CGFlight* lightBoardB;					/* light that is near the right board */
	// ---- objects
	myTable* table;							/* the table object */
	Plane* planeWall;						/* the front plane wall */
	Plane* floor;							/* floor plane */
	Plane* boardA;							/* left board plane*/
	Plane* boardB;							/* right board plane*/
	myCylinder* column;						/* the column */
	myClock* clock;							/* the clock between the boards */
	myRobot* robot;							/* the Mr. Robot */
	myWindowWall *windowWall;				/* left wall with a window border and a hole */
	// -- materials
	boardAppearance* boardMaterial;			/* white board material */
	slidesAppearance* slidesMaterial;		/* cgra slides material */
	floorAppearance* floorMaterial;			/* floor wood material */
	wallAppearance* wallMaterial;			/* wall concrete material */
	windowAppearance* windowMaterial;		/* window material */
	marbleAppearance* marbleMaterial;		/* marble material used for columns*/
	robotAppearance* robotMaterial;			/* robot material that have 3 textures */
public:
	/* Setup the environment, materials and lights */
	void init();
	/* Setup the lights */
	void initLights();
	/* Draw the primitives, apply the materials, etc */
	void display();
	/** Update necessary objects
	 * @param millis time elapsed
	 */
	void update(long millis);
	/* destructor */
	~LightingScene();
	/* toggle something */
	void toggleSomething();

	int light0on;      /* turn on the left wall light */
	int lightBoardAon; /* turn on the right board light */
	int lightBoardBon; /* turn on the left board light */
	int clockon;	   /* activates the clock */
	int robotTexture;  /* the texture id of the robot */
	int robotDrawMode; /* the robot draw mode 0=textured, 1=wired */
	/**
	 * Moves the robot
	 * @param rotAngle the desired angle
	 * @param modeDist the desired distance
	 */
	void moveRobot(double rotAngle, double moveDist);
};

#endif
