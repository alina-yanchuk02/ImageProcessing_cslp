
#include "greyImage.h"

#include <stdlib.h>
#include <stdio.h>
 



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


