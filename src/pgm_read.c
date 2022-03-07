#include "pgm.h"


image readPgm( char *file ) {
  FILE* f;
  image fichier = NULL;
  f = fopen(file,"r");
  if (f==NULL) {
    return NULL;
  }

  fseek(f,2*sizeof(char),0);
  int a;
  fread(&a,sizeof(a),1,f);
  printf("%d\n",a);
  return fichier;
}
