#include "CGFinterface.h"
#include "CGFscene.h"
#include "CGFapplication.h"
#include <GL/glui.h>

#define MOUSE_ROTATE_FACTOR 0.5
#define MOUSE_PAN_FACTOR 0.05
#define MOUSE_ZOOM_FACTOR 0.5

CGFinterface::CGFinterface() {
}

CGFinterface::~CGFinterface() {
}

CGFinterface * CGFinterface::activeInterface=NULL;

void CGFinterface::setScene(CGFscene *sc) 
{
	scene=sc;
}


void CGFinterface::init(int parent) {

	glui_window = GLUI_Master.create_glui_subwindow(parent, GLUI_SUBWINDOW_BOTTOM);
	GLUI_Master.set_glutKeyboardFunc(CGFinterface::preprocessKeyboard);

	GLUI_Master.set_glutMouseFunc(CGFinterface::preprocessMouse);
	glutMotionFunc(CGFinterface::preprocessMouseMoved);
	glutPassiveMotionFunc(CGFinterface::preprocessPassiveMouseMoved);
	this->displacementX = 0;
	this->displacementY = 0;

	pressing_left=false;
	pressing_right=false;
	pressing_middle=false;

	this->prev_X = 0;
	this->prev_Y = 0;
}

void CGFinterface::initControls()
{
};


GLUI_Panel* CGFinterface::addPanel(char* name)
{
	return glui_window->add_panel(name);
}

GLUI_Checkbox* CGFinterface::addCheckbox(char* name, int* value, int id,GLUI_CB cb )
{
	return glui_window->add_checkbox(name, value, id, cb);
}

GLUI_Checkbox* CGFinterface::addCheckboxToPanel(GLUI_Panel *p,char* name, int* value,int id ,GLUI_CB cb)
{
	return glui_window->add_checkbox_to_panel(p,name, value,id,cb);
}

GLUI_Button* CGFinterface::addButton(char* name,int id , GLUI_CB callback)
{
	return glui_window->add_button(name, id, callback);
}

GLUI_Button* CGFinterface::addButtonToPanel(GLUI_Panel *p,char* name, int id ,GLUI_CB cb )
{
	return glui_window->add_button_to_panel(p,name, id, cb);
}

void CGFinterface::addColumn()
{
	glui_window->add_column();
}

void CGFinterface::addColumnToPanel(GLUI_Panel *p)
{
	glui_window->add_column_to_panel(p);
}

GLUI_EditText* CGFinterface::addEditText(char* name, char* var, int id ,GLUI_CB cb)
{
	return glui_window->add_edittext(name,GLUI_EDITTEXT_STRING, var,id,cb);
}

GLUI_EditText* CGFinterface::addEditText(char* name, int* var, int id ,GLUI_CB cb )
{
	return glui_window->add_edittext(name,GLUI_EDITTEXT_INT, var,id,cb);
}

GLUI_EditText* CGFinterface::addEditText(char* name, float* var, int id ,GLUI_CB cb )
{
	return glui_window->add_edittext(name,GLUI_EDITTEXT_FLOAT, var,id,cb);
}

GLUI_EditText* CGFinterface::addEditTextToPanel(GLUI_Panel *p,char* name, char* var, int id ,GLUI_CB cb )
{
	return glui_window->add_edittext_to_panel(p,name,GLUI_EDITTEXT_FLOAT, var,id,cb);
}

GLUI_EditText* CGFinterface::addEditTextToPanel(GLUI_Panel *p,char* name, int* var, int id ,GLUI_CB cb)
{
	return glui_window->add_edittext_to_panel(p,name,GLUI_EDITTEXT_FLOAT, var,id,cb);
}

GLUI_EditText* CGFinterface::addEditTextToPanel(GLUI_Panel *p,char* name, float* var, int id ,GLUI_CB cb )
{
	return glui_window->add_edittext_to_panel(p,name,GLUI_EDITTEXT_FLOAT, var,id,cb);
}

GLUI_Listbox* CGFinterface::addListbox(char* name, int* var, int id ,GLUI_CB cb)
{
	return glui_window->add_listbox(name,var,id,cb);
}

GLUI_Listbox* CGFinterface::addListboxToPanel(GLUI_Panel *p,char* name, int* var, int id,GLUI_CB cb)
{
	return glui_window->add_listbox_to_panel(p,name,var,id,cb);
}

GLUI_Panel* CGFinterface::addPanel(char* name, int type )
{
	return glui_window->add_panel(name,type);
}

GLUI_Panel* CGFinterface::addPanelToPanel(GLUI_Panel *p,char* name, int type)
{
	return glui_window->add_panel_to_panel(p,name,type);
}

GLUI_RadioButton* CGFinterface::addRadioButtonToGroup(GLUI_RadioGroup * group, char * name)
{
	return glui_window->add_radiobutton_to_group(group,name);
}

GLUI_RadioGroup* CGFinterface::addRadioGroup(int *var, int id, GLUI_CB cb )
{
	return glui_window->add_radiogroup(var,id,cb);

}

