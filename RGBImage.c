
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
    int rgb_color;

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


int getPixelRGB(ImageRGB *imageRGB,int x, int y, int l){
  if (x < 0 || x > imageRGB->width || y < 0 || y > imageRGB->height){
    return 0;
  }
  int position = (y * imageRGB->width) + x;
  if (l==0){
    return imageRGB->pixels[position].red;}
  if (l==1){
    return imageRGB->pixels[position].green;}
  if (l==2){
    return imageRGB->pixels[position].blue;}

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


void *put_pixel_unsafe(ImageRGB *img,int x,int y,int red,int green,int blue){
    unsigned int ofs;
    ofs = (y * img->width) + x;
    img->pixels[ofs].red = red;
    img->pixels[ofs].green = green;
    img->pixels[ofs].blue = blue;
}



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
      for(l=0; l<3; l++)
        cp[l] = (cp[l]>255.0) ? 255.0 : ((cp[l]<0.0) ? 0.0 : cp[l]) ;
      put_pixel_unsafe(img_filtered, ix, iy, (int)cp[0], (int)cp[1], (int)cp[2]);
      
    }
  }
  return img_filtered;
}

