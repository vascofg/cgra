#include "CGFscene.h"

#include <GL/glut.h>
#include "CGFapplication.h"
#include "CGFaxis.h"

CGFscene::CGFscene() {
	initCameras();
}

CGFscene::~CGFscene() {

}

//CGFcamera *CGFscene::activeCamera = new CGFcamera();


void CGFscene::activateCamera(int i)
{
	if(i<3 && i >=0)
	{
		activeCamera = this->scene_cameras.at(i);
	}
}

void CGFscene::initCameras()
{
	CGFcamera* first = new CGFcamera();
	CGFcamera* second = new CGFcamera();
	CGFcamera* third = new CGFcamera();

	first->moveTo(25,0,0);
	first->rotate(0,20);
	first->rotate(1,-45);

	second->moveTo(20,20,20);

	third->moveTo(0,30,0);
	
	this->scene_cameras.push_back(first);
	this->scene_cameras.push_back(second);
	this->scene_cameras.push_back(third);

	activateCamera(0);
}

void CGFscene::init() {
	glEnable(GL_LIGHTING);

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // define luz ambiente
	
	// Light
	float light0_pos[4] = {4.0, 6.0, 3.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();
}

void CGFscene::display() {

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Inicializacoes da matriz de transformacoes geometricas
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	CGFscene::activeCamera->applyView();

	axis.draw();

	glutSwapBuffers();
}
