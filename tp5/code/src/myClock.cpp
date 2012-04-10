#include "myClock.h"
#include "myMaterials.h"
myClock::myClock(){
    c=new myCylinder(12,1,0);
    
}

void myClock::draw(){
    clockAppearance *clockMaterial=new clockAppearance();
    clockMaterial->apply();
    c->draw();
}