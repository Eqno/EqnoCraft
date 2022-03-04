#include <init.h>
#include <coord.h>
#include <pointer.h>
#include <transform.h>
#include <collision.h>

BoxBorder::BoxBorder(double x, double z): Point(x, 0, z) { }

void initBorder(CollisionBox *box)
{
    box->frontLeft = new BoxBorder(box->x-box->r, box->z-box->r);
    box->frontRight = new BoxBorder(box->x+box->r, box->z-box->r);
    box->backLeft = new BoxBorder(box->x-box->r, box->z+box->r);
    box->backRight = new BoxBorder(box->x+box->r, box->z+box->r);
}

CollisionBox::CollisionBox(): Coord(view->x, view->y, view->z, view->r)
{
    this->height = View::INIT_HEIGHT;
    this->weight = CollisionBox::INIT_WEIGHT;
    this->color = new double[3]{BLACK};
    this->rotate = view->rotateX;
    initBorder(this);
    this->borders = {frontLeft, frontRight, backLeft, backRight};
}

CollisionBox::CollisionBox(double r, double h, double w, double *color): Coord(view->x, view->y, view->z, r)
{
    this->height = h;
    this->weight = w;
    this->color = color;
    this->rotate = view->rotateX;
    initBorder(this);
    this->borders = {frontLeft, frontRight, backLeft, backRight};
}

void CollisionBox::updateAng()
{
    translateX(this->borders, -this->x);
    translateZ(this->borders, -this->z);
    rotateDY(this->borders, this->rotate-view->rotateX);
    this->rotate = view->rotateX;
    translateX(this->borders, this->x);
    translateZ(this->borders, this->z);
}

void CollisionBox::updatePos()
{
    translateX(this->borders, view->x-this->x);
    translateZ(this->borders, view->z-this->z);
    this->x = view->x;
    this->y = view->y;
    this->z = view->z;
}

void showInner(const CollisionBox *box)
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3d(RED);
    glLineWidth(box->weight);
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x-box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y-box->r*0.8)/F, (box->z+box->r*0.8)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glVertex3d((box->x-box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z+box->r*0.8)/F);
    glVertex3d((box->x+box->r*0.8)/F, (box->y+box->r*0.8+box->height)/F, (box->z-box->r*0.8)/F);
    glEnd();
    glLineWidth(1);
}

void showOuter(const CollisionBox *box)
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3dv(box->color);
    glLineWidth(box->weight);
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->frontLeft->x/F, (box->y-box->r)/F, (box->frontLeft->z)/F);
    glVertex3d(box->frontRight->x/F, (box->y-box->r)/F, (box->frontRight->z)/F);
    glVertex3d(box->backRight->x/F, (box->y-box->r)/F, (box->backRight->z)/F);
    glVertex3d(box->backLeft->x/F, (box->y-box->r)/F, (box->backLeft->z)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->frontLeft->x/F, (box->y-box->r)/F, (box->frontLeft->z)/F);
    glVertex3d(box->frontRight->x/F, (box->y-box->r)/F, (box->frontRight->z)/F);
    glVertex3d(box->frontRight->x/F, (box->y+box->r+box->height)/F, (box->frontRight->z)/F);
    glVertex3d(box->frontLeft->x/F, (box->y+box->r+box->height)/F, (box->frontLeft->z)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->frontRight->x/F, (box->y-box->r)/F, (box->frontRight->z)/F);
    glVertex3d(box->backRight->x/F, (box->y-box->r)/F, (box->backRight->z)/F);
    glVertex3d(box->backRight->x/F, (box->y+box->r+box->height)/F, (box->backRight->z)/F);
    glVertex3d(box->frontRight->x/F, (box->y+box->r+box->height)/F, (box->frontRight->z)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->backRight->x/F, (box->y-box->r)/F, (box->backRight->z)/F);
    glVertex3d(box->backLeft->x/F, (box->y-box->r)/F, (box->backLeft->z)/F);
    glVertex3d(box->backLeft->x/F, (box->y+box->r+box->height)/F, (box->backLeft->z)/F);
    glVertex3d(box->backRight->x/F, (box->y+box->r+box->height)/F, (box->backRight->z)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->backLeft->x/F, (box->y-box->r)/F, (box->backLeft->z)/F);
    glVertex3d(box->frontLeft->x/F, (box->y-box->r)/F, (box->frontLeft->z)/F);
    glVertex3d(box->frontLeft->x/F, (box->y+box->r+box->height)/F, (box->frontLeft->z)/F);
    glVertex3d(box->backLeft->x/F, (box->y+box->r+box->height)/F, (box->backLeft->z)/F);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(box->frontLeft->x/F, (box->y+box->r+box->height)/F, (box->frontLeft->z)/F);
    glVertex3d(box->frontRight->x/F, (box->y+box->r+box->height)/F, (box->frontRight->z)/F);
    glVertex3d(box->backRight->x/F, (box->y+box->r+box->height)/F, (box->backRight->z)/F);
    glVertex3d(box->backLeft->x/F, (box->y+box->r+box->height)/F, (box->backLeft->z)/F);
    glEnd();
    glLineWidth(1);
}

void CollisionBox::show() const
{
    showInner(this);
    showOuter(this);
    double del = pointer->z*cos(toRad(view->rotateY));
    double y = view->y+0.5 - pointer->z*sin(toRad(view->rotateY));
    double x = view->x + del*cos(toRad(view->rotateX-90));
    double z = view->z + del*sin(toRad(view->rotateX-90));
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(view->x/F, (view->y+1)/F, view->z/F);
    glVertex3d(x/F, y/F, z/F);
    glVertex3d(view->x/F, (view->y+1)/F, view->z/F);
    glEnd();
}

void renderCollisionBox() { collBox->show(); }