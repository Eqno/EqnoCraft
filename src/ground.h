#ifndef GROUND_H
#define GROUND_H

#include "base.h"
#include "block.h"

class Stone: public Block
{
public:
    Stone();
    Stone(double x, double y, double z);
    Stone(double x, double y, double z, double r);
};

class Grass: public Block
{
public:
    Grass();
    Grass(double x, double y, double z);
    Grass(double x, double y, double z, double r);
};

void addStone();
void addStone(double x, double y, double z);
void addStone(double x, double y, double z, double r);

void addGrass();
void addGrass(double x, double y, double z);
void addGrass(double x, double y, double z, double r);

void renderGround();

#endif