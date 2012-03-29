#ifndef CG_CGFappearance
#define CG_CGFappearance

/**
 * @file CGFappearance.h
 * Appearance class of CGF.
 * 
 * This class is useful to keep data on color, material and textures so you can apply them to an object.
 */

#include <vector>

#define CG_GLMAT_COLOR 0
#define CG_GLMAT_MATERIAL 1
#define CG_GLMAT_TEXTURE 2

class CGFappearance {
	public:
		CGFappearance();
		CGFappearance(float*, float*, float*, float);
		CGFappearance(float*);
		~CGFappearance();

		void apply();

		static std::vector<CGFappearance*> appearances;

	protected:
		static unsigned int __next_id;
		unsigned int id;

		bool isMaterial;

		float ambient[3];
		float diffuse[3];
		float specular[3];
		float shininess[1];

		float color[3];
};

#endif
