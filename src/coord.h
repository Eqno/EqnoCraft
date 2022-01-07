#ifndef COORD_H
#define COORD_H

#include "base.h"

class Coord
{
public:
    double x, y, z, r;
    Coord(double x, double y, double z);
    Coord(double x, double y, double z, double r);
    virtual void show() const = 0;
};

#endif