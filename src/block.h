#ifndef BLOCK_H
#define BLOCK_H

#include "base.h"

const double INITBLOCKRAD = 0.5;

class Block
{
public:
    GLint texture;
    double x, y, z, r;
    Block(GLint tex);
    Block(GLint tex, double x, double y, double z);
    Block(GLint tex, double x, double y, double z, double r);
    void show() const;
};

#endif