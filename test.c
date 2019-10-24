#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "RGBImage.h"
//#include "binImage.h"
=======
//#include "RGBImage.h"
//#include "binImage.h"
#include "greyImage.h"
>>>>>>> 28d209257dbc050167cf6b411b70588f7f1b60e5

int main(void){

  ImageRGB *image;
  image = readRGB("lena.ppm");
  image = intensityFilterRGB(image,-100);
  colorPixel pixel = getPixelRGB(image,200,200);
  printf("%d\n",pixel.blue );
  writeRGB("resultadoRGB.ppm",image);

<<<<<<< HEAD
  /*BMPImage *image;
  image = readBin("LAND3.BMP");
  writeBin("resultadoBIN.bmp", image);*/
=======
  //BMPImage *image;
  //image = readBin("LAND3.BMP");
  //writeBin("resultadoBIN.bmp", image);
>>>>>>> 28d209257dbc050167cf6b411b70588f7f1b60e5


  GreyImage *image;
  image=readPGM("baboon.pgm");
  writePGM("resultadoGrey.pgm",image);
  
  return 0;
}
