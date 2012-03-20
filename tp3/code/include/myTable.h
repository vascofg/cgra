#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "CGFappearance.h"
class myTable: public CGFobject {
	CGFappearance* material;

	public:
		void draw();
};

#endif
