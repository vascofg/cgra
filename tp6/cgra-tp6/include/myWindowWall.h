/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef MYWINDOWWALL_H_
#define MYWINDOWWALL_H_
#include "myMaterials.h"
#include "Plane.h"
/**
 * myWindowWall - A class for defining the "impostor"
 */
class myWindowWall: public CGFobject {
	landscapeAppearance * landscapeMaterial;	/* landscape material */
public:
	/* Constructor */
	myWindowWall();
	/* Draws the window wall and the landscape */
	void draw();

};

#endif /* MYWINDOWWALL_H_ */
