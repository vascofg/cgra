/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef MYTABLE_H
#define MYTABLE_H
#include "myUnitCube.h"
#include "CGFobject.h"
#include "CGFappearance.h"
#include "myMaterials.h"
/**
 * myTable - A class for defining a table with its texture
 */
class myTable: public CGFobject {
	tableAppearance* materialTop; /* top material */
	CGFappearance *materialFeets; /* feets material */
	myUnitCube *p1;				  /* feet 1 */
	myUnitCube *p2;				  /* feet 2 */
	myUnitCube *p3;				  /* feet 3 */
	myUnitCube *p4;				  /* feet 4 */
	myUnitCube *t;				  /* top */
public:
	/* empty constructor */
	myTable();
	/* draw the table and applies texture */
	void draw();

};

#endif
