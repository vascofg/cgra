#ifndef MYVERTEX_H_
#define MYVERTEX_H_

class myVertex {
public:
	double x;
	double y;
	double z;
	myVertex(double x, double y, double z);
	void rotateY(double angleRad);
};

class mySemiRect {
	public:
		myVertex *begin;
		myVertex *end;
		double divideStep;
		double deltaX,deltaY,deltaZ;
		mySemiRect(myVertex *begin, myVertex *end, double divideStep);
		myVertex getVertexT(int t);
};
#endif /* MYVERTEX_H_ */
