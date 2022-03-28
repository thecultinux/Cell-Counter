#include "library.h"

image generate_frame_seed(int width, int height){
  image frame;
  int i,j;
  frame.width=width;
  frame.height=height;
  frame.depth=255;
  frame=allocate(frame);
  for(i = 0; i<frame.width; i++){
    for(j = 0; j<frame.height; j++){
      if(i==0 || i==frame.width || j==0 || j==frame.height){
        frame.data[i][j]=255;
      }
      else frame.data[i][j]=0;
    }
  }
  return frame;
}

image delete_edge_cell(image fichier){
  image seed;
  image border_cells_only;
  border_cells_only=fichier;
  seed=fichier;
  border_cells_only=allocate(border_cells_only);
  seed=generate_frame_seed(fichier.width,fichier.height);
  border_cells_only=reconstruct(fichier,seed);
  fichier=XOR(fichier,border_cells_only);
  return fichier;
}
