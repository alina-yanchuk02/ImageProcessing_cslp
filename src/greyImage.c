/**
 *  \file greyImage.c
 *
 *  \brief Problem name: Image processing in C
 *
 *  Imagem greyscale
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */
#include <stdio.h>
#include <stdlib.h>
#include "greyImage.h"
#include "binImage.h"

// LEITURA E ESCRITA DE IMAGENS PGM (GREYSCALE)

/**
 *  \brief Ler Imagem greyscale
 *
 * Recebe um ficheiro pgm, lê essa imagem de greyscale e retorna uma GreyImage
 */
GreyImage *readGrey(char *filename)
{
    char buff[1000];
    GreyImage *img;
    FILE *fp;


    fp = fopen(filename, "rb");


    fgets(buff, sizeof(buff), fp);


    img = (GreyImage*)malloc(sizeof(GreyImage));


    fscanf(fp, "%d %d", &img->width, &img->height);

    fscanf(fp, "%d", &img->max_grey);


    while (fgetc(fp) != '\n') ;

    img->pixels = (greyPixel*)malloc(img->width * img->height * sizeof(greyPixel));


    fread(img->pixels, img->width, img->height, fp);


    fclose(fp);

    return img;
}





/**
 *  \brief Escrever Imagem greyscale
 *
 * Recebe o nome do ficheiro de output e uma imagem GreyImage
 * Escreve a imagem no ficheiro de output
 */
void writeGrey(char *filename, GreyImage *img)
{
    FILE *fp;

    fp = fopen(filename, "wb");


    fprintf(fp, "P5\n");


    fprintf(fp, "%d %d\n",img->width,img->height);


    fprintf(fp, "%d\n",img->max_grey);

    fwrite(img->pixels, img->width, img->height, fp);

    fclose(fp);
}

/**
 *  \brief Grey Pixel
 *
 * Ao receber as Coordenadas de um certo pixel, retorna esse mesmo
 */
 int getPixelGrey(GreyImage *image,int x, int y){

   if (x < 0 || x > image->width || y < 0 || y > image->height){
     return 0;
   }
   int position = ((image->width-1) * y + x)-1;

   return image->pixels[position].grey;
 }

/**
 *  \brief De greyscale para binario
 *
 * Recebe uma GreyImage e transforma essa imagem numa imagem binaria, retornando uma BinImage
 * NOT WORKING
 */
BinImage *from_grey_to_bin(GreyImage *greyImage){

  BinImage *binImage;
  binImage = (BinImage*)malloc(sizeof(BinImage));
  binImage->pixels = (binPixel*)malloc(greyImage->width * greyImage->height * sizeof(binPixel));
  binImage->width = greyImage->width;
  binImage->height = greyImage->height;
  for(int i = 0; i < greyImage-> width * greyImage-> height; i++){
    if (greyImage->pixels[i].grey >= 128 ) {
      binImage->pixels[i].byte = 1;
    }
    else{binImage->pixels[i].byte= 0;}
  }
  for (int i = 0 ; i < binImage->width * binImage->height; i++) {
    printf("%i\n", binImage->pixels[i].byte );
  }
  return binImage;
}

/**
 *  \brief Filtro de intensidade para imagem greyscale
 *
 * Recebe uma GreyImage e um valor de intensidade
 * Retorna essa imagem com a intensidade escolhida
 */
GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity){
  for (int i = 0 ; i < greyImage->height * greyImage->width; i++){
    int grey = greyImage->pixels[i].grey + intensity;
    if (grey < 0) {greyImage->pixels[i].grey = 0;}
    else if (grey > 255) {greyImage->pixels[i].grey = 255;}
    else{greyImage->pixels[i].grey=grey;}

  }
    return greyImage;
}

/**
 *  \brief Modificar pixel
 *
 * Recebe as cordenadas de um pixel e os novos valores
 * Troca os valores do pixel pelos novos
 */
void *change_pixelGREY(GreyImage *img,int x,int y,int pixel){
    int position = ((img->width-1) * y + x)-1;
    img->pixels[position].grey=pixel;

}


/**
 *  \brief Filtro Grey
 *
 *
 */
GreyImage *filter_grey(GreyImage *img, double *K, int Ks, double divisor, double offset){

  GreyImage *img_filtered;
  unsigned int ix, iy, l;

  int kx, ky;
  double cp;
  int pixel;

  img_filtered = (GreyImage*)malloc(sizeof(GreyImage));
  img_filtered->width = img->width;
  img_filtered->height = img->height;
  img_filtered->max_grey = img->max_grey;
  img_filtered->pixels = (greyPixel*)malloc(img->width * img->height * sizeof(greyPixel));

  for(ix=0; ix < img->width; ix++) {
    for(iy=0; iy < img->height; iy++) {

      cp = 0.0;
      for(kx=-Ks; kx <= Ks; kx++) {
        for(ky=-Ks; ky <= Ks; ky++) {

	        cp += (K[(kx+Ks) + (ky+Ks)*(2*Ks+1)]/divisor) *((double)getPixelGrey(img,ix+kx,iy+ky)) + offset;

        }
      }

      cp = (cp>255.0) ? 255.0 : ((cp<0.0) ? 0.0 : cp);
      if (cp>255) {cp=255.0;}
      else if (cp<0.0) {cp=0.0;}
      else {cp=cp;}


      change_pixelGREY(img_filtered, ix, iy, (int)cp);

    }
  }
  return img_filtered;
}
