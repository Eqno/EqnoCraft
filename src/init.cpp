#include <init.h>
#include <ground.h>
#include <window.h>
#include <pointer.h>
#include <bedrock.h>

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
    // for (int k=0; k<5; k++)
    //     for (int i=-5; i<=5; i++)
    //         for (int j=-2; j>=-10; j--)
    //             addStone(i, k, j);
    addStone(0, 0, 3);
    addStone(1, 0, 3);
    addStone(1, 1, 3);
    addStone(2, 0, 3);
    addStone(2, 1, 3);
    addStone(2, 2, 3);
    addStone(3, 0, 3);
    addStone(3, 1, 3);
    addStone(3, 2, 3);
    addStone(3, 0, 2);
    addStone(3, 1, 2);
    addStone(3, 2, 2);
    addStone(3, 0, 1);
    addStone(3, 1, 1);
    addStone(3, 2, 1);
}

void initCollisionBox()
{ collBox = new CollisionBox(); }