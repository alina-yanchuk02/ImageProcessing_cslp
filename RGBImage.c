
#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"
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

<<<<<<< HEAD
colorPixel getPixelRGB(ImageRGB *imageRGB,int x, int y){
  if (x < 0 || x > imageRGB->width || y < 0 || y > imageRGB->height){
    printf("Coordenadas incorretas!\n");
    exit(0);
  }
  int position = ((imageRGB->width-1) * y + x)-1;
  return imageRGB->pixels[position];
}

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
=======


GreyImage *from_rgb_to_grey(ImageRGB *img){

    for (i = 0; i < img->height; i++) { 
        for (j = 0; j < img->width; j++) { 
            temp = img->pixels[i][j]; 
            temp = (temp*3) / 3;

            
        } 
         
    } 
}
>>>>>>> 28d209257dbc050167cf6b411b70588f7f1b60e5
