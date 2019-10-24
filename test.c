#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"
#include "binImage.h"



int main(void){

  ImageRGB *imagergb;
  imagergb = readRGB("lena.ppm");
  imagergb = intensityFilterRGB(imagergb,-100);
  writeRGB("resultadoRGBintensaty.ppm",imagergb);
  colorPixel pixel = getPixelRGB(imagergb,200,200);


  GreyImage *imagegrey;
  imagegrey=readGrey("baboon.pgm");
  imagegrey=intensityFilterGrey(imagegrey,100);
  writeGrey("resultadoGreyintensaty.pgm",imagegrey);


  BMPImage *imagebin;
  imagebin = readBin("LAND3.BMP");
  writeBin("resultadoBIN.bmp", imagebin);


  return 0;
}
