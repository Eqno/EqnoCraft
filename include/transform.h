#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <vector>
#include "utils.h"
#include "config.h"
#include "coord.h"

void translateX(std::vector <Point *> &v, double l);
void translateY(std::vector <Point *> &v, double m);
void translateZ(std::vector <Point *> &v, double n);
void translate(std::vector <Point *> &v, double l, double m, double n);

void rotateDY(std::vector <Point *> &v, double angle);

#endif