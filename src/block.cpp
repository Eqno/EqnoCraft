#include "block.h"

Block::Block(GLint tex)
{
    this->texture = tex;
    this->x = 0, this->y = 0, this->z = 0, this->r = INITBLOCKRAD;
}
Block::Block(GLint tex, double x, double y, double z)
{
    this->texture = tex;
    this->x = x, this->y = y, this->z = z, this->r = INITBLOCKRAD;
}
Block::Block(GLint tex, double x, double y, double z, double r)
{
    this->texture = tex;
    this->x = x, this->y = y, this->z = z, this->r = r;
}
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