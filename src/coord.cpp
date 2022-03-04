#include <coord.h>

Point::Point(double x, double y, double z)
{ this->x = x, this->y = y, this->z = z; }

Coord::Coord(double x, double y, double z): Point(x, y, z) { this->r = 0; }
Coord::Coord(double x, double y, double z, double r): Point(x, y, z) { this->r = r; }