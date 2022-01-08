#include "ground.h"

Stone::Stone(double x, double y, double z): Block(STONETEX, x, y, z) {}
Stone::Stone(double x, double y, double z, double r): Block(STONETEX, x, y, z, r) {}

Dirt::Dirt(double x, double y, double z): Block(DIRTTEX, x, y, z) {}
Dirt::Dirt(double x, double y, double z, double r): Block(DIRTTEX, x, y, z, r) {}

Grass::Grass(double x, double y, double z): Coord(x, y, z, INITBLOCKRAD)
{
    this->textop = GRASSTOPTEX;
    this->texside = GRASSSIDETEX;
    this->texbottom = GRASSBOTTOMTEX;
}
Grass::Grass(double x, double y, double z, double r): Coord(x, y, z, r)
{
    this->textop = GRASSTOPTEX;
    this->texside = GRASSSIDETEX;
    this->texbottom = GRASSBOTTOMTEX;
}
void Grass::show() const
{
    glBindTexture(GL_TEXTURE_2D, this->texbottom);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texside);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(1, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);

    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->textop);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glEnd();
}

void addStone(double x, double y, double z)
{ block.push_back((Coord *) new Stone(x, y, z)); }

void addStone(double x, double y, double z, double r)
{ block.push_back((Coord *) new Stone(x, y, z, r)); }

void addDirt(double x, double y, double z)
{ block.push_back((Coord *) new Dirt(x, y, z)); }

void addDirt(double x, double y, double z, double r)
{ block.push_back((Coord *) new Dirt(x, y, z, r)); }

void addGrass(double x, double y, double z)
{ block.push_back((Coord *) new Grass(x, y, z)); }
void addGrass(double x, double y, double z, double r)
{ block.push_back((Coord *) new Grass(x, y, z, r)); }