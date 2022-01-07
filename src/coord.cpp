#include "coord.h"

Coord::Coord(double x, double y, double z)
{ this->x = x, this->y = y, this->z = z, this->r = 0; }

Coord::Coord(double x, double y, double z, double r)
{ this->x = x, this->y = y, this->z = z, this->r = r; }