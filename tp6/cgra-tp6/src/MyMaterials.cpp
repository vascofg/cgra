#include "myMaterials.h"
#include <GL/glut.h>
tableAppearance::tableAppearance(){
	// Coefficients for ilumination
	float amb[3] = { 0.3, 0.205, 0.047 };
	float dif[3] = { 0.6, 0.41, 0.094 };
	float spec[3] = { 0.05, 0.05, 0.05 };
	float shininess = 2.f;
	
	this->setTexture("textures/table.png");
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

	this->setTexture("textures/slides.png");
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
	this->setTexture("textures/board.png");
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
	
	this->setTexture("textures/floor.png");
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

	this->setTexture("textures/wall.png");
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

	this->setTexture("textures/window.png");
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

	this->setTexture("textures/marmore.jpg");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

clockAppearance::clockAppearance(){

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0, 0,0 };
	float shininess = 120.f;

	this->setTexture("textures/clock.png");
	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}
pointerAppearance::pointerAppearance(){
    this->color[0]=1;
    this->color[1]=0;
    this->color[2]=0;
}


robotAppearance::robotAppearance(int textureID){

	float amb[3] = { 0.6, 0.6, 0.6 };
	float dif[3] = { 0.4, 0.4, 0.4 };
	float spec[3] = { 0.3, 0.3,0.3 };
	float shininess = 120.f;
	switch(textureID){
		case 1: this->setTexture("textures/robot1.jpg"); break;
		case 2: this->setTexture("textures/robotcop.png"); break;
		case 3: this->setTexture("textures/table.png"); break;
	}

	this->setAmbient(amb);
	this->setDiffuse(dif);
	this->setSpecular(spec);
	this->shininess = shininess;

}

