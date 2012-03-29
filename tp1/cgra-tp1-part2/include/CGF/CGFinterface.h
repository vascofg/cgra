#ifndef CG_CGFinterface
#define CG_CGFinterface

/**
 * @file CGFinterface.h
 * CGF class to implement the interface for CGF applications.
 * 
 * This class is used to initialise the visual interface as well as the keyboard and mouse handlers for CGF applications.
 */

#include <GL/glui.h>
#include "CGFscene.h"

class CGFinterface {
	public:
		CGFinterface();
		~CGFinterface();

		// Initialization methods

		void init(int parent);
		virtual void initControls();

		// Link to scene
		void setScene(CGFscene *);

		// Active interface selection

		static CGFinterface * activeInterface;
		GLUI* glui_window;
		static void setActiveInterface(CGFinterface *gli) { activeInterface=gli; }; 

		// Static handlers to route events to the active interface instance

		static void preprocessKeyboard(unsigned char key, int x, int y);
		static void preprocessMouse(int, int, int, int);
		static void preprocessMouseMoved(int, int);
		static void preprocessPassiveMouseMoved(int, int);

		// Handlers to be overridden by subclasses

		virtual void processKeyboard(unsigned char key, int x, int y);
		virtual void processMouse(int, int, int, int);
		virtual void processMouseMoved(int, int);
		virtual void processPassiveMouseMoved(int, int);


		// Control creation methods (see GLUI documentation for details)

		GLUI_Panel* addPanel(char* name);
		GLUI_Checkbox* addCheckbox(char* name, int* value = (int*) 0, int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_Checkbox* addCheckboxToPanel(GLUI_Panel *p,char* name, int* value= (int*) 0,int id = -1,GLUI_CB cb = GLUI_CB());

		GLUI_Button* addButton(char* name,int id = -1, GLUI_CB callback = GLUI_CB());
		GLUI_Button* addButtonToPanel(GLUI_Panel *p,char* name,int id = -1, GLUI_CB callback = GLUI_CB());

		void addColumn();
		void addColumnToPanel(GLUI_Panel *p);

		GLUI_EditText* addEditText(char* name, char* var = (char*) 0,int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_EditText* addEditText(char* name, int* var = (int*) 0,int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_EditText* addEditText(char* name, float* var = (float*) 0,int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_EditText* addEditTextToPanel(GLUI_Panel *p,char* name, char* var = (char*) 0,int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_EditText* addEditTextToPanel(GLUI_Panel *p,char* name, int* var= (int*) 0,int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_EditText* addEditTextToPanel(GLUI_Panel *p,char* name, float* var= (float*) 0,int id = -1,GLUI_CB cb = GLUI_CB());

		GLUI_Listbox* addListbox(char* name, int* var= (int*) 0, int id = -1,GLUI_CB cb = GLUI_CB());
		GLUI_Listbox* addListboxToPanel(GLUI_Panel *p,char* name, int* var= (int*) 0, int id = -1,GLUI_CB cb = GLUI_CB());

		GLUI_Panel* addPanel(char* name, int type = 1);
		GLUI_Panel* addPanelToPanel(GLUI_Panel *p,char* name, int type = 1);

		GLUI_RadioButton* addRadioButtonToGroup(GLUI_RadioGroup * group, char * name);

		GLUI_RadioGroup* addRadioGroup(int *var, int id=-1, GLUI_CB cb = GLUI_CB());
		GLUI_RadioGroup* addRadioGroupToPanel(GLUI_Panel* p,int *var= (int*) 0, int id=-1, GLUI_CB cb = GLUI_CB());

		GLUI_Rollout* addRollout(char *name, int open=1, int type =1);
		GLUI_Rollout* addRolloutToPanel(GLUI_Panel* p,char *name, int open=1, int type =1);

		GLUI_Rotation* addRotation(char* name, float* var= (float*) 0, int id=-1, GLUI_CB cb = GLUI_CB());
		GLUI_Rotation* addRotationToPanel(GLUI_Panel* p,char* name, float* var= (float*) 0, int id=-1, GLUI_CB cb = GLUI_CB());

		void addSeparator();
		void addSeparatorToPanel(GLUI_Panel * p);

		GLUI_Spinner* addSpinner(char* name, int type = 2, int* var= (int*)0, int id=-1, GLUI_CB cb = GLUI_CB());
		GLUI_Spinner* addSpinnerToPanel(GLUI_Panel* p,char* name, int type = 2, int* var= (int*)0, int id=-1, GLUI_CB cb = GLUI_CB());

		GLUI_StaticText* addStaticText(char* name);
		GLUI_StaticText* addStaticTextToPanel(GLUI_Panel *p,char* name);

		GLUI_Translation* addTranslation(char* name, int type = GLUI_TRANSLATION_X, float* var = (float*) 0, int id=-1, GLUI_CB cb = GLUI_CB());
		GLUI_Translation* addTranslationToPanel(GLUI_Panel* p,char* name, int type = GLUI_TRANSLATION_X, float* var= (float*) 0, int id=-1, GLUI_CB cb = GLUI_CB());


	private:

		// Link to scene
		CGFscene *scene;

		// state and control variables to handle mouse interaction
		float displacementX;
		float displacementY;
		bool pressing_left;
		bool pressing_middle;
		bool pressing_right;
		float prev_X;
		float prev_Y;
};


#endif
