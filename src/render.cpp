#include "../include/init.h"
#include "../include/view.h"
#include "../include/render.h"
#include "../include/ground.h"
#include "../include/config.h"
#include "../include/bedrock.h"
#include "../include/pointer.h"
#include "../include/listener.h"
#include "../include/collision.h"

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
    view->updateAng();
    view->updatePos();
    collBox->updateAng();
    collBox->updatePos();
    renderBlock();
    renderCollisionBox();
    glDisable(GL_DEPTH_TEST);
    glLoadIdentity();
    renderPointer();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double)w/h, 0.01, RENDERDISTANCE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    eqnoCraft->updateSize(w, h);
}