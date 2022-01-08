#include "block.h"

std::vector<Coord *> block;

Block::Block(GLint tex, double x, double y, double z): Coord(x, y, z, INITBLOCKRAD)
{ this->texture = tex; }
Block::Block(GLint tex, double x, double y, double z, double r): Coord(x, y, z, r)
{ this->texture = tex; }
void Block::show() const
{
    glBindTexture(GL_TEXTURE_2D, this->texture);
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

void renderBlock()
{ for (const auto &i: block) i->show(); }