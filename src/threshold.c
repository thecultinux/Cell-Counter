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
