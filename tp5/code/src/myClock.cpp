#include "myClock.h"
#include "myMaterials.h"
#include "MyClockHand.h"
#include <iostream>
using namespace std;
myClock::myClock(){
    c=new myCylinder(12,1,0);
    seconds= new MyClockHand;
    minutes= new MyClockHand;
    hours= new MyClockHand;
    
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
    
    // Translate pointer 0.1 in z
    glTranslated(0,0,0.1);
    
    // seconds pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            seconds->setScale(0.4,1,1);
            seconds->setAngle(180+90);
            seconds->draw();
    glPopMatrix();

    // minutes pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            minutes->setAngle(180);
            minutes->draw();
    glPopMatrix();

    // hours pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            hours->setScale(1,0.85,1);
            hours->setAngle(90);
            hours->draw();
    glPopMatrix();



    
}
 void myClock::update(long milis){
     cout << " DEBUG MODE: UPDATE: " <<milis << endl;
     // Calculate seconds and angle
     float secondsT=milis/1000.0;
     float secondsAngle=secondsT/60.0*360;
     
     // Calculate seconds and angle
     float minutesT=secondsT/60.0;
     float minutesAngle=minutesT/60.0*360;
     
     // Calculate seconds and angle
     float hoursT=minutesT/60.0;
     float hoursAngle=hoursT/60.0*360;
     
     // Clock appearance
    clockAppearance *clockMaterial=new clockAppearance();
    clockMaterial->apply();
    glEnable (GL_TEXTURE_2D);
    
    // New GLU quadric
    GLUquadric *clock = gluNewQuadric();
    gluQuadricTexture (clock, GL_TRUE);
    gluDisk(clock, 0, 1, 12, 1);
    
    // Translate pointers 0.1 in z
    glTranslated(0,0,0.1);
    
    // seconds pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            seconds->setScale(0.4,1,1);
            seconds->setAngle(secondsAngle);
            seconds->draw();
    glPopMatrix();

    // minutes pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            minutes->setAngle(minutesAngle);
            minutes->draw();
    glPopMatrix();

    // hours pointer
    glPushMatrix();
            glScaled(0.7,1,1);
            hours->setScale(1,0.85,1);
            hours->setAngle(hoursAngle);
            hours->draw();
    glPopMatrix();
     
 }