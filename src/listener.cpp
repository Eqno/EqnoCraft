#include "init.h"
#include "view.h"
#include "timer.h"
#include "window.h"
#include "listener.h"

bool mouseLocked = false;

void mouseMove(int x, int y)
{ if (mouseLocked) mouseClickMove(x, y); }

void mouseClickMove(int x, int y)
{
    view->updateRotate(view->rotateX, x, view->lastRotateX, View::ROTATE_FACTOR_X);
    view->updateRotate(view->rotateY, y, view->lastRotateY, View::ROTATE_FACTOR_Y);
}

void mouseClick(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) if (! mouseLocked) view->lastRotateX = x, view->lastRotateY = y;
}

void keyboardDown(unsigned char cmd, int x, int y)
{
    switch (cmd) 
    {
        case 'w': view->movingForward = true; break;
        case 'a': view->movingLeftward = true; break;
        case 's': view->movingBackward = true; break;
        case 'd': view->movingRightward = true; break;
        case ' ':
            ifJump = true;
            dropVelocity = INIT_JUMP_VELOCITY;
            break;
        case '`':
            mouseLocked = !mouseLocked;
            if (mouseLocked)
            {
                while (ShowCursor(FALSE) >= 0)
                    ShowCursor(FALSE);
            }
            else
            {
                while (ShowCursor(TRUE) < 0)
                    ShowCursor(TRUE);
            }
            lockMousePos();
            break;
        default: break;
    }
}

void keyboardUp(unsigned char cmd, int x, int y)
{
    switch (cmd) 
    {
        case 'w': view->movingForward = false; break;
        case 'a': view->movingLeftward = false; break;
        case 's': view->movingBackward = false; break;
        case 'd': view->movingRightward = false; break;
        default: break;
    }
}