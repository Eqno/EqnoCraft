#include "../include/init.h"
#include "../include/config.h"
#include "../include/pointer.h"

Pointer::Pointer(): Coord(0, 0, Pointer::INIT_DIS, Pointer::INIT_RAD)
{
    this->w = INIT_WEIGHT;
    this->color = new double[3]{BLACK};
    this->style = PointerStyle::CROSS;
}

Pointer::Pointer(double r, double w): Coord(0, 0, Pointer::INIT_DIS, r)
{
    this->w = w;
    this->color = new double[3]{BLACK};
    this->style = PointerStyle::CROSS;
}

Pointer::Pointer(double *color, int style): Coord(0, 0, Pointer::INIT_DIS, Pointer::INIT_RAD)
{
    this->w = INIT_WEIGHT;
    this->color = color;
    this->style = style;
}

Pointer::Pointer(double r, double w, double *color, int style): Coord(0, 0, Pointer::INIT_DIS, r)
{
    this->w = w;
    this->color = color;
    this->style = style;
}

Pointer::Pointer(double x, double y, double z, double r, double w, double *color, int style): Coord(x, y, z, r)
{
    this->w = w;
    this->color = color;
    this->style = style;
}

void Pointer::show() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3dv(this->color);
    glLineWidth(this->w);
    if (this->style == PointerStyle::CROSS)
    {
        glBegin(GL_LINES);
        glVertex3d(this->x/F, (this->y-this->r)/F, -this->z/F);
        glVertex3d(this->x/F, (this->y+this->r)/F, -this->z/F);
        glVertex3d((this->x-this->r)/F, this->y/F, -this->z/F);
        glVertex3d((this->x+this->r)/F, this->y/F, -this->z/F);
        glEnd();
    }
    glLineWidth(1);
}

void renderPointer()
{
    pointer->show();
}