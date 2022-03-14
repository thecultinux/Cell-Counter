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

int histogram(image fichier; int histogram[]){
  int histogram[256];
  int i,j,k;
  for( i = 0; i<255; i++){
    j=0;
    k=0;
    for( j = 0; j<fichier.height; j++){
      for( k = 0; k<fichier.width; k++){
        if(fichier.data[j][k]==i){
          histogram[i]++;
        }
      }
    }
  }
  return 0;
}

int auto_threshold(image fichier){
  int threshold=1;
  int s=1;
  int i;
  int h[256];
  h=histogram(fichier;h);
  float average0, average1,w0,w1,simga2,old_sigma2=0;
  for(s=1; s<255; s++){
    for(i=0; i<s-1; i++){
      w0=w0+h[i];
      average0=average0+(i*h[i]/w0);
    }
    for(i=s; i<255; i++){
      w1=w1+h[i];
      average1=average1+(i*h[i]/w1);
    }
    old_sigma2=simga2;
    simga2=w0*w1*(average0-average1)*(average0-average1);
    if(old_sigma2<simga2){
      threshold=s;
    }
  }

  return 0;
}
