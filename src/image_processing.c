#include "library.h"


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
