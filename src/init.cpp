#include "init.h"
#include "view.h"
#include "window.h"
#include "ground.h"
#include "pointer.h"
#include "bedrock.h"

Window *eqnoCraft;
View *view;
Coord *pointer;
Texture *texture;

void createWindow(int argc, char **argv)
{
    eqnoCraft = new Window("EqnoCraft");
    eqnoCraft->show(argc, argv);
}

void initView()
{ view = new View(); }

void initPointer()
{ pointer = new Pointer(); }

void loadTexture()
{ texture = new Texture(); }

void initBedrock()
{ new BedrockLayer(); }

void initGround()
{ new GroundLayer(); }