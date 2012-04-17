#include <math.h>

#include "MyPaperPlane.h"
#include "iostream"
using namespace std;
void MyPaperPlane::draw() {
    float scale=0.2;
    glPushMatrix();
    glTranslated(Xpos,Ypos,Zpos);
    glRotated(-90,0,1,0);
    // The plane is composed by 3 triangles
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        // In this way we can draw a full paper plane with a cycle
        glRotated(i*90,1,0,0);
            // wing
            glBegin(GL_TRIANGLES);
            //Top (anti-clockwise)
            glVertex3f(scale*5, 0, i==1?scale*2:scale*3);
            glVertex3f(scale*5, 0, 0);
            glVertex3f(0, 0, 0);
            // Bottom (clockwise)
            glVertex3f(0, 0, 0);
            glVertex3f(scale*5, 0, 0);
            glVertex3f(scale*5, 0, i==1?scale*2:scale*3);
            glEnd();
        glPopMatrix();
    }
    glPopMatrix();

}

MyPaperPlane::MyPaperPlane() {

}

 void MyPaperPlane::update(long milis){
     // (1) get the seconds
     float secondsT=milis/1000.0;
     // (2) cinematic variables (projectile movement)
     float v0=50; // m/s
     float angle=30; // degrees 
     long double g=0.000000000000000008; // m/s
     float z0=7;
     float y0=4;
     // (3) cinematic equations

     Xpos=5;
     Zpos=z0-(v0*cos(angle)*secondsT); // is minus because the z-axis
     cout << "DeltaZ: " << Zpos << "\n";
     Ypos=y0+v0*sin(angle)*secondsT+(g*secondsT*secondsT)/(float)2 ;
      cout << "DeltaY: " << Ypos << "\n";
    
     
     
 }