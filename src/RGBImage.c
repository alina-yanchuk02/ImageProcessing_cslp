/**
 *  \file RGBImage.c
 *
 *  \brief Problem name: Image processing in C
 *
 *  Imagem RGB
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */

#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"
#define RGB 255

/**
 *  \brief Ler Imagem RGB
 *
 * Recebe um ficheiro ppm, lê essa imagem de rgb e retorna uma ImageRGB
 */
ImageRGB *readRGB(char *filename)
{
    char buff[16];
    ImageRGB *img;
    FILE *fp;
    int rgb_color;

    fp = fopen(filename, "rb");


    fgets(buff, sizeof(buff), fp);


    img = (ImageRGB*)malloc(sizeof(ImageRGB));

       int c;
       //check for comments
       c = getc(fp);
       while (c == '#') {
       while (getc(fp) != '\n') ;
            c = getc(fp);
       }

    fscanf(fp, "%d %d", &img->width, &img->height);

    fscanf(fp, "%d", &rgb_color);


    while (fgetc(fp) != '\n') ;

    img->pixels = (colorPixel*)malloc(img->width * img->height * sizeof(colorPixel));


    fread(img->pixels, 3 * img->width, img->height, fp);

    printf("%i\n",img->width);
    printf("%i\n",img->height );

    fclose(fp);

    return img;
}



/**
 *  \brief Escrever Imagem RGB
 *
 * Recebe o nome do ficheiro de output e uma imagem ImageRGB
 * Escreve a imagem no ficheiro de output
 */
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

/**
 *  \brief RGB Pixel
 *
 * Ao receber as Coordenadas de um certo pixel e que cor quer
 * Retorna a cor escolhida do pixel escolhidosse mesmo
 */
int getPixelRGB(ImageRGB *imageRGB,int x, int y, int l){
  if (x < 0 || x > imageRGB->width || y < 0 || y > imageRGB->height){
    return 0;
  }
  int position = ((imageRGB->width-1) * y + x)-1;
  if (l==0){
    return imageRGB->pixels[position].red;}
  if (l==1){
    return imageRGB->pixels[position].green;}
  if (l==2){
    return imageRGB->pixels[position].blue;}

}

/**
 *  \brief Filtro de intensidade para imagem RGB
 *
 * Recebe uma ImageRGB e um valor de intensidade
 * Retorna essa imagem com a intensidade escolhida
 */
ImageRGB *intensityFilterRGB(ImageRGB *imageRGB, int intensity){
  for (int i = 0 ; i < imageRGB->height * imageRGB->width; i++){
    //red
    int red = imageRGB->pixels[i].red + intensity;
    if (red < 0) {imageRGB->pixels[i].red = 0;}
    else if (red > 255) {imageRGB->pixels[i].red = 255;}
    else{imageRGB->pixels[i].red=red;}
    //green
    int green = imageRGB->pixels[i].green + intensity;
    if (green < 0) {imageRGB->pixels[i].green = 0;}
    else if (green > 255) {imageRGB->pixels[i].green = 255;}
    else{imageRGB->pixels[i].green=green;}
    //blue
    int blue = imageRGB->pixels[i].blue + intensity;
    if (blue < 0) {imageRGB->pixels[i].blue = 0;}
    else if (blue > 255) {imageRGB->pixels[i].blue = 255;}
    else{imageRGB->pixels[i].blue=blue;}
  }

    return imageRGB;
}

/**
 *  \brief De RGB para Greyscale
 *
 * Recebe uma ImageRGB e transforma essa imagem numa imagem greyscale, retornando uma GreyImage
 */
GreyImage *from_rgb_to_grey(ImageRGB *rgbimg){

  GreyImage *greyimg;
  greyimg = (GreyImage*)malloc(sizeof(GreyImage));
  greyimg->pixels = (greyPixel*)malloc(rgbimg->width * rgbimg->height * sizeof(greyPixel));
  greyimg->width = rgbimg->width;
  greyimg->height = rgbimg->height;
  greyimg->max_grey=255;
  for (int i = 0 ; i < rgbimg->height * rgbimg->width; i++){
    int red = rgbimg->pixels[i].red;
    int green = rgbimg->pixels[i].green;
    int blue = rgbimg->pixels[i].blue;
    int grey = 0.2126*red + 0.7152*green + 0.0722*blue;
    greyimg->pixels[i].grey=grey+0.5;
  }
  return greyimg;


}

<<<<<<< HEAD:src/RGBImage.c
/**
 *  \brief Modificar pixel
 *
 * Recebe as cordenadas de um pixel e os novos valores
 * Troca os valores do pixel pelos novos
 */
