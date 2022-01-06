#include "base.h"
#include "view.h"
#include "render.h"
#include "ground.h"
#include "bedrock.h"

void renderTeaPot()
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3d(WHITE);
    glutWireTeapot(1);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    updateViewAng();
    // renderTeaPot();
    renderBedrock();
    renderGround();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double)w/h, 0.1, RENDERDISTANCE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}