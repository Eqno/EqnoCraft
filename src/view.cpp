#include "view.h"

double viewHeight = VIEWHEIGHT, viewPosX = 0, viewPosZ = 0,
    viewRadius = VIEWRADIUS, viewRotateX = 0, viewRotateY = 0;
double lastRotateX = viewRotateX, lastRotateY = viewRotateY;
bool viewMovingForward = false, viewMovingBackward = false,
    viewMovingLeftward = false, viewMovingRightward = false;

void updateViewPos()
{
    glTranslated(viewPosX/F, 0, 0);  // view pos x
    glTranslated(0, 0, viewPosZ/F);  // view pos z
    glTranslated(0, -viewHeight/F, 0);  // actor height
}

void updateViewAng()
{   
    glLoadIdentity();
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