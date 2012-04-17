#ifndef CG_CGFappearance
#define CG_CGFappearance

/**
 * @file CGFappearance.h
 * Appearance class of CGF.
 * 
 * This class is useful to keep data on color and material so you can apply them to an object.
 */

#include <vector>
#include <string>

using namespace std;

class CGFappearance {
	public:
		CGFappearance();
		CGFappearance(float*, float*, float*, float);
		CGFappearance(float*);
		CGFappearance(string, int, int);


		~CGFappearance();

		void apply();

		void setAmbient(float*);
		void setDiffuse(float*);
		void setSpecular(float*);
		void setShininess(float);

		void setTexture(string);
		void setTextureWrap(int, int);

	protected:

		int materialType;

		float ambient[3];
		float diffuse[3];
		float specular[3];
		float shininess;

		float color[3];

		string texName;
		int sWrap, tWrap;

		int texWidth, texHeight;

		unsigned int texID;
};

#endif
