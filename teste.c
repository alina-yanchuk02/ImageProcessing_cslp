
#include "image.h"
#include "greyImage.h"

#include <stdlib.h>
#include <stdio.h>
 
#define RGB 255


// RGB: ///////////////////////////////////////////////////////////////////////////////////////////////////

// lê imagens PPM RGB:


Image *readRGB(char *filename)
{
    char buff[16];
    Image *img;
    FILE *fp;
    int c, rgb_color;
        
    fp = fopen(filename, "rb");
 

    fgets(buff, sizeof(buff), fp);


    img = (Image*)malloc(sizeof(Image));


    fscanf(fp, "%d %d", &img->width, &img->height);
 
    fscanf(fp, "%d", &rgb_color);


    while (fgetc(fp) != '\n') ;
  
    img->pixels = (colorPixel*)malloc(img->width * img->height * sizeof(colorPixel));


    fread(img->pixels, 3 * img->width, img->height, fp);
    

    fclose(fp);

    return img;
}



// escreve imagens RGB PPM: 


void writeRGB(char *filename, Image *img)
{
    FILE *fp;
    
    fp = fopen(filename, "wb");
 

    fprintf(fp, "P6\n");

    
    fprintf(fp, "%d %d\n",img->width,img->height);

 
    fprintf(fp, "%d\n",RGB);
    
    fwrite(img->pixels, 3 * img->width, img->height, fp);

    fclose(fp);
}



// GREYSCALE: ///////////////////////////////////////////////////////////////////////////////////////////////////






int main(){

    Image *image;
    image = readRGB("lena.ppm");

    writeRGB("resultadoRGB.ppm",image);

}