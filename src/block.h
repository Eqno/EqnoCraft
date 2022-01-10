#ifndef BLOCK_H
#define BLOCK_H

#include "base.h"
#include "coord.h"
#include <vector>

class Block: public Coord
{
public:
    static constexpr double INIT_RAD = 0.5;
    GLint blockTex;
    Block(GLint tex, double x, double y, double z);
    Block(GLint tex, double x, double y, double z, double r);
    void show() const;
};

extern std::vector<Coord *> block;

void renderBlock();

#endif