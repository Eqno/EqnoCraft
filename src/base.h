#ifndef BASE_H
#define BASE_H

#include <GL/freeglut_std.h>
// It has to be defined before any other .h in GL.
#include <gl/gl.h>
#include <string>
#include <vector>
#include <GL/gl.h>
#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>

// common colors
#define WHITE 1, 1, 1
#define BLACK 0, 0, 0
#define YELLOW 1, 1, 0
#define SKYBLUE 0, 1, 1

// specific colors
#define SKYCOLOR SKYBLUE, 1

// textures
extern GLint BEDROCKTEX;

// coord factors
const double F = 10;

#endif