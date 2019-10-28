#include <stdio.h>
#include <stdlib.h>
#include "greyImage.h"
#ifndef IMAGERGB
#define IMAGERGB

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
int getPixelRGB(ImageRGB *imageRGB,int x, int y,int l);
ImageRGB *intensityFilterRGB(ImageRGB *imageRGB, int percentagem);
GreyImage *from_rgb_to_grey(ImageRGB *RGBimg);
ImageRGB *filter_rgb(ImageRGB *img,double *K, int Ks, double divisor, double offset);
void *changepixelRGB(ImageRGB *img,int x,int y,int red,int green,int blue);


#endif


 