#ifndef VIEW_H
#define VIEW_H

#include "base.h"

// extern double viewRadius, viewRotateX, viewRotateY;
const double VIEWRADIUS = 0.5, VIEWFACTORX = 0.25, VIEWFACTORY = 0.125;

void updateViewAng();
void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);

#endif