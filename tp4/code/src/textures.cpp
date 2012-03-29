#include "textures.h"
#include <cmath>

boardTex::boardTex() {
	
	float ambA[3] = {0.2, 0.2, 0.2};
	float difA[3] = {0.5, 0.5, 0.5};
	float specA[3] = {0.2, 0.2, 0.2};
	
	this->setTexture("board.png");
	this->setAmbient(ambA);
	this->setDiffuse(difA);
	this->setSpecular(specA);
	this->shininess = 1420.f;
	
}

floorTex::floorTex() {

	float ambA[3] = {0.2, 0.2, 0.2};
	float difA[3] = {0.5, 0.5, 0.5};
	float specA[3] = {0.2, 0.2, 0.2};

	this->setTexture("floor.png");
	this->setAmbient(ambA);
	this->setDiffuse(difA);
	this->setSpecular(specA);
	this->shininess = 1420.f;

}
