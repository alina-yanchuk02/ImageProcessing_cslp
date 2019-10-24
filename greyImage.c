#include <stdio.h>
#include <stdlib.h>
#include "greyImage.h"
#include "binImage.h"

greyPixel getGreyPixel(GreyImage *greyImage,int x, int y){
  if (x < 0 || x > greyImage->width || y < 0 || y > greyImage->height){
    printf("Coordenadas incorretas!\n");
    exit(0);
  }
  int position = ((greyImage->width-1) * y + x)-1;
  return greyImage->pixels[position];
}

BMPImage *from_grey_to_bin(GreyImage *greyImage){

}

GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity){
  for (int i = 0 ; i < greyImage->height * greyImage->width; i++){
    int grey = greyImage->pixels[i].grey + intensity;
    if (grey < 0) {greyImage->pixels[i].grey = 0;}
    else if (grey > 255) {greyImage->pixels[i].grey = 255;}
    else{greyImage->pixels[i].red=grey;}

  }
    return greyImage;
}