void *change_pixel(ImageRGB *img,int x,int y,int red,int green,int blue){
=======

void *change_pixelRGB(ImageRGB *img,int x,int y,int red,int green,int blue){
>>>>>>> caaca95800a96f0355e0489c82179bff8c6e4724:RGBImage.c
    int position = ((img->width-1) * y + x)-1;
    img->pixels[position].red = red;
    img->pixels[position].green = green;
    img->pixels[position].blue = blue;
}


/**
 *  \brief Filtro RGB
 *
 *
 */
ImageRGB *filter_rgb(ImageRGB *img, double *K, int Ks, double divisor, double offset){

  ImageRGB *img_filtered;
  unsigned int ix, iy, l;

  int kx, ky;
  double cp[3];
  int pixel_red,pixel_green,pixel_blue;

  img_filtered = (ImageRGB*)malloc(sizeof(ImageRGB));
  img_filtered->width = img->width;
  img_filtered->height = img->height;
  img_filtered->pixels = (colorPixel*)malloc(img->width * img->height * sizeof(colorPixel));

  for(ix=0; ix < img->width; ix++) {
    for(iy=0; iy < img->height; iy++) {

      cp[0] = cp[1] = cp[2] = 0.0;
      for(kx=-Ks; kx <= Ks; kx++) {
        for(ky=-Ks; ky <= Ks; ky++) {
          for(l=0; l<3; l++){
	          cp[l] += (K[(kx+Ks) + (ky+Ks)*(2*Ks+1)]/divisor) *((double)getPixelRGB(img,ix+kx,iy+ky,l)) + offset;
          }
        }
      }
      for(l=0; l<3; l++){
        
        if (cp[l]>255) {cp[l]=255.0;}
        else if (cp[l]<0.0) {cp[l]=0.0;}
        else {cp[l]=cp[l];}
      }

<<<<<<< HEAD:src/RGBImage.c
      change_pixel(img_filtered, ix, iy, (int)cp[0], (int)cp[1], (int)cp[2]);

=======
      change_pixelRGB(img_filtered, ix, iy, (int)cp[0], (int)cp[1], (int)cp[2]);
        
>>>>>>> caaca95800a96f0355e0489c82179bff8c6e4724:RGBImage.c
    }
  }
  return img_filtered;
}

/**
 *  \brief RGB Pixel
 *
 * Ao receber as Coordenadas de um certo pixel
 * Retorna esse pixel
 */
colorPixel *getPixelRGB_complet(ImageRGB *imageRGB,int x, int y){
  if (x < 0 || x > imageRGB->width || y < 0 || y > imageRGB->height){
    return NULL;
  }
  int position = ((imageRGB->width-1) * y + x)-1;
  colorPixel *p = (colorPixel*)malloc(sizeof(colorPixel));
  p->red = imageRGB->pixels[position].red;
  p->green = imageRGB->pixels[position].green;
  p->blue = imageRGB->pixels[position].blue;
  return p;
}

/**
 *  \brief watermark
 *
 * Recebe duas ImageRGB e um valor alpha
 * Retorna uma imagemRGB com o resultado
 * NOT WORKING
 */
ImageRGB *watermark(ImageRGB * imageA, ImageRGB * imageB, float alpha){
	if(imageA->height != imageB->height || imageA->width != imageB->width){
		printf("As imagens têm de ter o mesmo tamanho\n");
		exit(1);
	}
	float beta = 1 - alpha;
	ImageRGB *watermark = (ImageRGB*)malloc(sizeof(ImageRGB));
  watermark->height = imageA->height;
  watermark->width = imageA->width;
  watermark->pixels = (colorPixel*)malloc(imageA->width * imageA->height * sizeof(colorPixel));

	for(int height = 0; height < imageA->height; height++){
		for(int width = 0; width < imageA->width; width++){

		  colorPixel *pixelA = getPixelRGB_complet(imageA, height, width);
			colorPixel *pixelB = getPixelRGB_complet(imageB, height, width);
      int position = ((imageA->width-1) * width + height)-1;
			watermark->pixels[position].red = (int)((float)pixelA->red*beta + (float)pixelB->red*alpha);
			watermark->pixels[position].green = (int)((float)pixelA->green*beta + (float)pixelB->green*alpha);
			watermark->pixels[position].blue = (int)((float)pixelA->blue*beta + (float)pixelB->blue*alpha);
      printf("%i\n",watermark->pixels[position].red);
      printf("%i\n",watermark->pixels[position].green);
      printf("%i\n",watermark->pixels[position].blue);
  	}
	}
  return watermark;
}
