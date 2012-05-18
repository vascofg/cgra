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

#endif /* MYVERTEX_H_ */
