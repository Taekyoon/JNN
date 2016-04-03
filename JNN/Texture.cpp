#include "Texture.h"
Texture::Texture() {}
// for RABG ordered 4-bit BMP file...
GLuint LoadTextureFromBMP( const char * filename, int width, int height ) {
    GLuint texture;
    unsigned char * data;
    FILE * file;
    file = fopen( filename, "rb" );
    if ( file == NULL ) {
        //printf("There is no file.\n");
        return 0;
    }
    //printf("The file exists.\n");
    data = (unsigned char *)malloc( width * height * 4 );
    //int size = fseek(file,);
    fread( data, width * height * 4, 1, file );
    fclose( file );
    for(int i = 0; i < width * height ; ++i) {
        int idx = i*4;
        unsigned char R,G,B,A;
        R=data[idx], A=data[idx+1], B=data[idx+2], G=data[idx+3];
        data[idx+1]=G, data[idx+2]=B, data[idx+3]=A;
    }
    for(int i = 0; i < height/2; i++) {
        int r = i*width*4;
        for(int j = 0; j < width; j++) {
            unsigned char tmp;
            int t=(height-i-1)*width*4, c=j*4;
            for(int k=0;k<4;k++) {
                tmp=data[r+c+k];
                data[r+c+k]=data[t+c+k];
                data[t+c+k]=tmp;
            }
        }
    }
    glGenTextures( 1, &texture );
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
    free( data );
    return texture;
}
