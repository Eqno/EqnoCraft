#include <init.h>
#include <utils.h>
#include <timer.h>
#include <ground.h>
#include <operation.h>

bool judgeInside(double x, double y, double z)
{
    const auto &m = block[getHash(x+0.5, z+0.5)];
    if (m.find(y+0.5) != m.end()) return true;
    return false;
}

void putBlock()
{
    double x = view->x, y = view->y, z = view->z, dis = 0;
    while (dis < pointer->z)
    {
        double del = dis*cos(toRad(view->rotateY));
        double ny = view->y - dis*sin(toRad(view->rotateY));
        double nx = view->x + del*cos(toRad(view->rotateX-90));
        double nz = view->z + del*sin(toRad(view->rotateX-90));
        if (judgeInside(nx, ny, nz))
        {
            int resX = x + 0.5, resY = y + 0.5, resZ = z + 0.5;
            const auto &m = block[getHash(resX, resZ)];
            if (m.find(resY) == m.end())
            {
                printf("%.2f\n", view->y);
                addStone(resX, resY, resZ);
            }
            return ;
        }
        x = nx, y = ny, z = nz, dis += 0.3;
    }
}

void removeBlock()
{
    double x = view->x, y = view->y, z = view->z, dis = 0;
    while (dis < pointer->z)
    {
        double del = dis*cos(toRad(view->rotateY));
        y = view->y - dis*sin(toRad(view->rotateY));
        x = view->x + del*cos(toRad(view->rotateX-90));
        z = view->z + del*sin(toRad(view->rotateX-90));
        if (judgeInside(x, y, z))
        {
            int resX = x + 0.5, resY = y + 0.5, resZ = z + 0.5;
            auto &m = block[getHash(resX, resZ)];
            if (m.find(resY) != m.end())
            {
                // printf("%.2f %.2f %.2f\n", x, y, z);
                m.erase(resY);
            }
            return ;
        }
        dis += 0.3;
    }
}