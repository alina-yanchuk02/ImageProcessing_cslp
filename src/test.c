/**
 *  \file test.c
 *
 *  \brief Problem name: Image processing in C
 *
 *  Menu
 *
 *  \author Alina Yanchuk
 *  \author Sandra Andrade
 */



#include <stdio.h>
#include <stdlib.h>
#include "RGBImage.h"
#include "greyImage.h"
#include "binImage.h"



int main(void){



  int escolha_tipo=1;
  int opera=1;
  char nome[40];
  char nome2[400];
  int intensidade;

  double edge_kernel[3*3] = {-1.0, 0.0, 1.0, -2.0, 0.0, 2.0, -1.0, 0.0, 1.0};
  double blur_kernel[3*3] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const double filter_params[2*4] = {1.0, 0.0, 1.0, 0.0, 1.0, 0.5, 9.0, 0.0};


  while (escolha_tipo!=4){

  printf("\n------------------------------\n");
  printf("\n*****IMAGE PROCESSING*****\n");
  printf("\n Escolha o tipo de imagem com o qual quer trabalhar: ");
  printf("\n 1 - Imagem RGB (.ppm)");
  printf("\n 2 - Imagem GreyScale (.pgm) ");
  printf("\n 3 - Imagem Binária (.pbm)");
  printf("\n 4 - Sair ");
  printf("\n ->");

  scanf("%d",&escolha_tipo);


  // estrutura switch
  switch (escolha_tipo) {

  case 1:{
    printf("\n------------------------------\n");
    printf("\nIntroduza o nome da imagem que quer processar: (tem de ser do tipo .ppm)  Utilize:  falls_1.ppm \n");
    printf("->");
    scanf("%s",nome);
    ImageRGB *imageA=readRGB(nome);

    while(opera!=5){
      printf("\n------------------------------\n");
      printf("\n Escolha a operação a realizar:");
      printf("\n 1 - Converter a imagem em Greyscale");
      printf("\n 2 - Mudar intensidade da imagem ");
      printf("\n 3 - Aplicar filtro ");
      printf("\n 4 - Aplicar marca de água ");
      printf("\n 5 - Sair ");
      printf("\n ->");
      scanf("%d",&opera);

        switch (opera) {
          case 1:{
            ImageRGB *imagergb;
            imagergb = readRGB(nome);
            GreyImage *image_convert_to_grey;
            image_convert_to_grey=from_rgb_to_grey(imagergb);
            writeGrey("resultado_rgb_to_grey.pgm",image_convert_to_grey);
            printf("\nO resultado foi criado em : resultado_rgb_to_grey.pgm\n ");

            break;
          }
          case 2:{
            ImageRGB *imagergb;
            imagergb = readRGB(nome);
            printf("\nEscolha a intensidade (ex.: 100 ou -100) ->  \n");
            scanf("%d",&intensidade);
            imagergb = intensityFilterRGB(imagergb,intensidade);
            writeRGB("resultadoRGBintensaty.ppm",imagergb);
            printf("\nO resultado foi criado em : resultadoRGBintensaty.ppm \n");
            break;
          }
          case 3:{
            printf("\nForam aplicados dois filtros:\n -> Edge Detection\n -> Blur\n\nOs resultados foram criados em: rgb_filtered_edge.ppm e rgb_filtered_blur.ppm. \n");

            

            ImageRGB *imagergb;
            ImageRGB *rgb_filtered_edge,*rgb_filtered_blur;
            imagergb = readRGB(nome);
            rgb_filtered_edge=filter_rgb(imagergb, edge_kernel, 1, filter_params[0], filter_params[1]);
            rgb_filtered_blur=filter_rgb(imagergb, blur_kernel, 1, filter_params[6], filter_params[7]);
            writeRGB("rgb_filtered_edge.ppm",rgb_filtered_edge);
            writeRGB("rgb_filtered_blur.ppm",rgb_filtered_blur);
            break;
          }
          case 4:{
            printf("\nIntroduza o nome da imagem a sobrepôr (tem de ser do mesmo tamanho da primeira! Utilize: falls_2.ppm)\n");
            printf("->\n");
            scanf("%s",nome2);
            ImageRGB *imageB = readRGB(nome2);
              
            ImageRGB *water = watermark(imageA,imageB,0.5);
              
            writeRGB("resultado_watermark.ppm",water);
            printf("\nO resultado foi publicado em resultado_watermark.ppm.\n");
            break;
          }

          case 5:{
            exit(1);
          }
        }
      }

  break;
  }

  case 2:{
    printf("\n------------------------------\n");
    printf("\nIntroduza o nome da imagem que quer processar: (tem de ser do tipo .pgm) Utilize: baboon.pgm \n");
    printf("->");
    scanf("%s",nome);
    while(opera!=4){
      printf("\n Escolha a operação a realizar: ");
      printf("\n 1 - Converter a imagem em Binária");
      printf("\n 2 - Mudar intensidade da imagem ");
      printf("\n 3 - Aplicar filtro ");
      printf("\n 4 - Sair ");
      printf("\n ->");
      scanf("%d",&opera);
      switch (opera) {
          case 1:{
            printf("\n Esta opção infelizmente não foi implementada.\n");
            break;
          }
          case 2:{
            GreyImage *imagegrey;
            imagegrey=readGrey(nome);
            printf("\nEscolha a intensidade (ex.: 100 ou -100) ->  \n");
            scanf("%d",&intensidade);
            imagegrey=intensityFilterGrey(imagegrey,intensidade);
            writeGrey("resultadoGreyintensaty.pgm",imagegrey);
            printf("\nO resultado foi criado em : resultadoGreyintensaty.pgm \n");

            break;
          }
          case 3:{
            printf("\nForam aplicados dois filtros:\n -> Edge Detection\n -> Blur\n\nOs resultados foram criados em: grey_filtered_edge.pgm e rgb_filtered_blur.pgm. \n");

           
            GreyImage *imagegrey;
            GreyImage *grey_filtered_edge,*grey_filtered_blur;
            imagegrey=readGrey(nome);
            grey_filtered_edge=filter_grey(imagegrey, edge_kernel, 1, filter_params[0], filter_params[1]);
            grey_filtered_blur=filter_grey(imagegrey, blur_kernel, 1, filter_params[6], filter_params[7]);
            writeGrey("grey_filtered_edge.pgm",grey_filtered_edge);
            writeGrey("rgb_filtered_blur.pgm",grey_filtered_blur);
            break;
          }
          case 4:{

            exit(1);
          }

    }


  }

  case 3:{
    printf("\n------------------------------\n");
    printf("\nIntroduza o nome da imagem que quer processar: (tem de ser do tipo .pbm) Utilize: circle.pbm \n");
    printf("->");
    scanf("%s",nome);
    while(opera!=2){
      printf("\n Escolha a operação a realizar: ");
      printf("\n 1 - Criar uma cópia");
      printf("\n 2 - Sair ");
      printf("\n ->");
      scanf("%d",&opera);
      switch (opera) {
          case 1:{
            BinImage *imagebin;
            imagebin = readBin(nome);
            writeBin("resultadoBIN.pbm", imagebin);
            printf("\nA cópia da sua imagem binária foi criada em resultadoBIN.pbm.\n");

            break;
          }
          case 3:{
            exit(1);
            
          }

  break;
  }

  case 4:{
    exit(1);
  }
    }
  }
  }
  }
  }


return 0;  
}





