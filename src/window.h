#ifndef WINDOW_H
#define WINDOW_H

#include "base.h"

class Window
{
public:
    static const int
        INIT_WIDTH = 1600, INIT_HEIGHT = 900,
        INIT_POS_X = 0, INIT_POS_Y = 0;
    std::string title;
    int width, height, posx, posy, midx, midy;
    Window(const std::string &);
    Window(int, int, const std::string &);
    Window(int, int, int, int, const std::string &);
    void updateSize(int, int);
    void show(int argc, char **argv);
};

#endif