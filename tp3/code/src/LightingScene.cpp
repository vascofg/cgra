#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = { 1, 6.0, 5.0, 1.0 };
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
float ambient1[4] = { 0.05, 0.05, 0.05, 1 };
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
	light0->setAmbient(ambient1);
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

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();
	light0->draw();
	light1->draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section
	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
	glTranslated(5, 0, 8);
	table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
	glTranslated(12, 0, 8);
	table->draw();
	glPopMatrix();

	//Floor
	// Coefficients for material
	float amb[3] = { 0, 0, 0.3984 };
	float dif[3] = { 0, 0, 0.3984 };
	float spec[3] = { 0, 0, 0.1 };
	float shininess = 12.f;
	CGFappearance *materialF = new CGFappearance(amb, dif, spec, shininess);
	glPushMatrix();
	materialF->apply();
	glTranslated(7.5, 0, 7.5);
	glScaled(15, 0.2, 15);
	wall->draw();
	glPopMatrix();

	//LeftWall
	float amb1[3] = { 0.3984, 0, 0 };
	float dif1[3] = { 0.3984, 0, 0 };
	float spec1[3] = { 0.20, 0, 0 };
	float shininess1 = 12.f;
	CGFappearance *materialLw = new CGFappearance(amb1, dif1, spec1,
			shininess1);

	glPushMatrix();
	materialLw->apply();
	glTranslated(0, 4, 7.5);
	glRotated(-90.0, 0, 0, 1);

	glScaled(8, 0.2, 15);
	wall->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glRotated(90.0, 1, 0, 0);
	glScaled(15, 0.2, 8);
	wall->draw();
	glPopMatrix();

	// Board A
	glPushMatrix();
	glTranslated(4, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	materialA->apply();
	boardA->draw();
	glPopMatrix();

	//PlaneB
	glPushMatrix();
	glTranslated(10.5, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	materialB->apply();
	boardB->draw();
	glPopMatrix();

	//roof
	glPushMatrix();
	glTranslated(0, 8, 0);
	glNormal3f(0,-1,0);
	glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(15,0,0);
		glVertex3f(15,0,15);
		glVertex3f(0,0,15);
	glEnd();
	glPopMatrix();

	// lamp in the roof
	glRotated(180,1,0,0);
	glTranslated(7.5, -8, -7.5);
	myLamp *lamp = new myLamp(20, 1);

	lamp->draw();
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
