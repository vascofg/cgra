#ifndef CG_CGFcamera
#define CG_CGFcamera

/**
 * @file CGFcamera.h
 * Camera class for the CGF framework.
 * 
 * This class can be used to implement a point of view for the application.
 */

#define CG_CGFcamera_AXIS_X 0
#define CG_CGFcamera_AXIS_Y 1
#define CG_CGFcamera_AXIS_Z 2

class CGFcamera {
	public:
		CGFcamera();
		~CGFcamera();

		bool rotateTo(int axis, float angle, float increment = 0.5f);
		bool rotate(int axis, float angle);
		bool setRotation(int axis, float angle);
		bool moveTo(int axis, float value, float increment=0.5f);
		bool translate(int axis, float value);

		void setX(float value);
		void setY(float value);
		void setZ(float value);

		void applyView();

	//private:
		float position[3]; //= {0.0,0.0,-25.0};
		float target[3]; //= {0.0,0.0,0.0};
		float rotation[3];// = {0.0,0.0,0.0};

		enum CAMERA_MODE { EXAMINE_MODE, WALK_MODE, TARGET_MODE };

		CAMERA_MODE mode;

		void setExamineMode();
		void setWalkMode();
};

#endif
