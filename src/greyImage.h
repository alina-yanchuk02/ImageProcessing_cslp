/**
 *  \file greyImage.h
 *
 *  \brief Problem name: Image processing in C
 *
 *  Estrutura da Imagem Greyscale
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */
#include <stdio.h>
#include <stdlib.h>
#include "binImage.h"

#ifndef IMAGEGREY
#define IMAGEGREY

/**
 *  \brief Defenição da estrutura do Pixel de uma imagem greyscale
 */
typedef struct {
    /** \brief valor de cada Pixel */
     unsigned char grey;
} greyPixel;

/**
 *  \brief Defenição da estrutura da imagem greyscale
 */
typedef struct {
    /** \brief altura da imagem greyscale*/
    int  height;
    /** \brief largura da imagem greyscale*/
    int width;
    /** \brief valor maximo de cinzentos na imagem greyscale*/
    int max_grey;
    /** \brief array de pixels da imagem greyscale*/
    greyPixel *pixels;

} GreyImage;

GreyImage *readGrey(char *filename);
void writeGrey(char *filename, GreyImage *img);
int getPixelGrey(GreyImage *image,int x, int y);
BinImage *from_grey_to_bin(GreyImage *greyImage);
GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity);
GreyImage *filter_grey(GreyImage *img, double *K, int Ks, double divisor, double offset);
void *change_pixelGREY(GreyImage *img,int x,int y,int pixel);

#endif
