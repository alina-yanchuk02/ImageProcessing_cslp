/**
 *  \file binImage.h
 *
 *  \brief Problem name: Image processing in C
 *
 *  Estrutura da Imagem binaria
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef IMAGEBIN
#define IMAGEBIN

/**
 *  \brief Defenição da estrutura do Pixel de uma imagem binaria
 */
typedef struct {
    /** \brief valor de cada Pixel */
     unsigned char byte;
} binPixel;

/**
 *  \brief Defenição da estrutura da imagem binaria
 */
typedef struct {
    /** \brief altura da imagem binaria*/
    int  height;
    /** \brief largura da imagem binaria*/
    int width;
    /** \brief array de pixels da imagem binaria*/
    binPixel *pixels;

} BinImage;

BinImage *readBin(char *filename);
void writeBin(char *filename, BinImage *image);

#endif
