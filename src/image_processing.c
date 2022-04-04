#include "library.h"

image generate_frame_seed(int width, int height){
  image frame;
  int i=0;
  int j=0;
  frame.width=width;
  frame.height=height;
  frame.depth=255;
  frame=allocate(frame);
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

image delete_edge_cell(image fichier){
  int i,j;
  image seed,result;
  image border_cells_only;
  seed=generate_frame_seed(fichier.width,fichier.height);
  border_cells_only=reconstruct(fichier,seed);
  result=XOR(fichier,border_cells_only);
  for(i = 0; i<result.height; i++){
    for(j = 0; j<result.width; j++){
      if(i==0 || i==result.height-1 || j==0 || j==result.width-1){
        result.data[i][j]=0;
      }
    }
  }
  return result;
}


image reverse (image fichier){
  int i,j;
  image reversed=fichier;
  reversed=allocate(reversed);
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

image hole_plugging(image fichier){
  image result,seed,reversed;
  int i,j;
  seed=generate_frame_seed(fichier.width,fichier.height);
  reversed=reverse(fichier);
  result=reconstruct(reversed,seed);
  result=reverse(result);
  for(i = 0; i<result.height; i++){
    for(j = 0; j<result.width; j++){
      if(i==0 || i==result.height-1 || j==0 || j==result.width-1){
        result.data[i][j]=0;
      }
    }
  }
  return result;
}

image manual_erosion(image fichier , int rep){
  image result;
  int i ;
  for(i=0 ; i<rep ; i++) {
    result=erode(fichier);
    fichier=result;
  }
  return result;
}
