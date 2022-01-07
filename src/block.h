#ifndef BLOCK_H
#define BLOCK_H

#include "base.h"
#include "coord.h"

const double INITBLOCKRAD = 0.5;

class Block: public Coord
{
public:
    GLint texture;
    Block(GLint tex, double x, double y, double z);
    Block(GLint tex, double x, double y, double z, double r);
    void show() const;
};

#endif