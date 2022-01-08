#ifndef VIEW_H
#define VIEW_H

#include "base.h"

extern double viewHeight, viewPosX, viewPosZ,
    viewRadius, viewRotateX, viewRotateY, lastRotateX, lastRotateY;
extern bool viewMovingForward, viewMovingBackward,
    viewMovingLeftward, viewMovingRightward;

const double VIEWHEIGHT = 1.5, VIEWMOVEFACTOR = 0.1,
    VIEWRADIUS = 5, VIEWROTATEFACTORX = 2.5, VIEWROTATEFACTORY = 1.4;

void updateViewPos();
void updateViewAng();
void obverseChange(double &viewRotate, double coord, double &lastRotate, double viewMoveFac);

#endif