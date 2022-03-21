#include "library.h"

int i,j;
int pixel=0;

int writePgm( image fichier, char* name) {
  FILE* f = NULL;
  f = fopen(name,"wb");
  if (f==NULL) {
    return -1;
  }

  rewind(f);
  fprintf(f, "P5\n%d %d\n%d\n",fichier.width, fichier.height, fichier.depth);
  fwrite(fichier.data[0],sizeof(char),fichier.height*fichier.width,f);
  fclose(f);
  return 0;
}
