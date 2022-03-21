#include "pgm.h"

int manual_threshold( image fichier,int threshold){
  int i,j;
  for (i = 0; i < fichier.height; i++) {
    for ( j = 0; j < fichier.width; j++) {

      if (fichier.data[i][j]<=threshold) fichier.data[i][j]=0;
      if (fichier.data[i][j]>threshold) fichier.data[i][j]=255;

    }
  }
  return 0;
}

int histogram(image fichier, int histogram[]){
  int i,j,k;
  for( i = 0; i<=255; i++){
    for( j = 0; j<fichier.height; j++){
      for( k = 0; k<fichier.width; k++){
        if(fichier.data[j][k]==i){
          histogram[i]++;
        }
      }
    }
    //printf("h[%d]=%d\n",i,histogram[i] ); //affiche l'histogramme
  }
  return 0;
}

int indexmaxi(float t[], int size){
  int i;
  float max=0;
  int index_max=0;
  for (i = 0; i < size; i++) {
    if(t[i]>max){
      max = t[i];
      index_max=i;
    }
  }
  return index_max;
}

int auto_threshold(image fichier){
  int threshold=1;
  int s=1;
  int i,j;
  int h[256]={0};

  float sigma2[256] = {0};

  histogram(fichier,h);

  for(s=1; s<=255; s++){

    float average0 = 0;
    float average1 = 0;
    float w0 = 0;
    float w1 = 0;

    for(i=0; i<=s-1; i++){
      w0=w0+(float)h[i];
      average0=average0+(float)(i*h[i]);
    }
    average0=average0/w0;
    if(isnan(average0)) average0=0;

    for(j=s; j<=255; j++){
      w1=w1+(float)h[j];
      average1=average1+(float)(j*h[j]);
    }
    average1=average1/w1;
    if(isnan(average1)) average1=0;

    sigma2[s]=w0*w1*(average0-average1)*(average0-average1);
  }
  threshold=indexmaxi(sigma2,256);
  manual_threshold(fichier,threshold);
  return threshold;
}
