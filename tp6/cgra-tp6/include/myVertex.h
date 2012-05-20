/****************************************************************************
 * Author:	- André Freitas, p.andrefreitas@gmail.com / ei10036@fe.up.pt	*
 * Author:	- Vasco Gonçalves, vascofg@gmail.com / ei10054@fe.up.pt			*
 * Copyright: - 21/05/2012, Computação Gráfica, FEUP						*
 ****************************************************************************/
#ifndef MYVERTEX_H_
#define MYVERTEX_H_
#include <vector>
using namespace std;
/**
 * myVertex - a class for defining a vertex with his coordinates and basic transformations
 * x, y and z remains public for easy use
 */
class myVertex {
public:
	double x; /* x value */
	double y; /* y value */
	double z; /* z value */
	/**
	 * Constructor
	 * @param x the x value
	 * @param y the y value
	 * @param z the z value
	 */
	myVertex(double x, double y, double z);
	/**
	 * Rotates the vertex in the XZ plane
	 * @param angleRad the angle in radians
	 */
	void rotateY(double angleRad);

	/**
	 * Rotates the vertex in the XY plane
	 * @param angleRad the angle in radians
	 */
	void rotateZ(double angleRad);

	/**
	 * Translates the point in 3 dimensions
	 * @param dx the x translation
	 * @param dy the y translation
	 * @param dz the z translation
	 */
	void translate(double dx, double dy, double dz);
};

/**
 * mySemiRect - a class for defining a semirect that goes from a to b
 * We can get points between a and b that is very useful
 */
class mySemiRect {
	public:
		myVertex *begin;		      /* pointer to begin vertex */
		myVertex *end;				  /* pointer to end vertex */
		double divideStep; 			  /* it's a little difficult to explain, but think like this:  a+(b-a)/divideStep * t */
		double deltaX,deltaY,deltaZ; /* the step in every dimension */
		/**
		 * The constructor
		 * @param begin a pointer to the begin vertex
		 * @param end a pointer to the end vertex
		 * @param divideStep it's a little difficult to explain, but think like this:  a+(b-a)/divideStep * t
		 */
		mySemiRect(myVertex *begin, myVertex *end, double divideStep);
		/*
		 * Get a vertex in the semiRect
		 * @param t the increment over the vector
		 */
		myVertex getVertexT(int t);
};
/**
 * This function computes the normal of a polygon by giving the list of its vertex.
 * Implemented from: http://www.opengl.org/wiki/Calculating_a_Surface_Normal
 * @param vertexList the list of the polygon's vertexs
 * @return a myVertex object thas is the normal
 */
myVertex computeNormalNewel(vector<myVertex> vertexList);
#endif /* MYVERTEX_H_ */
