#include "myMaterials.h"
#include <GL/glut.h>
tableAppearance::tableAppearance(){
	// Coefficients for ilumination
	float amb[3] = { 0.3, 0.205, 0.047 };
	float dif[3] = { 0.6, 0.41, 0.094 };
	float spec[3] = { 0.05, 0.05, 0.05 };
	float shininess = 2.f;
	
	this->setTexture("table.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess=shininess;

}

slidesAppearance::slidesAppearance() {

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 1, 1, 1 };
	float spec[3] = { 0.05, 0.05, 0.05 };
	float shininess = 1.f;

	this->setTexture("slides.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

boardAppearance::boardAppearance() {

	float amb[3] = { 0.02, 0.02, 0.02 };
	float dif[3] = { 0.2, 0.2, 0.2 };
	float spec[3] = { 0.4, 0.4, 0.4 };
	float shininess = 1200.f;
	this->setTexture("board.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

floorAppearance::floorAppearance(){
	// Coefficients for ilumination
	float amb[3] = { 0.6, 0.41, 0.094 };
	float dif[3] = { 0.3, 0.205, 0.047 };
	float spec[3] = { 0.3, 0.3, 0.3 };
	float shininess = 20.f;
	
	this->setTexture("floor.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess=shininess;

}
wallAppearance::wallAppearance() {

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0.05, 0.05, 0.05 };
	float shininess = 1200.f;

	this->setTexture("wall.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

windowAppearance::windowAppearance(){

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0.5, 0.5, 0.5 };
	float shininess = 1200.f;

	this->setTexture("window.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

marbleAppearance::marbleAppearance(){

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0.9, 0.9,0.9 };
	float shininess = 1200.f;

	this->setTexture("marmore.jpg");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}


