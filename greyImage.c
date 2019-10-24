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


greyPixel getGreyPixel(GreyImage *greyImage,int x, int y){
  if (x < 0 || x > greyImage->width || y < 0 || y > greyImage->height){
    printf("Coordenadas incorretas!\n");
    exit(0);
  }
  int position = ((greyImage->width-1) * y + x)-1;
  return greyImage->pixels[position];
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
