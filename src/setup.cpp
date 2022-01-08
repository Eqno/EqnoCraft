#include "init.h"
#include "timer.h"
#include "render.h"
#include "listener.h"
using namespace std;

int main(int argc, char **argv)
{
    // init
    createWindow(argc, argv);
    loadTexture();
    initBedrock();
    initGround();
    initActor();
    // render
    glClearColor(SKYCOLOR);
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // listener
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    // loop
    glutTimerFunc(VIEWMOVETIMERTM, viewMoveTimer, VIEWMOVETIMERID);
    glutTimerFunc(VIEWDROPTIMERTM, viewDropTimer, VIEWDROPTIMERID);
    glutMainLoop();
    return 0;
}