#include "library.h"

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
  fscanf(f,"%d %d ",&(fichier.width),&(fichier.height));
  fscanf(f,"%d ",&(fichier.depth));
  fichier=allocate(fichier);

  fread(fichier.data[0],sizeof(char),fichier.height*fichier.width,f);
  fclose(f);
  return fichier;
}

void freeImage(image fichier){
  free(*(fichier.data));
  free(fichier.data);
}

int are_same_image(image a, image b){ //returns 1 if images are the same
  return memcmp(a.data[0],b.data[0],a.height*a.width*sizeof(char))==0;
}

int image_copy(image source, image dest){
  assert(source.width==dest.width &&source.height==dest.height);
  int i,j;
  for (i = 0; i < source.height; i++) {
    for (j = 0; j < source.width; j++) {
      dest.data[i][j]=source.data[i][j];
    }
  }
  return 0;
}
/*
int image_copy(image source, image dest){
  memcpy(dest.data[0],source.data[0],source.width*source.height);
  return 0;
}
*/
