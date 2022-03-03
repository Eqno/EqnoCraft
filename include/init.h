#ifndef INIT_H
#define INIT_H

#include "view.h"
#include "window.h"
#include "texture.h"
#include "collision.h"

extern Window *eqnoCraft;
extern View *view;
extern Coord *pointer;
extern Texture *texture;
extern CollisionBox *collBox;

void createWindow(int argc, char **argv);
void loadTexture();
void initView();
void initBedrock();
void initGround();
void initPointer();
void initCollisionBox();

#endif