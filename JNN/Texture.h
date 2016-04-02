#ifndef Texture_h
#define Texture_h

#include "OpenGL.h"
#include <stdio.h>
#include <stdlib.h>
class Texture {
public:
    Texture() {}
    friend GLuint LoadTextureFromBMP( const char * filename, int width, int height );
};

#endif