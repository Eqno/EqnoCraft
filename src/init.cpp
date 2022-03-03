#include "../include/init.h"
#include "../include/ground.h"
#include "../include/window.h"
#include "../include/pointer.h"
#include "../include/bedrock.h"

#include <iostream>

Window *eqnoCraft;
View *view;
Coord *pointer;
Texture *texture;
CollisionBox *collBox;

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
{
    new GroundLayer();
    for (int k=0; k<5; k++)
        for (int i=-5; i<=5; i++)
            for (int j=-2; j>=-10; j--)
                addStone(i, k, j);
}

void initCollisionBox()
{ collBox = new CollisionBox(); }