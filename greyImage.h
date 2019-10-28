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
int getPixelGrey(GreyImage *image,int x, int y);
//BMPImage *from_grey_to_bin(GreyImage *greyImage);
GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity);
GreyImage *filter_grey(GreyImage *img, double *K, int Ks, double divisor, double offset);
void *change_pixelGREY(GreyImage *img,int x,int y,int pixel);

#endif
