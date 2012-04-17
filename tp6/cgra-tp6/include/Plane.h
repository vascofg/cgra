#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void draw(int xDiv, int yDiv);
	void drawMaintainRatio(int textureWidth, int textureHeight);
	void drawCentered();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	int xDiv, yDiv;
};

