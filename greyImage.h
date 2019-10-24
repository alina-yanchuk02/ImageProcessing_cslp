#include <stdio.h>
#include <stdlib.h>
#include "binImage.h"

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

greyPixel getGreyPixel(ImageGrey *ImageGrey,int x, int y);
BMPImage *from_grey_to_bin(GreyImage *greyImage);
BMPImage *intensityFilterGrey(GreyImage *greyImage, int intensity);

GreyImage *readGrey(char *filename);
void writeGrey(char *filename, GreyImage *img);

#endif
