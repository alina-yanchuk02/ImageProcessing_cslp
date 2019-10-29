/**
 *  \file RGBImage.h
 *
 *  \brief Problem name: Image processing in C
 *
 *  Estrutura da Imagem RGB
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */
#include <stdio.h>
#include <stdlib.h>
#include "greyImage.h"
#ifndef IMAGERGB
#define IMAGERGB

/**
 *  \brief Defenição da estrutura do Pixel de uma imagem RGB
 */
typedef struct {
    /** \brief valor de vermelho do pixel*/
     unsigned char red;
    /** \brief valor de verde do pixel*/
     unsigned char green;
    /** \brief valor de azul do pixel*/
     unsigned char blue;
} colorPixel;

/**
 *  \brief Defenição da estrutura da imagem rgb
 */
typedef struct {
    /** \brief altura da imagem rgb*/
    int  height;
    /** \brief largura da imagem rgb*/
    int width;
    /** \brief array de pixels da imagem rgb*/
    colorPixel* pixels;

} ImageRGB;



ImageRGB *readRGB(char *filename);
void writeRGB(char *filename, ImageRGB *img);
int getPixelRGB(ImageRGB *imageRGB,int x, int y, int l);
ImageRGB *intensityFilterRGB(ImageRGB *imageRGB, int percentagem);
GreyImage *from_rgb_to_grey(ImageRGB *RGBimg);
ImageRGB *filter_rgb(ImageRGB *img,double *K, int Ks, double divisor, double offset);
void *put_pixel_unsafe(ImageRGB *img,int x,int y,int red,int green,int blue);
ImageRGB *watermark(ImageRGB * imageA, ImageRGB * imageB, float alpha);
colorPixel *getPixelRGB_complet(ImageRGB *imageRGB,int x, int y);
void *change_pixel(ImageRGB *img,int x,int y,int red,int green,int blue);


#endif
