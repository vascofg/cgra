#include <math.h>

#include "MyPaperPlane.h"
#include "iostream"
using namespace std;

void MyPaperPlane::draw() {
    scale = 0.2;
    glPushMatrix();
    glTranslated(Xpos, Ypos, Zpos);
    glRotated(rotation, 1, 0, 0);
    // The plane is composed by 3 triangles
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        // In this way we can draw a full paper plane with a cycle
        glRotated(i * 90, 1, 0, 0);
        // wing
        glBegin(GL_TRIANGLES);
        //Top (anti-clockwise)
        glVertex3f(scale * 5, 0, i == 1 ? scale * 2 : scale * 3);
        glVertex3f(scale * 5, 0, 0);
        glVertex3f(0, 0, 0);
        // Bottom (clockwise)
        glVertex3f(0, 0, 0);
        glVertex3f(scale * 5, 0, 0);
        glVertex3f(scale * 5, 0, i == 1 ? scale * 2 : scale * 3);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

}

MyPaperPlane::MyPaperPlane() {
    bool collision = false;
}

void MyPaperPlane::update(long milis) {
    // (1) get the seconds
    float secondsT = milis / 1000.0;

    // (2) cinematic variables (projectile movement with aerodynamics)
    // see more here http://pt.wikipedia.org/wiki/Sustenta%C3%A7%C3%A3o_(aerodin%C3%A2mica)
    float g = 9.8;

    // angle of launching (rads)
    float angleRad = 0.5;

    // the velocity (m/s)
    float velocity = 5; // the velocity vector norm
    float v0x = velocity * cos(angleRad);
    float v0y = velocity * sin(angleRad);
    float vx = v0x;
    float vy = v0y - 0.15 * secondsT; // fake aproximation cause this dependes of lift

    // initial positions
    float z0 = 7;
    float y0 = 6;
    float x0 = 10;

    // lifts
    float actualSpeed = (float) sqrt(vx * vx + vy * vy); // compute the norm
    float kL = 0.35; // fake aproximmation
    float arDensity = 1.225;
    float wingArea = (5 * 3 / 2.0) * scale;
    float lift = kL * arDensity / 2.0 * wingArea * actualSpeed*actualSpeed;

    // forces
    float forceY = g - lift;

    // (3) cinematic equations (projectile movement)
    Zpos = z0;
    Ypos = y0;
    Xpos = x0;

    Zpos = z0;
    Xpos = x0 - v0x*secondsT;
    Ypos = y0 + v0y * secondsT - 1 / 2.0 * (forceY * secondsT * secondsT);
    
    // (4) debug info
    cout << "y=" << Ypos << " x=" << Xpos << " velocity=" << vy << " m/s" << endl;
        
    // Colision detection
    if ((Zpos < 0.1) | (Ypos < 0.1) | (Xpos < 0.1))
        handleCollision(milis);


}

void MyPaperPlane::handleCollision(float milis) {
    //  get the seconds
    float secondsT = milis / 1000.0;
    float g = 1;
    Zpos = 8;
    Ypos = 5 - 1 / 2.0 * g * secondsT*secondsT;
    rotation=180-180*1/(float)secondsT; // plane flip while falls
    // collision
    if (Ypos < 0) {
        Ypos = 0.05;
        rotation = 180; // flip over
    }
    Xpos = 0;

}