#ifndef CG_CGFapplication
#define CG_CGFapplication

/**
 * @file CGFapplication.h
 * Application class of CGF.
 * 
 * This is the main class for an OpenGL application where you can add scenes, interfaces and manage other aspects of the application.
 */

#include "CGFscene.h"
#include "CGFinterface.h"

#include <stdexcept>
#include <string>

class GLexception: public std::runtime_error {
	public:
		GLexception(const std::string& what_str): runtime_error(what_str) {}

};

#define CG_GLAPP_DISPLAY_MODE GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA
#define CG_GLAPP_INIT_WIDTH 500
#define CG_GLAPP_INIT_HEIGHT 500
#define CG_GLAPP_INIT_POSX 200
#define CG_GLAPP_INIT_POSY 200
#define CG_GLAPP_REDBITS 8
#define CG_GLAPP_BLUEBITS 8
#define CG_GLAPP_GREENBITS 8

class CGFapplication {
	public:
		CGFapplication();
		~CGFapplication();
		void init(int*, char**);
		void run();
		
		void setScene(CGFscene* gls);
		void setInterface(CGFinterface* gli);

		int getMainWindow();

		static void snapshot();

		static float xy_aspect;
		static int width;
		static int height;

		static long getTime();

	protected:
		void activate();

		static int app_window;
		static CGFapplication *activeApp;

		CGFscene* app_scene;

		CGFinterface* app_interface;

		void static gluiIdleFunction(void);
		void static reshape(int, int);
		void static display();
		void environmentInit();
		void updateScene(); 
};

#endif
