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

image edge_cells_removal(image fichier , image edge){
  image reconst = fichier;
  image result = fichier;
  reconst=allocate(reconst);
  result=allocate(result);
  reconst = reconstruct(fichier,edge);
  result = XOR(reconst, fichier);
  return result;
}

int reverse (image fichier){
  int i,j;
  for (i=0 ; i<fichier.height ; i++)
    for (j=0 ; j<fichier.width ; j++) {
      if (fichier.data[i][j]==0) fichier.data[i][j]=255;
      if (fichier.data[i][j]==255) fichier.data[i][j]=0;
    }
  return 1;
}

/*image hole_plugging(image fichier , image edge){
  image result = fichier;
  result=allocate(result);
  reverse(fichier)
}*/
