
#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"

#define RGB 255


ImageRGB *readRGB(char *filename)
{
    char buff[16];
    ImageRGB *img;
    FILE *fp;
    int c, rgb_color;

    fp = fopen(filename, "rb");


    fgets(buff, sizeof(buff), fp);


    img = (ImageRGB*)malloc(sizeof(ImageRGB));


    fscanf(fp, "%d %d", &img->width, &img->height);

    fscanf(fp, "%d", &rgb_color);


    while (fgetc(fp) != '\n') ;

    img->pixels = (colorPixel*)malloc(img->width * img->height * sizeof(colorPixel));


    fread(img->pixels, 3 * img->width, img->height, fp);


    fclose(fp);

    return img;
}


void writeRGB(char *filename, ImageRGB *img)
{
    FILE *fp;

    fp = fopen(filename, "wb");


    fprintf(fp, "P6\n");


    fprintf(fp, "%d %d\n",img->width,img->height);


    fprintf(fp, "%d\n",RGB);

    fwrite(img->pixels, 3 * img->width, img->height, fp);

    fclose(fp);
}
