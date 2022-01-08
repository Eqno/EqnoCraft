#ifndef LISTENER_H
#define LISTENER_H

#include "base.h"

void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
void keyboardDown(unsigned char cmd, int x, int y);
void keyboardUp(unsigned char cmd, int x, int y);

const double INITJUMPVELOCITY = -0.2;

#endif
