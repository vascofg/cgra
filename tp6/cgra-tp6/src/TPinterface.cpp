#include "TPinterface.h"
#include "LightingScene.h"
#include <iostream>
using namespace std;
TPinterface::TPinterface() {
    testVar = 0;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
    // Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
    CGFinterface::processKeyboard(key, x, y);

    switch (key) {
            /*
            case 'a':
            {
                    // This is an example of accessing the associated scene
                    // To test, create the function toggleSomething in your scene to activate/deactivate something
                    ((LightingScene *) scene)->toggleSomething();
                    break;
            }*/
        case 'j':
        {
            ((LightingScene *) scene)->moveRobot(1, 0);
            break;
        }
        case 'l':
        {
            ((LightingScene *) scene)->moveRobot(-1, 0);
            break;
        }
        case 'i':
        {
            ((LightingScene *) scene)->moveRobot(0, 1);
            break;
        }
        case 'k':
        {
            ((LightingScene *) scene)->moveRobot(0, -1);
            break;
        }
    }
}

void TPinterface::initGUI() {
    GLUI_Panel *varPanel = addPanel("Luzes", 1);
    addCheckboxToPanel(varPanel, "Light 0", &(((LightingScene*) scene)->light0on), 1);
    addCheckboxToPanel(varPanel, "Light Board A", &(((LightingScene*) scene)->lightBoardAon), 1);
    addCheckboxToPanel(varPanel, "Light Board B", &(((LightingScene*) scene)->lightBoardBon), 1);
    addButtonToPanel(varPanel, "Pause Clock", 4);

    // Multi texture support
    int tex;
    GLUI_Panel *texPanel= addPanel("Robot", 1);
    GLUI_Listbox *texturasList=addListboxToPanel(texPanel,"Textura ", &(((LightingScene*) scene)->robotTexture),1);
    texturasList->add_item(1,"Original");
    texturasList->add_item(2,"RobotCop");
    texturasList->add_item(3,"Wood");

    // Robot DrawMode
    GLUI_RadioGroup *drawMode=addRadioGroupToPanel(texPanel,&(((LightingScene*) scene)->robotDrawMode),1);
    addRadioButtonToGroup(drawMode,"Textured");
    addRadioButtonToGroup(drawMode,"Wireframe");




}

void TPinterface::processGUI(GLUI_Control *ctrl) {
    //printf ("GUI control id: %d\n  ",ctrl->user_id);
    switch (ctrl->user_id) {
        case 4:
        {
            if(((LightingScene*) scene)->clockon)
            {
                ((LightingScene*) scene)->clockon=0;
                ctrl->name="Resume Clock";
            }
            else
            {
                ((LightingScene*) scene)->clockon=1;
                ctrl->name="Pause Clock";
            }
            break;
        }
    };
}

