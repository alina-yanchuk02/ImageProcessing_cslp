/**
 *  \file binImage.c
 *
 *  \brief Problem name: Image processing in C
 *
 *  Imagem binaria
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binImage.h"

/**
 *  \brief Ler Imagem Binaria
 *
 * Recebe um ficheiro pbm, lê essa imagem binaria e retorna uma BinImage
 */
BinImage *readBin(char *filename){
  char buff[16];
  BinImage *img;
  FILE *fp;
  int c;

  //open PBM file for reading
  fp = fopen(filename, "rb");

  //read image format
  fgets(buff, sizeof(buff), fp);


   //alloc memory form image
   img = (BinImage *)malloc(sizeof(BinImage));


   //check for comments
   c = getc(fp);
   while (c == '#') {
   while (getc(fp) != '\n') ;
        c = getc(fp);
   }

   ungetc(c, fp);

  //read image size information
   fscanf(fp, "%d %d", &img->width, &img->height);



   while (fgetc(fp) != '\n') ;
   //memory allocation for pixel data
   img->pixels = (binPixel*)malloc(img->width * img->height * sizeof(binPixel));

   //read pixel data from file
   fread(img->pixels, img->width, img->height, fp);

  /* for (int i = 0; i < img->width*img->height; i++){
     int z = img->pixels[i].bit;
     if(z >= 1){printf("%d\n", img->pixels[i].bit );}

   }*/
   fclose(fp);
   return img;
}

/**
 *  \brief Escrever Imagem Binaria
 *
 * Recebe o nome do ficheiro de output e uma imagem binImage
 * Escreve a imagem no ficheiro de output
 */
void writeBin(char *filename, BinImage *img)
{
    FILE *fp;

    fp = fopen(filename, "wb");

    fprintf(fp, "P4\n");

    fprintf(fp, "%d %d\n",img->width,img->height);


    fwrite(img->pixels, img->width, img->height, fp);

    fclose(fp);
}
