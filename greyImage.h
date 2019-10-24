#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGE
#define IMAGE


typedef struct {
     unsigned char grey;
} greyPixel;


typedef struct {

    int  height;
    int width;
    greyPixel *pixels;

} GreyImage;


#endif
