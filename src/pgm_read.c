#include "pgm.h"


image readPgm( char *file ) {
  FILE* f;
  image error;
  image fichier;
  f = fopen(file,"rb");
  if (f==NULL) {
    return error;
  }

  fseek(f,2*sizeof(char),0);
  fscanf(f,"%d %d",&(fichier.width),&(fichier.height));
  fseek(f,sizeof(char),1);
  fscanf(f,"%d",&(fichier.depth));


  return fichier;
}
