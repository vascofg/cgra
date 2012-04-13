#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myUnitCube.h"
#include <math.h>

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = {0, 0, 0, 1.0};

// Constants for materials
#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

void LightingScene::init() {
    // Enables lighting computations
    glEnable(GL_LIGHTING);

    // Sets up some lighting parameters
    // Computes lighting only using the front face normals and materials
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    // Define ambient light (do not confuse with ambient component of individual lights)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

    // Declares and enables lights
    initLights();

    // Uncomment below to enable normalization of lighting normal vectors
    glEnable(GL_NORMALIZE);

    // Declares objects
    table = new myTable();
    leftWall = new Plane(20);
    planeWall = new Plane();
    floor = new Plane();
    boardA = new Plane(BOARD_A_DIVISIONS);
    boardB = new Plane(BOARD_B_DIVISIONS);
    column = new myCylinder(14, 8, 1);
    clock = new myClock();

    // Declare Materials
    boardMaterial = new boardAppearance();
    slidesMaterial = new slidesAppearance();
    floorMaterial = new floorAppearance();
    wallMaterial = new wallAppearance();
    windowMaterial = new windowAppearance();
    marbleMaterial = new marbleAppearance();

}

void LightingScene::display() {

    // ---- BEGIN Background, camera and axis setup

    // Clear image and depth buffer everytime we update the scene
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Initialize Model-View matrix as identity (no transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);

    // Apply transformations corresponding to the camera position relative to the origin
    CGFscene::activeCamera->applyView();
    // Draw axis
    axis.draw();
    light0->draw();
    lightBoardA->draw();
    lightBoardB->draw();
    // ---- END Background, camera and axis setup

    // ---- BEGIN Primitive drawing section

    // Clock
    glPushMatrix();
        glTranslated(7.5, 7, 0.3);
        clock->draw();
    glPopMatrix();

    //Left Table
    glPushMatrix();
    glTranslated(5, 0, 8);
    table->draw();
    glPopMatrix();

    //Right Table
    glPushMatrix();
    glTranslated(12, 0, 8);
    table->draw();
    glPopMatrix();

    //Floor
    glPushMatrix();
    glTranslated(7.5, 0, 7.5);
    glScaled(15, 0.2, 15);
    floorMaterial->apply();
    floor->draw(10, 12);
    glPopMatrix();

    // Left Wall
    glPushMatrix();
    glTranslated(0, 0, 7.5);
    glRotated(90.0, 0, 1, 0);
    glTranslated(0, 4, 0);
    glRotated(90.0, 1, 0, 0);
    glScaled(15, 0.2, 8);
    windowMaterial->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    windowMaterial->apply();
    leftWall->drawCentered();
    glPopMatrix();

    //Plane Wall
    glPushMatrix();
    glTranslated(7.5, 4, 0);
    glRotated(90.0, 1, 0, 0);
    glScaled(15, 0.2, 8);
    wallMaterial->setTextureWrap(GL_REPEAT, GL_REPEAT);
    wallMaterial->apply();
    planeWall->draw();
    glPopMatrix();


    // Slides Board A
    glPushMatrix();
    glTranslated(3.2, 4, 0.2);
    glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
    glRotated(90.0, 1, 0, 0);
    slidesMaterial->apply();
    boardA->draw();
    glPopMatrix();

    //Board B
    glPushMatrix();
    glTranslated(11.8, 4, 0.2);
    glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
    glRotated(90.0, 1, 0, 0);
    boardMaterial->apply();
    boardB->drawMaintainRatio(512, 372);
    glPopMatrix();


    // Columns
    glPushMatrix();
    marbleMaterial->apply();
    glScaled(0.4, 1, 0.4);
    glTranslated(7, 0, 35);
    column->draw();
    glTranslated(25, 0, 0);
    column->draw();
    glPopMatrix();
    // ---- END Primitive drawing section


    // We have been drawing in a memory area that is not visible - the back buffer, 
    // while the graphics card is showing the contents of another buffer - the front buffer
    // glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
    glutSwapBuffers();
}

LightingScene::~LightingScene() {

}

