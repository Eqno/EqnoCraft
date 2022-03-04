#include <init.h>
#include <world.h>
#include <ground.h>
#include <bedrock.h>

Stone::Stone(double x, double y, double z): Block(texture->stone, x, y, z) {}
Stone::Stone(double x, double y, double z, double r): Block(texture->stone, x, y, z, r) {}

Dirt::Dirt(double x, double y, double z): Block(texture->dirt, x, y, z) {}
Dirt::Dirt(double x, double y, double z, double r): Block(texture->dirt, x, y, z, r) {}

Grass::Grass(double x, double y, double z): Coord(x, y, z, Block::INIT_RAD)
{
    this->textop = texture->grass_top;
    this->texside = texture->grass_side;
    this->texbottom = texture->grass_bottom;
}
Grass::Grass(double x, double y, double z, double r): Coord(x, y, z, r)
{
    this->textop = texture->grass_top;
    this->texside = texture->grass_side;
    this->texbottom = texture->grass_bottom;
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
{ addBlock<Stone>(x, y, z); }

void addStone(double x, double y, double z, double r)
{ addBlock<Stone>(x, y, z, r); }

void addDirt(double x, double y, double z)
{ addBlock<Dirt>(x, y, z); }

void addDirt(double x, double y, double z, double r)
{ addBlock<Dirt>(x, y, z, r); }

void addGrass(double x, double y, double z)
{ addBlock<Grass>(x, y, z); }
void addGrass(double x, double y, double z, double r)
{ addBlock<Grass>(x, y, z, r); }

GroundLayer::GroundLayer()
{
    for (int k=BedrockLayer::INIT_DEPTH+1; k<=-5; k++)
        for (int i=-World::INIT_WIDTH; i<=World::INIT_WIDTH; i++)
            for (int j=-World::INIT_LENGTH; j<=World::INIT_LENGTH; j++)
                addStone(i, k, j);
    for (int k=-4; k<=-2; k++)
        for (int i=-World::INIT_WIDTH; i<=World::INIT_WIDTH; i++)
            for (int j=-World::INIT_LENGTH; j<=World::INIT_LENGTH; j++)
                addDirt(i, k, j);
    for (int i=-World::INIT_WIDTH; i<=World::INIT_WIDTH; i++)
        for (int j=-World::INIT_LENGTH; j<=World::INIT_LENGTH; j++)
            addGrass(i, -1, j);
}