GLUI_RadioGroup* CGFinterface::addRadioGroupToPanel(GLUI_Panel *p,int *var, int id, GLUI_CB cb )
{
	return glui_window->add_radiogroup_to_panel(p,var,id,cb);

}

GLUI_Rollout* CGFinterface::addRollout(char *name, int open, int type )
{
	return glui_window->add_rollout(name,open,type);
}

GLUI_Rollout* CGFinterface::addRolloutToPanel(GLUI_Panel* p,char *name, int open, int type )
{
	return glui_window->add_rollout_to_panel(p,name,open,type);
}

void CGFinterface::addSeparator()
{
	return glui_window->add_separator();
}

void CGFinterface::addSeparatorToPanel(GLUI_Panel *p)
{
	return glui_window->add_separator_to_panel(p);
}

GLUI_Rotation* CGFinterface::addRotation(char* name, float* var, int id, GLUI_CB cb)
{
	return glui_window->add_rotation(name,var,id,cb);
}

GLUI_Rotation* CGFinterface::addRotationToPanel(GLUI_Panel *p,char* name, float* var, int id, GLUI_CB cb)
{
	return glui_window->add_rotation_to_panel(p,name,var,id,cb);
}


GLUI_Spinner* CGFinterface::addSpinner(char* name, int type, int* var, int id, GLUI_CB cb)
{
	return glui_window->add_spinner(name,type,var,id,cb);
}

GLUI_Spinner* CGFinterface::addSpinnerToPanel(GLUI_Panel* p,char* name, int type, int* var, int id, GLUI_CB cb )
{
	return glui_window->add_spinner_to_panel(p,name,type,var,id,cb);
}

GLUI_StaticText* CGFinterface::addStaticText(char* name)
{
	return glui_window->add_statictext(name);
}

GLUI_StaticText* CGFinterface::addStaticTextToPanel(GLUI_Panel *p,char* name)
{
	return glui_window->add_statictext_to_panel(p,name);
}

GLUI_Translation* CGFinterface::addTranslationToPanel(GLUI_Panel* p,char* name, int type, float* var, int id, GLUI_CB cb)
{
	return glui_window->add_translation_to_panel(p,name,type,var,id,cb);
}

GLUI_Translation* CGFinterface::addTranslation(char* name, int type, float* var, int id, GLUI_CB cb)
{
	return glui_window->add_translation(name,type,var,id,cb);
}

void CGFinterface::preprocessKeyboard(unsigned char key, int x, int y)
{
	activeInterface->processKeyboard(key,x,y); 
}

void CGFinterface::preprocessMouse(int button, int state, int x, int y) {
	activeInterface->processMouse(button, state, x,y); 
}

void CGFinterface::preprocessMouseMoved(int x, int y) {
	activeInterface->processMouseMoved(x,y); 
}

void CGFinterface::preprocessPassiveMouseMoved(int x, int y)
{ 
	activeInterface->processPassiveMouseMoved(x,y); 
}



// Default handlers (to be overriden by sub-class)

void CGFinterface::processKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'w':
			scene->activeCamera->setWalkMode();
			break;
		case 'e':
			scene->activeCamera->setExamineMode();
			break;

		case 's':
			CGFapplication::snapshot();
			break;

		case 27:		// tecla de escape termina o programa
			exit(0);
			break;
	}
}

void CGFinterface::processMouse(int button, int state, int x, int y) {

	
	this->prev_X = x;
	this->prev_Y = y;

	pressing_left = (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN);
	pressing_right = (button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN);
	pressing_middle = (button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN);
	/*
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) 
		{	
			pressing_left = true;
		}
		else
			pressing_left = false;

	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) 
		{	
			pressing_right = true;
			this->prev_X = x;
			this->prev_Y = y;
		}
		else
			pressing_right = false;

	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) 
		{	
			pressing_right = true;
			this->prev_X = x;
			this->prev_Y = y;
		}
		else
			pressing_right = false;

			*/

	glutPostRedisplay();
	
}

void CGFinterface::processMouseMoved(int x, int y) {
	
	// pedido de refrescamento da janela
	this->displacementX = x- this->prev_X;
	this->displacementY = y- this->prev_Y;


	if(pressing_left)
	{
		scene->activeCamera->rotate(CG_CGFcamera_AXIS_X, displacementY*MOUSE_ROTATE_FACTOR);
		scene->activeCamera->rotate(CG_CGFcamera_AXIS_Y, displacementX*MOUSE_ROTATE_FACTOR);
	}
	else if(pressing_right)
	{
		scene->activeCamera->translate(CG_CGFcamera_AXIS_X, displacementX*MOUSE_PAN_FACTOR);
		scene->activeCamera->translate(CG_CGFcamera_AXIS_Y, -displacementY*MOUSE_PAN_FACTOR);
	}
	else if(pressing_middle)
	{
		scene->activeCamera->translate(CG_CGFcamera_AXIS_Z, displacementY*MOUSE_ZOOM_FACTOR);
	}


	this->prev_X = x;
	this->prev_Y = y;

	glutPostRedisplay();				

}

void CGFinterface::processPassiveMouseMoved(int x, int y) {

	// pedido de refrescamento da janela
	glutPostRedisplay();				
}
