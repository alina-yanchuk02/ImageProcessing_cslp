#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"
#include "binImage.h"



int main(void){

  //ImageRGB *imagergb;
  //imagergb = readRGB("lena.ppm");
  //writeRGB("resultado_rgb.ppm",imagergb);
  //imagergb = intensityFilterRGB(imagergb,-100);
  //writeRGB("resultadoRGBintensaty.ppm",imagergb);
  //colorPixel pixel = getPixelRGB(imagergb,200,200);
  

  //GreyImage *imagegrey;
  //imagegrey=readGrey("baboon.pgm");
  //imagegrey=intensityFilterGrey(imagegrey,100);
  //writeGrey("resultadoGreyintensaty.pgm",imagegrey);


  //BMPImage *imagebin;
  //imagebin = readBin("LAND3.BMP");
  //writeBin("resultadoBIN.bmp", imagebin);


  // CONVERT FROM GRB TO GREY:
  /*  
  ImageRGB *imagergb;
  imagergb = readRGB("lena.ppm");
  GreyImage *image_convert_to_grey;
  image_convert_to_grey=from_rgb_to_grey(imagergb);
  writeGrey("resultado_rgb_to_grey.pgm",image_convert_to_grey);
  */


  return 0;
}
