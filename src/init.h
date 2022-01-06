#ifndef INIT_H
#define INIT_H

#include "base.h"

const int  // constants of the window
    WINWIDTH = 1600, WINHEIGHT = 900,  // size
    WINPOSX = 0, WINPOSY = 0;  // position
const std::string WINTITLE = "EqnoCraft";  // title

const double  // constants of the contants
    BEDROCKDEPTH = -6, WORLDWIDTH = 10, WORLDLENGTH = 10;  // width_x, length_z

void createWindow(int argc, char **argv);
void loadTexture();
void initBedrock();
void initGround();

#endif