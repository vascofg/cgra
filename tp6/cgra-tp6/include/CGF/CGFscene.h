#ifndef CG_CGFscene
#define CG_CGFscene

/**
 * @file CGFscene.h
 * Scene class of CGF.
 * 
 * This class stores information on one 3D scene, including cameras, lights and objects.
 */

#include <list>
#include <vector>

#include "CGFobject.h"
#include "CGFaxis.h"
#include "CGFlight.h"
#include "CGFcamera.h"
#include "CGFinterface.h"

class CGFscene {
	public:
		CGFscene();
		~CGFscene();

		void initCameras();

		virtual void init();
		virtual void display();
		virtual void update(long millis);

		CGFcamera* activeCamera;
		
		void activateCamera(int i);

		CGFaxis axis;
		void checkUpdate();

		void setInterface(CGFinterface *i);

	protected:
		void setUpdatePeriod(long millis);

		long updatePeriod;
		long lastUpdate;

		CGFinterface *iface;

		std::list<CGFlight*> scene_lights;
		std::list<CGFobject*> scene_objects;
		std::vector<CGFcamera*> scene_cameras;
};

#endif
