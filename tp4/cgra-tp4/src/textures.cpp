#include "textures.h"
#include <cmath>

tableAppearance::tableAppearance() {

	float amb[3] = { 0.6, 0.41, 0.094 };
	float dif[3] = { 0.3, 0.205, 0.047 };
	float spec[3] = { 0, 0, 0 };
	float shininess = 12.f;

	this->setTexture("textures/table.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

slidesAppearance::slidesAppearance() {

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 1, 1, 1 };
	float spec[3] = { 0.05, 0.05, 0.05 };
	float shininess = 120.f;

	this->setTexture("textures/slides.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

boardAppearance::boardAppearance() {

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0.5, 0.5, 0.5 };
	float shininess = 1200.f;

	this->setTexture("textures/board.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}
