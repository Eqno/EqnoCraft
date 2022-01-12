#include <GL/freeglut_std.h>
// It has to be defined before any other .h in GL.
#include <GL/gl.h>
#include <iostream>
#include <unordered_map>

#include "init.h"
#include "block.h"
#include "utils.h"

std::unordered_map<unsigned long long, std::unordered_map<int, Coord *>> inside, surface;

Block::Block(GLint tex, double x, double y, double z): Coord(x, y, z, Block::INIT_RAD)
{ this->blockTex = tex; }
Block::Block(GLint tex, double x, double y, double z, double r): Coord(x, y, z, r)
{ this->blockTex = tex; }
void Block::show() const
{
    glBindTexture(GL_TEXTURE_2D, this->blockTex);
    glBegin(GL_QUADS);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x+this->r)/F, (this->y-this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);

    glTexCoord2d(0, 0); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    glTexCoord2d(0, 1); glVertex3d((this->x-this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 1); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z+this->r)/F);
    glTexCoord2d(1, 0); glVertex3d((this->x+this->r)/F, (this->y+this->r)/F, (this->z-this->r)/F);
    
    glEnd();
}

// FIXME: inside and surface contain the same blocks
bool checkCoord(int x, int y, int z)
{
    ull hash = getHash(x, z);
    const auto &in = inside[hash], &su = surface[hash];
    if (in.find(y) != in.end()) return false;
    if (su.find(y) != su.end()) return false;
    return true;
}
bool checkExposed(double x, double y, double z)
{
    int ix = x+0.5, iy = y+0.5, iz = z+0.5;
    return checkCoord(ix-1, iy, iz) | checkCoord(ix, iy-1, iz)
        | checkCoord(ix, iy, iz-1) | checkCoord(ix+1, iy, iz)
        | checkCoord(ix, iy+1, iz) | checkCoord(ix, iy, iz+1);
}
void updateExposed(int x, int y, int z)
{
    // total
    // surface
    Coord *block = nullptr;
    ull hash = getHash(x, z);
    auto &in = inside[hash], &su = surface[hash];
    if (in.find(y) != in.end())
    {
        block = in.find(y)->second;
        // in.erase(in.find(y));
    }
    else if (su.find(y) != su.end())
    {
        block = su.find(y)->second;
        // su.erase(su.find(y));
    }
    if (block != nullptr)
    {
        if (checkExposed(x, y, z)) su[y] = block;
        else in[y] = block;
    }
}
void updateAround(double x, double y, double z)
{
    // int ix = x+0.5, iy = y+0.5, iz = z+0.5;
    // updateExposed(ix-1, iy, iz);
    // updateExposed(ix, iy-1, iz);
    // updateExposed(ix, iy, iz-1);
    // updateExposed(ix+1, iy, iz);
    // updateExposed(ix, iy+1, iz);
    // updateExposed(ix, iy, iz+1);
}

void renderBlock()
{
    int cot = 0;
    int startX = view->x-view->distance, endX = view->x+view->distance;
    int startZ = view->z-view->distance, endZ = view->z+view->distance;
    for (int i=startX; i<=endX; i++)
        for (int j=startZ; j<=endZ; j++)
            for (const auto &k: surface[getHash(i, j)])
                k.second->show(), cot ++;
    std::cout << cot << std::endl;
}