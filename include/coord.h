#ifndef COORD_H
#define COORD_H

class Point
{
public:
    double x, y, z;
    Point(double, double, double);
};

class Coord: public Point
{
public:
    double r;
    Coord(double, double, double);
    Coord(double, double, double, double);
    virtual void show() const = 0;
};

#endif