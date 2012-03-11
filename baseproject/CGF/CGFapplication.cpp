#include "CGFapplication.h"
#include <GL/glut.h>
#include <GL/glui.h>
#include <time.h>
#include "version.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdlib.h>
using namespace std;

int CGFapplication::app_window = NULL;

float CGFapplication::xy_aspect = NULL;

CGFapplication * CGFapplication::activeApp = NULL;

int CGFapplication::width = NULL;
int CGFapplication::height = NULL;

CGFapplication::CGFapplication() {
	char idstr[256];
	strcpy(idstr,CGFId+3);
	idstr[strlen(idstr)-1]=0;

	printf("CGF (Computer Graphics @ FEUP) library %s %s\n",(CGFVersion[0]=='$')?"":CGFVersion, idstr);

	CGFapplication::app_window = NULL;
	CGFapplication::app_scene = NULL;
	this->app_interface = NULL;
}

void CGFapplication::activate()
{
	CGFapplication::activeApp=this;
}

void CGFapplication::setScene(CGFscene* gls)
{ 
	app_scene = gls; 
	app_scene->init(); 
}

void CGFapplication::setInterface(CGFinterface* gli) 
{ 
	app_interface = gli; 
	
	app_interface->setScene(app_scene);
	
	app_interface->init(CGFapplication::app_window); 
	app_interface->initControls(); 
	
	CGFinterface::setActiveInterface(gli);
}

int CGFapplication::getMainWindow() 
{ 
	return CGFapplication::app_window; 
}


CGFapplication::~CGFapplication() {
}

void CGFapplication::init(int* argc, char** argv) {

	try {
		glutInit(argc, argv);
		glutInitDisplayMode(CG_GLAPP_DISPLAY_MODE);

		CGFapplication::width = CG_GLAPP_INIT_WIDTH;
		CGFapplication::height = CG_GLAPP_INIT_HEIGHT;
		glutInitWindowSize(CGFapplication::width, CGFapplication::height);
		glutInitWindowPosition(CG_GLAPP_INIT_POSX, CG_GLAPP_INIT_POSY);

		CGFapplication::app_window = glutCreateWindow(argv[0]);

		glutDisplayFunc(CGFapplication::display);
		GLUI_Master.set_glutIdleFunc(CGFapplication::gluiIdleFunction);
		GLUI_Master.set_glutReshapeFunc(CGFapplication::reshape);
	}
	catch(std::exception& ex) {
		throw GLexception("CGFapplication::init falhou na execucao");
	}

	return;
}

void CGFapplication::run() {
	activate();

	this->environmentInit();
	glutMainLoop();

	return;
}

void CGFapplication::display() {
	CGFapplication::activeApp->app_scene->display();
}

/* GLUI IDLE FUNCTION
 * This function may have to be re-implemented
 */
void CGFapplication::gluiIdleFunction()
{
	/* According to GLUT, the current window may be
	 * undefined when idle is called back. 
	 */
	if (glutGetWindow()!=CGFapplication::app_window) glutSetWindow(CGFapplication::app_window);  

	glutPostRedisplay();

	/****************************************************************/
	/*            This demonstrates GLUI::sync_live()               */
	/*   We change the value of a variable that is 'live' to some   */
	/*   control.  We then call sync_live, and the control          */
	/*   associated with that variable is automatically updated     */
	/*   with the new value.  This frees the programmer from having */
	/*   to always remember which variables are used by controls -  */
	/*   simply change whatever variables are necessary, then sync  */
	/*   the live ones all at once with a single call to sync_live  */
	/****************************************************************/

	//glui->sync_live();

	return;
}

/* ENVIRONMENT INITIALIZATION FUNCTION
 * This function may have to be re-implemented
 */
void CGFapplication::environmentInit() {

	//glDepthFunc(GL_LESS);		/* default */
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_DEPTH_TEST);	/* Usar z-buffer para desenhar so os objetos visiveis */

	glFrontFace(GL_CCW);		/* Faces da frente definidas em CounterClockWise */

	glCullFace(GL_BACK);		/* Cull apenas nas faces de trás */
	glEnable(GL_CULL_FACE);		/* Usar Cull para melhorar performance */

	glClearColor(0.0,0.0,0.0,1.0);	/* default - fundo preto */
	//glClearColor(1.0,1.0,1.0,1.0);	/* fundo branco */
	
	glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);

	glPolygonMode(GL_FRONT, GL_FILL);	/* preenche as faces da frente */
	//glPolygonMode(GL_FRONT, GL_LINE);	/* desenha apenas as arestas das faces */
	
}

void CGFapplication::reshape(int w, int h)
{
	CGFapplication::width = w;
	CGFapplication::height = h;

	int tx, ty, tw, th;

	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );
	CGFapplication::xy_aspect = (float)tw / (float)th;

	// Inicializacoes da matriz de visualizacao
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-CGFapplication::xy_aspect*.04, CGFapplication::xy_aspect*.04, -.04, .04, .1, 50.0);


	glutPostRedisplay();
}

void CGFapplication::snapshot() {

    time_t ltime;
    struct tm *Tm;
 
    ltime=time(NULL);
    Tm=localtime(&ltime);
 
	char ts[120];
	
	sprintf(ts,"CFGcapture_%04d%02d%02d_%02d%02d%02d.png",
            Tm->tm_year+1900,
            Tm->tm_mon+1,
            Tm->tm_mday,
            Tm->tm_hour,
            Tm->tm_min,
            Tm->tm_sec);


	/* define where to extract the snapshot from (GL_BACK or GLFRONT) */
	glReadBuffer(GL_FRONT);
	glPixelStorei(GL_PACK_ALIGNMENT,1);

	/* Allocate memory for storing the image */
	GLvoid* imageData = (GLvoid*)malloc(CGFapplication::width*CGFapplication::height*(CG_GLAPP_REDBITS+CG_GLAPP_BLUEBITS+CG_GLAPP_GREENBITS));

	/* Read the image to the buffer */
	glReadPixels(0, 0, CGFapplication::width, CGFapplication::height, GL_RGB, GL_UNSIGNED_BYTE, imageData);

	/* Save it to a JPEG file */
	stbi_write_png(ts,CGFapplication::width,CGFapplication::height,/*RGB*/3,imageData,CGFapplication::width*3);

	free(imageData);
}
