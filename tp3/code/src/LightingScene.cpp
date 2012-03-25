#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = { 4, 6.0, 5.0, 1.0 };
float light1_pos[4] = { 10.5, 6.0, 1.0, 1.0 };

float light2_pos[4] = { 10.5, 6.0, 5.0, 1.0 };
float light3_pos[4] = { 4, 6.0, 5.0, 1.0 };

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = { 0, 0, 0, 0 };

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = { 0.2, 0.2, 0.2 };
float difA[3] = { 0.6, 0.6, 0.6 };
float specA[3] = { 0, 0.8, 0.8 };
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = { 0.2, 0.2, 0.2 };
float difB[3] = { 0.6, 0.6, 0.6 };
float specB[3] = { 0.8, 0.8, 0.8 };
float shininessB = 120.f;

float ambientNull[4] = { 0, 0, 0, 1 };
float yellow[4] = { 1, 1, 0, 1 };
float white[4] = { 1, 0, 0, 1 };

void LightingScene::init() {
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setDiffuse(white);
	light0->setSpecular(white);
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	light1->enable();

	// Added light2
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);

	light2->setKc(0);
	light2->setKl(1.0);
	light2->setKq(0);

	light2->enable();

	// Added light3
	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setDiffuse(yellow);
	light3->setSpecular(yellow);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	light3->enable();
	// Uncomment below to enable normalization of lighting normal vectors
	glEnable(GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);

	//Declares materials
	materialA = new CGFappearance(ambA, difA, specA, shininessA);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);

}

void LightingScene::display() {

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glShadeModel(GL_FLAT);

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();
	light0->draw();


	 // ---- END Background, camera and axis setup

	 // ---- BEGIN Primitive drawing section


	// Draw 8 cilinders
	myCylinder pol[] = { myCylinder(4, 4), myCylinder(4, 2), myCylinder(5, 1),
			myCylinder(6, 1), myCylinder(7, 1), myCylinder(8, 1), myCylinder(9,
					1), myCylinder(10, 1), myCylinder(20, 1),myCylinder(50, 1),myCylinder(100, 4)};
	for (int i = 10; i >=0; i--) {
		glPushMatrix();
		glTranslated(i*2, 0, 0);
		pol[i].draw();
		glPopMatrix();
	}

	// ---- END Primitive drawing section

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() {
	delete (light0);
	delete (light1);

	delete (table);
	delete (wall);
	delete (boardA);
	delete (boardB);
	delete (materialA);
	delete (materialB);
}
