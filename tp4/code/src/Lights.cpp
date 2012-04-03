#include "LightingScene.h"
void LightingScene::initLights()
{

	// Light 0
	float light0_pos[4] = {0.5, 7, 7.5, 1.0};
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	float light0_amb[4]={0.2,0.2,0.2,1};
	float light0_diff[4]={0.6,0.6,0.6,1};
	float light0_spec[4]={0.5,0.5,0.5,1};	
	light0->setAmbient(light0_amb);
	light0->setDiffuse(light0_diff);
	light0->setSpecular(light0_spec);
	light0->enable();
	
	// Light boardA
	float lightBoardA_pos[4] = {4, 7.5, 0.5, 1.0};
	lightBoardA = new CGFlight(GL_LIGHT1, lightBoardA_pos);
	float lightBoardA_amb[4]={0.2,0.2,0.2,1};
	float lightBoardA_diff[4]={0.3,0.3,0.3,1};
	float lightBoardA_spec[4]={0.3,0.3,0.3,1};	
	lightBoardA->setAmbient(lightBoardA_amb);
	lightBoardA->setDiffuse(lightBoardA_diff);
	lightBoardA->setSpecular(lightBoardA_spec);
	lightBoardA->enable();
	
	// Light boardB
	float lightBoardB_pos[4] = {10, 7.5, 0.5, 1.0};
	lightBoardB = new CGFlight(GL_LIGHT2, lightBoardB_pos);
	float lightBoardB_amb[4]={0.2,0.2,0.2,1};
	float lightBoardB_diff[4]={0.3,0.3,0.3,1};
	float lightBoardB_spec[4]={0.3,0.3,0.3,1};	
	lightBoardB->setAmbient(lightBoardB_amb);
	lightBoardB->setDiffuse(lightBoardB_diff);
	lightBoardB->setSpecular(lightBoardB_spec);
	lightBoardB->enable();

}

