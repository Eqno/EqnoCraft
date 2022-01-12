#ifndef TIMER_H
#define TIMER_H

#include "config.h"

const int VIEWMOVETIMERID = 0;
const int VIEWMOVETIMERTM = 10;
const int VIEWDROPTIMERID = 1;
const int VIEWDROPTIMERTM = 10;

const double GRAVITYFACTOR = 1000;

void viewMoveTimer(int id);
void viewDropTimer(int id);

extern bool ifJump;
extern double dropVelocity;

#endif