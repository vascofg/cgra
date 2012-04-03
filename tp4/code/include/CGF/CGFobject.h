#ifndef CG_CGFobject
#define CG_CGFobject

/**
 * @file CGFobject.h
 * Object class of CGF.
 * 
 * This class should be used as a base class for all the objects within a CGF scene, by reimplementation of its draw method.
 */

#include <stdlib.h>
#include <GL/glut.h>

class CGFobject {
	public:
		CGFobject();
		~CGFobject();

		virtual void draw();
};

#endif
