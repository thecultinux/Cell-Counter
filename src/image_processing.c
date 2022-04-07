#include "library.h"

image generate_frame_seed(int width, int height, image frame){
  int i=0;
  int j=0;
  frame.width=width;
  frame.height=height;
  frame.depth=255;
  for(i = 0; i<frame.height; i++){
    for(j = 0; j<frame.width; j++){
      if(i==0 || i==frame.height-1 || j==0 || j==frame.width-1){
        frame.data[i][j]=255;
      }
      else frame.data[i][j]=0;
    }
  }
  return frame;
}

image delete_edge_cell(image fichier, image result){
  int i,j;
  image border_cells_only=fichier;
  border_cells_only=allocate(border_cells_only);
  image seed=fichier;
  seed=allocate(seed);
  seed=generate_frame_seed(fichier.width,fichier.height,seed);
  border_cells_only=reconstruct(fichier,seed,border_cells_only);
  result=XOR(fichier,border_cells_only,result);
  for(i = 0; i<result.height; i++){
    for(j = 0; j<result.width; j++){
      if(i==0 || i==result.height-1 || j==0 || j==result.width-1){
        result.data[i][j]=0;
      }
    }
  }
  freeImage(border_cells_only);
  freeImage(seed);
  return result;
}

image reverse (image fichier, image reversed){
  int i,j;
  for (i=0 ; i<fichier.height ; i++)
    for (j=0 ; j<fichier.width ; j++) {
      if (fichier.data[i][j]==0) {
        reversed.data[i][j]=255;
      }
      if (fichier.data[i][j]==255) {
        reversed.data[i][j]=0;
      }
    }
  return reversed;
}

image hole_plugging(image fichier, image result){
  image reversed1=fichier;
  image reversed2=fichier;
  image seed=fichier;
  seed=allocate(seed);
  reversed1=allocate(reversed1);
  reversed2=allocate(reversed2);
  int i,j;
  seed=generate_frame_seed(fichier.width,fichier.height,seed);
  reversed1=reverse(fichier,reversed1);
  result=reconstruct(reversed1,seed,result);
  reversed2=reverse(result,reversed2);
  for(i = 0; i<reversed2.height; i++){
    for(j = 0; j<reversed2.width; j++){
      if(i==0 || i==reversed2.height-1 || j==0 || j==reversed2.width-1){
        reversed2.data[i][j]=0;
      }
    }
  }
  image_copy(reversed2,result);
  freeImage(reversed1);
  freeImage(reversed2);
  freeImage(seed);
  return result;
}

image manual_erosion(image fichier , int rep, image result){
  int i ;

  for(i=0 ; i<rep ; i++) {
    result=erode(fichier,result);
  }
  return result;
}

int isEmpty(image fichier){
  int sum=0;
  int i,j;
  for (i = 0; i < fichier.height; i++) {
    for (j= 0; j < fichier.width; j++) {
      sum=sum+fichier.data[i][j];
    }
  }
  if (sum==0) return 1; //retourne 1 si vide
  else return 0; //retourne 0 sinon
}

void wipeImage(image fichier){
  int i,j;
  for (i = 0; i < fichier.height; i++) {
    for (j= 0; j < fichier.width; j++) {
      fichier.data[i][j]=0;
    }
  }
}
