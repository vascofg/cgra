#ifndef CG_CGFaxis
#define CG_CGFaxis

/**
 * @file CGFaxis.h
 * CGFobject representing the three axis.
 * 
 * This class implements three axis to show the use of the CGFobject class.
 */

#include "CGFobject.h"
#include <GL/glut.h>

#define CG_CGFaxis_DEFAULT_RADBEG 0.1
#define CG_CGFaxis_DEFAULT_RADEND 0.0
#define CG_CGFaxis_DEFAULT_LENGTH 16.0
#define CG_CGFaxis_DEFAULT_SLICES 8
#define CG_CGFaxis_DEFAULT_STACKS 1
#define CG_CGFaxis_DEFAULT_SPHRAD 0.2
#define CG_CGFaxis_DEFAULT_SPHSLI 8
#define CG_CGFaxis_DEFAULT_SPHSTK 16

class CGFaxis: public CGFobject {
	public:
		CGFaxis();
		~CGFaxis();
		void draw();

	protected:
		double radius_begin;
		double radius_end;
		double lenght;
		int nslices;
		int nstacks;

		double ball_radius;
		int ball_slices;
		int ball_stacks;

		GLUquadric* glu_quadric;
};

#endif
