#ifndef TEXTURE_H
#define TEXTURE_H

#include "base.h"

class Texture
{
public:
    const int BMP_HEADER_LENGTH = 54;
    GLint
        bedrock,  // bedrock
        stone,  // stone
        dirt,  /// dirt
        grass_top, grass_side, grass_bottom;  // grass
    Texture();
    bool powerOfTwo(int);
    GLint load(const char *);
};

#endif