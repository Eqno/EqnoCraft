#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

#include <coord.h>

class BoxBorder: public Point
{
public:
    BoxBorder(double x, double z);
};

class CollisionBox: public Coord
{
private:
    static constexpr double INIT_WEIGHT = 3;
public:
    double height, weight, *color, rotate;
    BoxBorder *frontLeft, *frontRight, *backLeft, *backRight;
    std::vector<Point *> borders;
    CollisionBox();
    CollisionBox(double r, double h, double w, double *color);
    void updatePos();
    void updateAng();
    void show() const;
};
void renderCollisionBox();

#endif