#include <stdio.h>
#include <stdlib.h>


#ifndef IMAGEGREY
#define IMAGEGREY


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
greyPixel getGreyPixel(GreyImage *GreyImage,int x, int y);
//BMPImage *from_grey_to_bin(GreyImage *greyImage);
GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity);


#endif
