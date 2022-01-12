#include "init.h"
#include "ground.h"
#include "window.h"
#include "pointer.h"
#include "bedrock.h"

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

void initExposed()
{
    int tmp, tot;

    for (const auto &i: inside)
    {
        int x = 0, z = 0;
        anaHash(i.first, x, z);
        for (const auto &j: i.second)
            updateExposed(x, j.first, z);
    }

    tmp = 0; tot = surface.size();
    for (const auto &i: surface)
    {
        int x = 0, z = 0;
        anaHash(i.first, x, z);
        std::cout << ++tmp << '/' << tot << "..." << std::endl;
        for (const auto &j: i.second)
            updateExposed(x, j.first, z);
        std::cout << ++tmp << '/' << tot << "." << std::endl;
    }
    std::cout << inside.size() << " " << surface.size() << std::endl;
}

void initCollisionBox()
{ collBox = new CollisionBox(); }