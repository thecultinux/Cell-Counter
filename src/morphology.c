#include "library.h"

int erode(image fichier){
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
        fichier.data[i][j]=255;
        break;
      }
      if((fichier.data[i][j-1]==0)
      || (fichier.data[i][j+1]==0)
      || (fichier.data[i-1][j]==0)
      || (fichier.data[i+1][j]==0)
      || (fichier.data[i-1][j-1]==0)
      || (fichier.data[i-1][j+1]==0)
      || (fichier.data[i+1][j-1]==0)
      || (fichier.data[i+1][j+1]==0)){
        fichier.data[i][j]=0;
        break;
      }
    }
  }
  return 0;
}

image erode_(image fichier){
  image eroded;
  int i,j,k,l,min;
  eroded.height=fichier.height;
  eroded.width=fichier.width;
  eroded.depth=fichier.depth;
  eroded=allocate(eroded);
  for (i=0;  i <fichier.height;  i++) {
    eroded.data[i][0]=fichier.data[i][0];
    eroded.data[i][fichier.width-1]=fichier.data[i][fichier.width-1];
  }
  for (j=1;  j <fichier.width-1;  j++) {
    eroded.data[0][j]=fichier.data[0][j];
    eroded.data[fichier.height-1][j]=fichier.data[fichier.height-1][j];
  }
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      min=fichier.data[i][j];
      for(k=i-1 ; k<i+2 ; k++){
        for(l=j-1 ; l<j+2 ; l++){
          if (fichier.data[k][l]<min){
            min=fichier.data[k][l];
            printf("%d\n",min);
          }
        }
      }
      if (min==255) eroded.data[i][j]=255;
      else eroded.data[i][j]=0;
    }
  }
  return eroded;
}


int expanse(image fichier){
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
        fichier.data[i][j]=0;
        break;
      }
      if((fichier.data[i][j-1]==255)
      || (fichier.data[i][j+1]==255)
      || (fichier.data[i-1][j]==255)
      || (fichier.data[i+1][j]==255)
      || (fichier.data[i-1][j-1]==255)
      || (fichier.data[i-1][j+1]==255)
      || (fichier.data[i+1][j-1]==255)
      || (fichier.data[i+1][j+1]==255)){
        fichier.data[i][j]=255;
        break;
      }
    }
  }
  return 0;
}


image expanse_(image fichier){
  image expansed;
  int i,j,k,l,max;
  expansed.height=fichier.height;
  expansed.width=fichier.width;
  expansed.depth=fichier.depth;
  expansed=allocate(expansed);
  for (i=0;  i <fichier.height;  i++) {
    expansed.data[i][0]=fichier.data[i][0];
    expansed.data[i][fichier.width-1]=fichier.data[i][fichier.width-1];
  }
  for (j=1;  j <fichier.width-1;  j++) {
    expansed.data[0][j]=fichier.data[0][j];
    expansed.data[fichier.height-1][j]=fichier.data[fichier.height-1][j];
  }
  for (i = 1; i < fichier.height-1; i++) { //on commence a 1 et on s'arrete a -1 car la bordure n'a pas de voisins
    for (j = 1; j < fichier.width-1; j++) {
      max=fichier.data[i][j];
      for(k=i-1 ; k<i+2 ; k++){
        for(l=j-1 ; l<j+2 ; l++){
          if (fichier.data[k][l]>max){
            max=fichier.data[k][l];
            printf("%d\n",max);
          }
        }
      }
      if (max==255) expansed.data[i][j]=255;
      else expansed.data[i][j]=0;
    }
  }
  return expansed;
}
