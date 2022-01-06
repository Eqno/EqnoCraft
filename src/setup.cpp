#include "init.h"
#include "view.h"
#include "render.h"
using namespace std;

int main(int argc, char **argv)
{
    // init
    createWindow(argc, argv);
    loadTexture();
    initBedrock();
    initGround();
    // render
    // glClearColor(SKYCOLOR);
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // listener
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    // loop
    glutMainLoop();
    return 0;
}