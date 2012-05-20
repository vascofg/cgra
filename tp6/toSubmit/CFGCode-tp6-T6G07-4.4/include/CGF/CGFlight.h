#ifndef CG_CGFlight
#define CG_CGFlight

/**
 * @file CGFlight.h
 * Light class of the CGF framework.
 * 
 * The light class is used to initialise and store information on a GLlight.
 * It may also draw a sphere to represent the light on the 3D scene.
 */

#include "CGFobject.h"
#include "CGFappearance.h"
#include <GL/glut.h>


class CGFlight: public CGFobject {
	public:
		CGFlight(unsigned int, float* pos, float *dir=NULL);
		~CGFlight();

		void draw();
		void update();
		void enable();
		void disable();

		void setAmbient(float*);
		void setDiffuse(float*);
		void setSpecular(float*);
		void setKc(float f);
		void setKl(float f);
		void setKq(float f);
		
		static float background_ambient[4];

	protected:
		static CGFappearance* default_light_material;

		unsigned int id;
		float ambient[4];
		float diffuse[4];
		float specular[4];
		float kc;
		float kl;
		float kq;

		GLUquadric* glu_quadric;

		float position[4];
		float direction[3];
		CGFappearance* material;

};

#endif
