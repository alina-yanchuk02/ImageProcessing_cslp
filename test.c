#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"




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
  
  double edge_kernel[3*3] = {-1.0, 0.0, 1.0, -2.0, 0.0, 2.0, -1.0, 0.0, 1.0};
  double blur_kernel[3*3] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const double filter_params[2*4] = {1.0, 0.0, 1.0, 0.0, 1.0, 0.5, 9.0, 0.0};
  ImageRGB *imagergb;
  ImageRGB *rgb_filtered_edge,*rgb_filtered_blur;
  imagergb = readRGB("lena.ppm");
  rgb_filtered_edge=filter_rgb(imagergb, edge_kernel, 1, filter_params[0], filter_params[1]);
  rgb_filtered_blur=filter_rgb(imagergb, blur_kernel, 1, filter_params[6], filter_params[7]);
  writeRGB("rgb_filtered_edge.ppm",rgb_filtered_edge);
  writeRGB("rgb_filtered_blur.ppm",rgb_filtered_blur);

  

  return 0;
}
