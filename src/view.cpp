#include "view.h"
#include "listener.h"
#include "init.h"

View::View(): Coord(0, View::INIT_HEIGHT, 0, View::INIT_RADIUS)
{
    this->rotateX = 0, this->rotateY = 0;
    this->lastRotateX = rotateX, this->lastRotateY = rotateY;
    this->movingForward = this->movingBackward
        = this->movingLeftward = this->movingRightward = false;
}

void lockMousePos()
{
    if (! mouseLocked) return;
    glutWarpPointer(view->lastRotateX = eqnoCraft->midx,
        view->lastRotateY = eqnoCraft->midy);
}

void View::updatePos()
{
    glTranslated(this->x/F, 0, 0);  // view pos x
    glTranslated(0, 0, this->z/F);  // view pos z
    glTranslated(0, -this->y/F, 0);  // actor height
}

void View::updateAng()
{   
    glLoadIdentity();
    if (this->rotateX > 180) this->rotateX = -180;
    if (this->rotateX < -180) this->rotateX = 180;
    if (this->rotateY > 180) this->rotateY = -180;
    if (this->rotateY < -180) this->rotateY = 180;
    glRotated(this->rotateY, 1, 0, 0);
    glRotated(this->rotateX, 0, 1, 0);
}

void View::updateRotate(double &viewRotate, double coord, double &lastRotate, double viewMoveFac)
{
    viewRotate += viewMoveFac * (coord-lastRotate) / View::INIT_RADIUS;
    lastRotate = coord;
    glutPostRedisplay();
    lockMousePos();
}

void View::show() const
{

}