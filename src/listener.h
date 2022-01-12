#ifndef LISTENER_H
#define LISTENER_H

#include "config.h"

void mouseMove(int x, int y);
void mouseClickMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
void keyboardDown(unsigned char cmd, int x, int y);
void keyboardUp(unsigned char cmd, int x, int y);

const double INIT_JUMP_VELOCITY = -0.12;

extern bool mouseLocked;

#endif
