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
    int max_grey;
    greyPixel *pixels;

} GreyImage;


GreyImage *readGrey(char *filename);
void writeGrey(char *filename, GreyImage *img);

#endif
