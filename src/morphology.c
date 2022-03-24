#include "library.h"

int erode(image fichier, image output){
  int i,j;
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      if(fichier.data[i][j-1]==255
        && (fichier.data[i][j+1]==255)
        && (fichier.data[i-1][j]==255)
        && (fichier.data[i+1][j]==255)
        && (fichier.data[i-1][j-1]==255)
        && (fichier.data[i-1][j+1]==255)
        && (fichier.data[i+1][j-1]==255)
        && (fichier.data[i+1][j+1]==255)){
        output.data[i][j]=255;
      }
      else if((fichier.data[i][j-1]==0)
      || (fichier.data[i][j+1]==0)
      || (fichier.data[i-1][j]==0)
      || (fichier.data[i+1][j]==0)
      || (fichier.data[i-1][j-1]==0)
      || (fichier.data[i-1][j+1]==0)
      || (fichier.data[i+1][j-1]==0)
      || (fichier.data[i+1][j+1]==0)){
        output.data[i][j]=0;
      }
    }
  }
  return 0;
}

int expanse(image fichier, image output){
  int i,j;
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      if(fichier.data[i][j-1]==0
        && (fichier.data[i][j+1]==0)
        && (fichier.data[i-1][j]==0)
        && (fichier.data[i+1][j]==0)
        && (fichier.data[i-1][j-1]==0)
        && (fichier.data[i-1][j+1]==0)
        && (fichier.data[i+1][j-1]==0)
        && (fichier.data[i+1][j+1]==0)){
        output.data[i][j]=0;
      }
      else if((fichier.data[i][j-1]==255)
      || (fichier.data[i][j+1]==255)
      || (fichier.data[i-1][j]==255)
      || (fichier.data[i+1][j]==255)
      || (fichier.data[i-1][j-1]==255)
      || (fichier.data[i-1][j+1]==255)
      || (fichier.data[i+1][j-1]==255)
      || (fichier.data[i+1][j+1]==255)){
        output.data[i][j]=255;
      }
    }
  }
  return 0;
}
