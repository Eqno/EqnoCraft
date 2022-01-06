#include "view.h"

double viewRadius = VIEWRADIUS, viewRotateX = 0, viewRotateY = 0;
double lastRotateX = viewRotateX, lastRotateY = viewRotateY;

void updateViewAng()
{   
    glTranslated(0, 0, -viewRadius);
    if (viewRotateX > 180) viewRotateX = -180;
    if (viewRotateX < -180) viewRotateX = 180;
    if (viewRotateY > 180) viewRotateY = -180;
    if (viewRotateY < -180) viewRotateY = 180;
    glRotated(viewRotateY, 1, 0, 0);
    glRotated(viewRotateX, 0, 1, 0);
}

void obverseChange(double &viewRotate, double coord, double &lastRotate, double viewMoveFac)
{
    viewRotate += viewMoveFac * (coord-lastRotate) / VIEWRADIUS;
    lastRotate = coord;
    glutPostRedisplay();
}
void mouseMove(int x, int y)
{
    obverseChange(viewRotateX, x, lastRotateX, VIEWFACTORX);
    obverseChange(viewRotateY, y, lastRotateY, VIEWFACTORY);
}

void mouseClick(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) lastRotateX = x, lastRotateY = y;
}
