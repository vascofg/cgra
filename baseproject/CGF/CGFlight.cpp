#include "CGFlight.h"

#include "CGFapplication.h"


float __tmp_0[3] = {CG_GLIGHT_DEFAULT_COLOR};
CGFappearance* CGFlight::default_light_material = new CGFappearance(__tmp_0);
float CGFlight::background_ambient[4] = {CG_GLIGHT_DEFAULT_BACKGROUND_AMBIENT};

CGFlight::CGFlight(unsigned int i, float* pos) {
	try {
		this->id = i;

		this->position[0] = pos[0];
		this->position[1] = pos[1];
		this->position[2] = pos[2];
		this->position[3] = pos[3];
		this->material = CGFlight::default_light_material;


		float __tmp_1[4] = {CG_GLIGHT_DEFAULT_AMBIENT};
		this->setLightAmbient(__tmp_1);
		float __tmp_2[4] = {CG_GLIGHT_DEFAULT_DIFFUSE};
		this->setLightDiffuse(__tmp_2);
		float __tmp_3[4] = {CG_GLIGHT_DEFAULT_SPECULAR};
		this->setLightSpecular(__tmp_3);

		this->setLightKc(CG_GLIGHT_DEFAULT_KC);
		this->setLightKl(CG_GLIGHT_DEFAULT_KL);
		this->setLightKq(CG_GLIGHT_DEFAULT_KQ);
	}
	catch(std::exception& ex) {
		throw GLexception("CGFlight::construtor construcao de objeto falhou");
	}

	glu_quadric = gluNewQuadric();
	gluQuadricOrientation(glu_quadric, GLU_INSIDE);
}

void CGFlight::setLightAmbient(float* li) {
	this->light_ambient [0] = li[0];
	this->light_ambient [1] = li[1];
	this->light_ambient [2] = li[2];
	this->light_ambient [3] = li[3];
}

void CGFlight::setLightDiffuse(float* li) {
	this->light_diffuse [0] = li[0];
	this->light_diffuse [1] = li[1];
	this->light_diffuse [2] = li[2];
	this->light_diffuse [3] = li[3];
}

void CGFlight::setLightSpecular(float* li) {
	this->light_specular [0] = li[0];
	this->light_specular [1] = li[1];
	this->light_specular [2] = li[2];
	this->light_specular [3] = li[3];
}

CGFlight::~CGFlight() {
	gluDeleteQuadric(glu_quadric);
}

void CGFlight::enable() {
	glLightfv(this->id, GL_AMBIENT, this->light_ambient);
	glLightfv(this->id, GL_DIFFUSE, this->light_diffuse);
	glLightfv(this->id, GL_SPECULAR, this->light_specular);
	glLightf(this->id, GL_CONSTANT_ATTENUATION, this->light_kc);
	glLightf(this->id, GL_LINEAR_ATTENUATION, this->light_kl);
	glLightf(this->id, GL_QUADRATIC_ATTENUATION, this->light_kq);

	glEnable(this->id);
}

void CGFlight::draw() {
	glLightfv(this->id, GL_POSITION, this->position);
	this->material->apply();
	glPushMatrix();
		glTranslatef(this->position[0],this->position[1],this->position[2]);
		gluSphere(glu_quadric, CG_GLIGHT_DEFAULT_RADIUS, CG_GLIGHT_DEFAULT_SLICES, CG_GLIGHT_DEFAULT_STACKS);
	glPopMatrix();
}

