#include <stdio.h>
#include <stdlib.h>
//#include "RGBImage.h"
#include "binImage.h"

int main(void){

  /*ImageRGB *image;
  image = readRGB("lena.ppm");
  writeRGB("resultadoRGB.ppm",image);*/

  BMPImage *image;
  image = readBin("LAND3.BMP");
  writeBin("resultadoBIN.bmp", image);

  return 0;
}
