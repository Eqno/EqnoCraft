#ifndef TIMER_H
#define TIMER_H

#include <config.h>

const int VIEW_MOVE_TIMER_ID = 0;
const int VIEW_MOVE_TIMER_TM = 10;
const int VIEW_DROP_TIMER_ID = 1;
const int VIEW_DROP_TIMER_TM = 10;

const double GRAVITYFACTOR = 1000;

void viewMoveTimer(int id);
void viewDropTimer(int id);

extern bool ifJump;
extern double dropVelocity;

#endif