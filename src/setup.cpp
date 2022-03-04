#include <gl/freeglut_std.h>
#include <init.h>
#include <timer.h>
#include <render.h>
#include <listener.h>
using namespace std;

int main(int argc, char **argv)
{
    // init
    createWindow(argc, argv);
    loadTexture();
    initView();
    initBedrock();
    initGround();
    initPointer();
    initCollisionBox();
    // render
    glClearColor(SKYCOLOR);
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // listener
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseClickMove);
    glutPassiveMotionFunc(mouseMove);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    // loop
    glutTimerFunc(VIEW_MOVE_TIMER_TM, viewMoveTimer, VIEW_MOVE_TIMER_ID);
    glutTimerFunc(VIEW_DROP_TIMER_TM, viewDropTimer, VIEW_DROP_TIMER_ID);
    glutMainLoop();
    return 0;
}