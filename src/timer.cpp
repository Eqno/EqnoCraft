#include "view.h"
#include "timer.h"
#include "block.h"

void viewMoveTimer(int id)
{
    if (viewMovingForward || viewMovingBackward || viewMovingLeftward || viewMovingRightward)
    {
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

bool ifJump = false;
double dropVelocity = 0;
void viewDropTimer(int id)
{
    if (ifJump)
    {
        viewHeight -= dropVelocity;
        ifJump = false;
        goto nextLoop;
    }
    for (const auto &i: block)
    {
        if (viewPosX>=i->x-i->r && viewPosX<=i->x+i->r
            && viewPosZ>=i->z-i->r && viewPosZ<=i->z+i->r)
        {
            if (viewHeight >= i->y
                && viewHeight-dropVelocity <= i->y+INITBLOCKRAD+VIEWHEIGHT)
            {
                viewHeight = i->y + INITBLOCKRAD + VIEWHEIGHT;
                dropVelocity = 0;
                goto nextLoop;
            }
            else if (viewHeight <= i->y
                && viewHeight-dropVelocity >= i->y-5*INITBLOCKRAD+VIEWHEIGHT)
            {
                viewHeight = i->y - 5*INITBLOCKRAD + VIEWHEIGHT;
                dropVelocity = -dropVelocity;
                goto nextLoop;
            }
        }
    }
    viewHeight -= dropVelocity;
    dropVelocity += G/GRAVITYFACTOR;
nextLoop:
    glutPostRedisplay();
    glutTimerFunc(VIEWDROPTIMERID, viewDropTimer, id);
}