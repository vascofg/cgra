#include "myClock.h"
#include "myMaterials.h"
myClock::myClock(){
    c=new myCylinder(12,1,0);
    
}

void myClock::draw(){
    // Clock appearance
    clockAppearance *clockMaterial=new clockAppearance();
    clockMaterial->apply();
    glEnable (GL_TEXTURE_2D);
    
    // New GLU quadric
    GLUquadric *clock = gluNewQuadric();
    gluQuadricTexture (clock, GL_TRUE);
    gluDisk(clock, 0, 1, 12, 1);
}