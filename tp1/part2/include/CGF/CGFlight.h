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


#define CG_GLIGHT_DEFAULT_COLOR 1.0,1.0,0.0 /* amarelo */
#define CG_GLIGHT_DEFAULT_BACKGROUND_AMBIENT 0.2,0.2,0.2,1.0
#define CG_GLIGHT_DEFAULT_RADIUS 0.2
#define CG_GLIGHT_DEFAULT_SLICES 8
#define CG_GLIGHT_DEFAULT_STACKS 16
#define CG_GLIGHT_DEFAULT_AMBIENT 0.0,0.0,0.0,1.0
#define CG_GLIGHT_DEFAULT_DIFFUSE 0.8,0.8,0.8,1.0
#define CG_GLIGHT_DEFAULT_SPECULAR 0.8,0.8,0.8,1.0
#define CG_GLIGHT_DEFAULT_KC 1.0
#define CG_GLIGHT_DEFAULT_KL 0.0
#define CG_GLIGHT_DEFAULT_KQ 0.0

class CGFlight: public CGFobject {
	public:
		CGFlight(unsigned int, float* pos);
		~CGFlight();

		void draw();
		void enable();

		void setLightAmbient(float*);
		void setLightDiffuse(float*);
		void setLightSpecular(float*);
		void setLightKc(float f) { this->light_kc = f; }
		void setLightKl(float f) { this->light_kl = f; }
		void setLightKq(float f) { this->light_kq = f; }
		
		static float background_ambient[4];

	protected:
		static CGFappearance* default_light_material;

		unsigned int id;
		float light_ambient[4];
		float light_diffuse[4];
		float light_specular[4];
		float light_kc;
		float light_kl;
		float light_kq;

		GLUquadric* glu_quadric;

		float position[4];
		CGFappearance* material;

};

#endif
