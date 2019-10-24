#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGE
#define IMAGE

typedef struct {
     unsigned char red,green,blue;
} colorPixel;

typedef struct {

    int  height;
    int width;
    colorPixel* pixels;

} ImageRGB;

ImageRGB *readRGB(char *filename);
void writeRGB(char *filename, ImageRGB *img);
colorPixel getPixelRGB(ImageRGB *imageRGB,int x, int y);
ImageRGB *intensityFilterRGB(ImageRGB *imageRGB, int percentagem);

#endif
