#ifndef INIT_H
#define INIT_H

#include "base.h"
#include "view.h"
#include "window.h"
#include "pointer.h"
#include "texture.h"

extern Window *eqnoCraft;
extern View *view;
extern Coord *pointer;
extern Texture *texture;

void createWindow(int argc, char **argv);
void loadTexture();
void initView();
void initBedrock();
void initGround();
void initPointer();

#endif