#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myMaterials.h"
#include "myCylinder.h"
#include "myClock.h"

class LightingScene : public CGFscene
{
public:
	// Setup the environment, materials and lights
	void init();
	// Setup the lights
	void initLights();
	// Draw the primitives, apply the materials, etc
	void display();
	// free memory
	~LightingScene();
protected:
	// ---- lights
	CGFlight* light0;
	CGFlight* lightBoardA;
	CGFlight* lightBoardB;
	// ---- objects
	myTable* table;
	Plane* planeWall;
	Plane* leftWall;
	Plane* floor;
	Plane* boardA;
	Plane* boardB;
	myCylinder* column;
        myClock* clock;
	// -- materials
	boardAppearance* boardMaterial;
	slidesAppearance* slidesMaterial;
	floorAppearance* floorMaterial;
	wallAppearance* wallMaterial;
	windowAppearance* windowMaterial;
	marbleAppearance* marbleMaterial;
};

#endif
