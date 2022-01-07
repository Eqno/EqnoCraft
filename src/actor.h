#ifndef ACTOR_H
#define ACTOR_H

#include "base.h"
#include "coord.h"

class BodyBlock
{
public:
    double h, w, l;
    GLint texfront, texback, texleft, texright, textop, texbottom;
    BodyBlock(double h, double w, double l);
    void show(double x, double y, double z) const;
};

class Actor: public Coord
{
    // x, y, z, r
    BodyBlock *head, *body, *leftArm, *rightArm, *leftLeg, *rightLeg;
public:
    Actor(double x, double y, double z);
    void show() const;
};

void renderActor();

#endif