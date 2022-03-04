#ifndef BLOCK_H
#define BLOCK_H

#include <GL/freeglut_std.h>
// It has to be defined before any other .h in GL.
#include <GL/gl.h>
#include <unordered_map>

#include <utils.h>
#include <coord.h>

class Block: public Coord
{
public:
    static constexpr double INIT_RAD = 0.5;
    GLint blockTex;
    Block(GLint, double, double, double);
    Block(GLint, double, double, double, double);
    void show() const;
};

extern std::unordered_map<unsigned long long,
    std::unordered_map<int, Coord *>> block;

void renderBlock();

template <class T>
inline void addBlock(double x, double y, double z)
{
    ull hash = getHash(x, z);
    Coord *newBlock = new T(x, y, z);
    block[hash][y] = newBlock;
}

template <class T>
inline void addBlock(double x, double y, double z, double r)
{
    ull hash = getHash(x, z);
    Coord *newBlock = new T(x, y, z, r);
    block[hash][y] = newBlock;
}

/*
    1 1 1
    1 0 1
    1 1 1
 */

#endif