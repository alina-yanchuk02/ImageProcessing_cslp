#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binImage.h"

// Correct values for the header
#define MAGIC_VALUE         0x4D42
#define NUM_PLANE           1
#define COMPRESSION         0
#define NUM_COLORS          0
#define IMPORTANT_COLORS    0
#define BITS_PER_PIXEL      24
#define BITS_PER_BYTE       8


BMPImage *readBin(char *filename){
    FILE *fp = fopen(filename, "rb");
    BMPImage *image = malloc(sizeof(*image));

    // Read header
    fread(&image->header, sizeof(image->header), 1, fp);

    // Allocate memory for image data
    image->data = malloc(sizeof(*image->data) * image->header.image_size_bytes);

    // Read image data
    fread(image->data, image->header.image_size_bytes, 1, fp);

    fclose(fp);

    return image;
}


void writeBin(char *filename, BMPImage *image){
  FILE *fp = fopen(filename, "wb");

  fwrite(&image->header, sizeof(image->header), 1, fp);

  // Write image data
  fwrite(image->data, image->header.image_size_bytes, 1, fp);

  fclose(fp);

}
