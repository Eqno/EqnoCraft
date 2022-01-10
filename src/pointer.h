#ifndef POINTER_H
#define POINTER_H

#include "coord.h"

enum PointerStyle
{ CROSS = 0 };

class Pointer: public Coord
{
private:
    static constexpr double INIT_RAD = 0.1, INIT_DIS = 10, INIT_WEIGHT = 2;
public:
    double w, *color;
    int style;  // 0->CROSS
    Pointer();
    Pointer(double r, double w);
    Pointer(double *color, int style);
    Pointer(double r, double w, double *color, int style);
    Pointer(double x, double y, double z, double r, double w, double *color, int style);
    void show() const;
};
void renderPointer();

#endif