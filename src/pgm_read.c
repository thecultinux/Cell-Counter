#include "pgm.h"


image readPgm( char *file ) {
  FILE* f;
  image error ={0,0,0,0};
  image fichier;
  f = fopen(file,"rb");
  if (f==NULL) {
    return error;
  }

  fseek(f,2*sizeof(char),0);
  fscanf(f,"%d %d",&(fichier.width),&(fichier.height));
  fseek(f,sizeof(char),1);
  fscanf(f,"%d",&(fichier.depth));
  fseek(f,sizeof(char),1);

  fichier.data=calloc(fichier.width,sizeof(*(fichier.data)));
  int i=0;
  for ( i = 0; i < (int)fichier.width; i++) {
    fichier.data[i]=calloc(fichier.height, sizeof(char));
  }
  return fichier;
}
