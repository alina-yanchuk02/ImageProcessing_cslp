#include <stdio.h>
#include <stdlib.h>
#include "greyImage.h"


// LEITURA E ESCRITA DE IMAGENS PGM (GREYSCALE)


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


int getPixelGrey(GreyImage *image,int x, int y){

  if (x < 0 || x > image->width || y < 0 || y > image->height){
    return 0;
  }
  int position = ((image->width-1) * y + x)-1;
  
  return image->pixels[position].grey;
}

/*BMPImage *from_grey_to_bin(GreyImage *greyImage){

}*/

GreyImage *intensityFilterGrey(GreyImage *greyImage, int intensity){
  for (int i = 0 ; i < greyImage->height * greyImage->width; i++){
    int grey = greyImage->pixels[i].grey + intensity;
    if (grey < 0) {greyImage->pixels[i].grey = 0;}
    else if (grey > 255) {greyImage->pixels[i].grey = 255;}
    else{greyImage->pixels[i].grey=grey;}

  }
    return greyImage;
}

void *change_pixelGREY(GreyImage *img,int x,int y,int pixel){
    int position = ((img->width-1) * y + x)-1;
    img->pixels[position].grey=pixel;
    
}



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
