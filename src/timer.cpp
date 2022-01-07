#include "view.h"
#include "timer.h"

void viewMoveTimer(int id)
{
    if (viewMovingForward || viewMovingBackward || viewMovingLeftward || viewMovingRightward)
    {
        std::cout << viewRotateX << std::endl;
        double delCos = VIEWMOVEFACTOR * cos(viewRotateX*pi/180);
        double delSin = VIEWMOVEFACTOR * sin(viewRotateX*pi/180);
        if (viewMovingForward)
        {
            viewPosZ += delCos;
            viewPosX -= delSin;
        }
        else if (viewMovingBackward)
        {
            viewPosZ -= delCos;
            viewPosX += delSin;
        }
        if (viewMovingLeftward)
        {
            viewPosX += delCos;
            viewPosZ += delSin;
        }
        else if (viewMovingRightward)
        {
            viewPosX -= delCos;
            viewPosZ -= delSin;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(VIEWMOVETIMERTM, viewMoveTimer, id);
}