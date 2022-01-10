#include "window.h"

Window::Window(const std::string &title)
{
    this->width = INIT_WIDTH;
    this->height = INIT_HEIGHT;
    this->posx = INIT_POS_X;
    this->posy = INIT_POS_Y;
    this->midx = (double) this->width/2;
    this->midy = (double) this->height/2;
    this->title = title;
}

Window::Window(int width, int height, const std::string &title)
{
    this->width = width;
    this->height = height;
    this->posx = INIT_POS_X;
    this->posy = INIT_POS_Y;
    this->midx = (double) width/2;
    this->midy = (double) height/2;
    this->title = title;
}

Window::Window(int width, int height, int posx, int posy, const std::string &title)
{
    this->width = width;
    this->height = height;
    this->posx = posx;
    this->posy = posy;
    this->midx = (double) width/2;
    this->midy = (double) height/2;
    this->title = title;
}

void Window::updateSize(int width, int height)
{
    this->width = width;
    this->height = height;
    this->midx = (double) width/2;
    this->midy = (double) height/2;
}

void Window::show(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(this->width, this->height); 
    glutInitWindowPosition(this->posx, this->posy);
    glutCreateWindow(this->title.c_str());
}