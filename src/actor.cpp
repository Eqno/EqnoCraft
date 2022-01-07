#include "actor.h"

void BodyBlock::show(double x, double y, double z) const
{
    glBindTexture(GL_TEXTURE_2D, this->texbottom);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((x-h)/F, (y-r)/F, (z-r)/F);
    glTexCoord2d(0, 1); glVertex3d((x-r)/F, (y-r)/F, (z+r)/F);
    glTexCoord2d(1, 1); glVertex3d((x+r)/F, (y-r)/F, (z+r)/F);
    glTexCoord2d(1, 0); glVertex3d((x+r)/F, (y-r)/F, (z-r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texleft);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((x-r)/F, (y-r)/F, (z-r)/F);
    glTexCoord2d(0, 1); glVertex3d((x-r)/F, (y+r)/F, (z-r)/F);
    glTexCoord2d(1, 1); glVertex3d((x+r)/F, (y+r)/F, (z-r)/F);
    glTexCoord2d(1, 0); glVertex3d((x+r)/F, (y-r)/F, (z-r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texfront);
    glBegin(GL_QUADS);
    glTexCoord2d(1, 0); glVertex3d((x-r)/F, (y-r)/F, (z-r)/F);
    glTexCoord2d(0, 0); glVertex3d((x-r)/F, (y-r)/F, (z+r)/F);
    glTexCoord2d(0, 1); glVertex3d((x-r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 1); glVertex3d((x-r)/F, (y+r)/F, (z-r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texright);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((x-r)/F, (y-r)/F, (z+r)/F);
    glTexCoord2d(0, 1); glVertex3d((x-r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 1); glVertex3d((x+r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 0); glVertex3d((x+r)/F, (y-r)/F, (z+r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texback);
    glBegin(GL_QUADS);
    glTexCoord2d(1, 0); glVertex3d((x+r)/F, (y-r)/F, (z-r)/F);
    glTexCoord2d(0, 0); glVertex3d((x+r)/F, (y-r)/F, (z+r)/F);
    glTexCoord2d(0, 1); glVertex3d((x+r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 1); glVertex3d((x+r)/F, (y+r)/F, (z-r)/F);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->textop);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d((x-r)/F, (y+r)/F, (z-r)/F);
    glTexCoord2d(0, 1); glVertex3d((x-r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 1); glVertex3d((x+r)/F, (y+r)/F, (z+r)/F);
    glTexCoord2d(1, 0); glVertex3d((x+r)/F, (y+r)/F, (z-r)/F);
    glEnd();
}
void setHeadTexture(BodyBlock *head)
{
    head->texfront = STONETEX;
    head->texback = STONETEX;
    head->texleft = STONETEX;
    head->texright = STONETEX;
    head->textop = STONETEX;
    head->texbottom = STONETEX;
}
void setBodyTexture(BodyBlock *block)
{
    block->texfront = DIRTTEX;
    block->texback = DIRTTEX;
    block->texleft = DIRTTEX;
    block->texright = DIRTTEX;
    block->textop = DIRTTEX;
    block->texbottom = DIRTTEX;
}

Actor::Actor(double x, double y, double z): Coord(x, y, z)
{
    head = new BodyBlock(0.25, 0.25, 0.25);
    body = new BodyBlock(1, 0.5, 0.2);
    leftArm = new BodyBlock(0.8, 0.125, 0.125);
    rightArm = new BodyBlock(0.8, 0.125, 0.125);
    leftLeg = new BodyBlock(0.8, 0.125, 0.125);
    rightLeg = new BodyBlock(0.8, 0.125, 0.125);
    setHeadTexture(head);
    setBodyTexture(body);
    setBodyTexture(leftArm);
    setBodyTexture(rightArm);
    setBodyTexture(leftLeg);
    setBodyTexture(rightLeg);
}

void Actor::show() const
{
    head->show(x, y, z);
    body->show(x, y, z);
    leftArm->show(x, y, z);
    rightArm->show(x, y, z);
    leftLeg->show(x, y, z);
    rightLeg->show(x, y, z);
}

Actor *actor;

void addActor() { actor = new Actor(0, 0, 0); }

void renderActor() { actor->show(); }