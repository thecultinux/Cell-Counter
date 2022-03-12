#include "pgm.h"

int i;
int pixel=0;

image readPgm( char *file ) {
  FILE* f = NULL;
  image error ={0,0,0,0};
  image fichier;
  f = fopen(file,"rb");
  if (f==NULL) {
    return error;
  }

  fseek(f,3*sizeof(char),SEEK_SET);
  fscanf(f,"%d %d",&(fichier.width),&(fichier.height));
  fseek(f,sizeof(char),SEEK_CUR);
  fscanf(f,"%d",&(fichier.depth));
  fseek(f,sizeof(char),SEEK_CUR);
  //fichier.data=calloc(fichier.width*fichier.height,sizeof(char));

  for ( i = 0; i < fichier.width*fichier.height; i++){
    fscanf(f,"%d",&pixel);
    printf("%d ",pixel);
  }
  fclose(f);
  return fichier;
}
