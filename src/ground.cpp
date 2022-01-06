#include "ground.h"

Stone::Stone(): Block(BEDROCKTEX) {}
Stone::Stone(double x, double y, double z): Block(BEDROCKTEX, x, y, z) {}
Stone::Stone(double x, double y, double z, double r): Block(BEDROCKTEX, x, y, z, r) {}

Grass::Grass(): Block(BEDROCKTEX) {}
Grass::Grass(double x, double y, double z): Block(BEDROCKTEX, x, y, z) {}
Grass::Grass(double x, double y, double z, double r): Block(BEDROCKTEX, x, y, z, r) {}

std::vector<Block> stone, grass;

void addStone()
{
    stone.push_back(Stone());
}
void addStone(double x, double y, double z)
{
    stone.push_back(Stone(x, y, z));
}
void addStone(double x, double y, double z, double r)
{
    stone.push_back(Stone(x, y, z, r));
}

void addGrass()
{
    grass.push_back(Grass());
}
void addGrass(double x, double y, double z)
{
    grass.push_back(Grass(x, y, z));
}
void addGrass(double x, double y, double z, double r)
{
    grass.push_back(Grass(x, y, z, r));
}
void renderGround()
{
    for (const auto &i: stone) i.show();
    for (const auto &i: grass) i.show();
}