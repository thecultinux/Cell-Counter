#include "pgm.h"

image allocate(image fichier){
  int j;
  fichier.data=calloc(fichier.height,sizeof(char*));
  *(fichier.data)=calloc(fichier.height*fichier.width,sizeof(char));
  for( j=1; j<fichier.height ;j++){
    fichier.data[j]=fichier.data[j-1]+fichier.width;
  }
  return fichier;
}





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
  fichier= allocate(fichier);

  fread(fichier.data[0],sizeof(char),fichier.height*fichier.width,f);
  fclose(f);
  return fichier;
}

void freeImage(image fichier){
  free(*(fichier.data));
  free(fichier.data);
}
