#include "view.h"
#include "timer.h"
#include "block.h"
#include "init.h"
#include "listener.h"

void viewMoveTimer(int id)
{
    if (view->movingForward || view->movingBackward || view->movingLeftward || view->movingRightward)
    {
        double delCos = View::MOVE_FACTOR * cos(view->rotateX*pi/180);
        double delSin = View::MOVE_FACTOR * sin(view->rotateX*pi/180);
        if (view->movingForward)
        {
            view->z += delCos;
            view->x -= delSin;
        }
        else if (view->movingBackward)
        {
            view->z -= delCos;
            view->x += delSin;
        }
        if (view->movingLeftward)
        {
            view->x += delCos;
            view->z += delSin;
        }
        else if (view->movingRightward)
        {
            view->x -= delCos;
            view->z -= delSin;
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
        view->y -= dropVelocity;
        ifJump = false;
        goto nextLoop;
    }
    for (const auto &i: block)
    {
        if (view->x>=i->x-i->r && view->x<=i->x+i->r
            && view->z>=i->z-i->r && view->z<=i->z+i->r)
        {
            if (view->y >= i->y
                && view->y-dropVelocity <= i->y+Block::INIT_RAD+View::INIT_HEIGHT)
            {
                view->y = i->y + Block::INIT_RAD + View::INIT_HEIGHT;
                dropVelocity = 0;
                goto nextLoop;
            }
            else if (view->y <= i->y
                && view->y-dropVelocity >= i->y-5*Block::INIT_RAD+View::INIT_HEIGHT)
            {
                view->y = i->y - 5*Block::INIT_RAD + View::INIT_HEIGHT;
                dropVelocity = -dropVelocity;
                goto nextLoop;
            }
        }
    }
    view->y -= dropVelocity;
    dropVelocity += G/GRAVITYFACTOR;
nextLoop:
    glutPostRedisplay();
    glutTimerFunc(VIEWDROPTIMERID, viewDropTimer, id);
}