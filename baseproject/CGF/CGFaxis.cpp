#include "CGFaxis.h"

#include "CGFapplication.h"

CGFaxis::CGFaxis(): CGFobject() {
	this->radius_begin = CG_CGFaxis_DEFAULT_RADBEG;
	this->radius_end = CG_CGFaxis_DEFAULT_RADEND;
	this->lenght = CG_CGFaxis_DEFAULT_LENGTH;
	this->nslices = CG_CGFaxis_DEFAULT_SLICES;
	this->nstacks = CG_CGFaxis_DEFAULT_STACKS;

	this->ball_radius = CG_CGFaxis_DEFAULT_SPHRAD;
	this->ball_slices = CG_CGFaxis_DEFAULT_SPHSLI;
	this->ball_stacks = CG_CGFaxis_DEFAULT_SPHSTK;

	glu_quadric = gluNewQuadric();
}


CGFaxis::~CGFaxis() {
	gluDeleteQuadric(glu_quadric);
}

void CGFaxis::draw() {
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();

		// esfera representativa da origem das coordenadas
		glColor3f(1.0,1.0,1.0);		// cor branca
		gluSphere(glu_quadric, this->ball_radius, this->ball_slices, this->ball_radius);

		// cilindro representativo do eixo X
		glColor3f(1.0,0.0,0.0);		// vermelho
		glPushMatrix();
			glRotated(90.0, 0.0,1.0,0.0);
			gluCylinder(glu_quadric, this->radius_begin, this->radius_end, this->lenght, this->nslices, this->nstacks);   // nao tem bases
		glPopMatrix();

		// cilindro representativo do eixo Y
		glColor3f(0.0,1.0,0.0);		// verde
		glPushMatrix();
			glRotated(-90.0, 1.0,0.0,0.0);
			gluCylinder(glu_quadric, this->radius_begin, this->radius_end, this->lenght, this->nslices, this->nstacks);   // nao tem bases
		glPopMatrix();
	
		// cilindro representativo do eixo Z
		glColor3f(0.0,0.0,1.0);		// azul
		glPushMatrix();
			// nao necessita rotacao... glRotated(...);
			gluCylinder(glu_quadric, this->radius_begin, this->radius_end, this->lenght, this->nslices, this->nstacks);   // nao tem bases
		glPopMatrix();

	glPopMatrix();

	glColor3f(1.0,1.0,1.0);
	glDisable(GL_COLOR_MATERIAL);

}