#ifndef GROUND_H
#define GROUND_H

#include "base.h"
#include "block.h"

class Stone: public Block
{
public:
    Stone(double x, double y, double z);
    Stone(double x, double y, double z, double r);
};

class Dirt: public Block
{
public:
    Dirt(double x, double y, double z);
    Dirt(double x, double y, double z, double r);
};

class Grass: public Coord
{
public:
    GLint textop, texside, texbottom;
    Grass(double x, double y, double z);
    Grass(double x, double y, double z, double r);
    void show() const;
};

void addStone(double x, double y, double z);
void addStone(double x, double y, double z, double r);

void addDirt(double x, double y, double z);
void addDirt(double x, double y, double z, double r);

void addGrass(double x, double y, double z);
void addGrass(double x, double y, double z, double r);

class GroundLayer
{
public:
    GroundLayer();
};

#endif