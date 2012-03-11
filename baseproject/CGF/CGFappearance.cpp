#include "CGFappearance.h"

#include "CGFapplication.h"

unsigned int CGFappearance::__next_id = 0;
std::vector<CGFappearance*> CGFappearance::appearances = std::vector<CGFappearance*>();

CGFappearance::CGFappearance(): id(__next_id++) {
	try {
		this->color[0] = 0.5;
		this->color[1] = 0.5;
		this->color[2] = 0.5;

		this->isMaterial = CG_GLMAT_COLOR;

		CGFappearance::appearances.push_back(this);
	}
	catch(std::exception& ex) {
		throw GLexception("CGFappearance::construtor construcao de objeto falhou");
	}
}

CGFappearance::CGFappearance(float* a, float* d, float* sp, float sh) {
	try {
		this->ambient[0] = a[0];
		this->ambient[1] = a[1];
		this->ambient[2] = a[2];

		this->diffuse[0] = d[0];
		this->diffuse[1] = d[1];
		this->diffuse[2] = d[2];
		
		this->specular[0] = sp[0];
		this->specular[1] = sp[1];
		this->specular[2] = sp[2];

		this->shininess[0] = sh;

		this->isMaterial = CG_GLMAT_MATERIAL;

		CGFappearance::appearances.push_back(this);
	}
	catch(std::exception& ex) {
		throw GLexception("CGFappearance::construtor construcao de objeto falhou");
	}
}

CGFappearance::CGFappearance(float* c) {
	try {
		this->color[0] = c[0];
		this->color[1] = c[1];
		this->color[2] = c[2];

		this->isMaterial = CG_GLMAT_COLOR;

		CGFappearance::appearances.push_back(this);
	}
	catch(std::exception& ex) {
		throw GLexception("CGFappearance::construtor construcao de objeto falhou");
	}
}

CGFappearance::~CGFappearance() {

}

void CGFappearance::apply() {

	if(this->isMaterial==CG_GLMAT_MATERIAL) {
		glDisable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_SHININESS, this->shininess);
		glMaterialfv(GL_FRONT, GL_SPECULAR,  this->specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,   this->diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT,   this->ambient);
	}
	else if(this->isMaterial==CG_GLMAT_COLOR) {
		glEnable(GL_COLOR_MATERIAL);
		glColor3f(0.0,1.0,0.0);
	}
}

