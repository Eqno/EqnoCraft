#include "../include/view.h"
#include "../include/timer.h"
#include "../include/block.h"
#include "../include/init.h"
#include "../include/utils.h"
#include "../include/listener.h"

double dis(double x1, double z1, double x2, double z2)
{ return sqrt((x1-x2)*(x1-x2)+(z1-z2)*(z1-z2)); }
double norm(double x, double z) { return sqrt(x*x+z*z); }
double projection(double x1, double z1, double x2, double z2)
{ return (x1*z1+x2*z2) / norm(x2, z2); }
void unitization(double &x, double &z)
{
    double nor = norm(x, z);
    x /= nor, z /= nor;
}

bool judgeMove(double x, double y, double z, double &nx, double &nz)
{
    double dx = nx - x, dz = nz - z;
    int startX = (int) (view->x)-2, endX = (int) (view->x)+2;
    int startZ = (int) (view->z)-2, endZ = (int) (view->z)+2;
    for (int coordX=startX; coordX<=endX; coordX++)
        for (int coordZ=startZ; coordZ<=endZ; coordZ++)
            for (const auto &block: block[getHash(coordX, coordZ)])
            {
                const auto &i = block.second;
                if (y < i->y+2*i->r && y > i->y-4*i->r)
                {
                    if (nx >= i->x-i->r-view->r && nx <= i->x+i->r+view->r)
                    {
                        if (nz > i->z-i->r-view->r && nz < i->z+i->r+view->r)
                        {
                            if (z <= i->z-i->r-view->r)
                            {
                                nz = i->z-i->r-view->r;
                                nx = x + projection(dx, dz, i->r, 0) * F;
                                return true;
                            }
                            else if (z >= i->z+i->r+view->r)
                            {
                                nz = i->z+i->r+view->r;
                                nx = x - projection(dx, dz, i->r, 0) * F;
                                return true;
                            }
                        }
                    }
                    if (nz >= i->z-i->r-view->r && nz <= i->z+i->r+view->r)
                    {
                        if (nx > i->x-i->r-view->r && nx < i->x+i->r+view->r)
                        {
                            if (x <= i->x-i->r-view->r)
                            {
                                nx = i->x-i->r-view->r;
                                nz = z + projection(dx, dz, 0, i->r) * F;
                                return true;
                            }
                            else if (x >= i->x+i->r+view->r)
                            {
                                nx = i->x+i->r+view->r;
                                nz = z - projection(dx, dz, 0, i->r) * F;
                                return true;
                            }
                        }
                    }
                }
            }
    return true;
}

void viewMoveTimer(int id)
{
    if (view->movingForward || view->movingBackward || view->movingLeftward || view->movingRightward)
    {
        double delCos = View::MOVE_FACTOR * cos(view->rotateX*pi/180);
        double delSin = View::MOVE_FACTOR * sin(view->rotateX*pi/180);
        double nxtX = view->x, nxtZ = view->z;
        if (view->movingForward)
        {
            nxtZ -= delCos;
            nxtX += delSin;
        }
        else if (view->movingBackward)
        {
            nxtZ += delCos;
            nxtX -= delSin;
        }
        if (view->movingLeftward)
        {
            nxtX -= delCos;
            nxtZ -= delSin;
        }
        else if (view->movingRightward)
        {
            nxtX += delCos;
            nxtZ += delSin;
        }
        if (judgeMove(view->x, view->y, view->z, nxtX, nxtZ))
        {
            view->x = nxtX;
            view->z = nxtZ;
            glutPostRedisplay();
        }
    }
    glutTimerFunc(VIEWMOVETIMERTM, viewMoveTimer, id);
}

bool ifJump = false;
double dropVelocity = 0;
#define updateVelocity() \
do { \
    if (view->y > i->y \
        && view->y-dropVelocity <= i->y+2*i->r) \
    { \
        view->y = i->y + 2*i->r; \
        dropVelocity = 0; \
        goto nextLoop; \
    } \
    else if (view->y < i->y \
        && view->y-dropVelocity >= i->y-4*i->r) \
    { \
        view->y = i->y - 4*i->r; \
        dropVelocity = -dropVelocity; \
        goto nextLoop; \
    } \
} while (0)
void viewDropTimer(int id)
{
    int startX = (int) (view->x)-2, endX = (int) (view->x)+2;
    int startZ = (int) (view->z)-2, endZ = (int) (view->z)+2;
    if (ifJump)
    {
        view->y -= dropVelocity;
        ifJump = false;
        goto nextLoop;
    }
    for (int coordX=startX; coordX<=endX; coordX++)
        for (int coordZ=startZ; coordZ<=endZ; coordZ++)
            for (const auto &block: block[getHash(coordX, coordZ)])
            {
                const auto &i = block.second;
                if (view->x > i->x-i->r-view->r && view->x < i->x+i->r+view->r)
                    if (view->z > i->z-i->r-view->r && view->z < i->z+i->r+view->r)
                        updateVelocity();
                if (view->z > i->z-i->r-view->r && view->z < i->z+i->r+view->r)
                    if (view->x > i->x-i->r-view->r && view->x < i->x+i->r+view->r)
                        updateVelocity();
            }
    view->y -= dropVelocity;
    dropVelocity += G/GRAVITYFACTOR;
nextLoop:
    glutPostRedisplay();
    glutTimerFunc(VIEWDROPTIMERID, viewDropTimer, id);
}