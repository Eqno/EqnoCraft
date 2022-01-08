#include "view.h"
#include "timer.h"
#include "listener.h"

void mouseMove(int x, int y)
{
    obverseChange(viewRotateX, x, lastRotateX, VIEWROTATEFACTORX);
    obverseChange(viewRotateY, y, lastRotateY, VIEWROTATEFACTORY);
}

void mouseClick(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) lastRotateX = x, lastRotateY = y;
}

void keyboardDown(unsigned char cmd, int x, int y)
{
    switch (cmd) 
    {
        case 'w': viewMovingForward = true; break;
        case 'a': viewMovingLeftward = true; break;
        case 's': viewMovingBackward = true; break;
        case 'd': viewMovingRightward = true; break;
        case ' ':
            ifJump = true;
            dropVelocity = INITJUMPVELOCITY;
            break;
        default: break;
    }
}

void keyboardUp(unsigned char cmd, int x, int y)
{
    switch (cmd) 
    {
        case 'w': viewMovingForward = false; break;
        case 'a': viewMovingLeftward = false; break;
        case 's': viewMovingBackward = false; break;
        case 'd': viewMovingRightward = false; break;
        default: break;
    }
}