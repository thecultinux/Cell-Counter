#include "pgm.h"

int main(){
  image fichier;
  fichier=readPgm("image.pgm");
  if (fichier.width == 0) {
    printf("error: file not found \n");
    return 1 ;
  }
  printf("longueur:%d ||  largeur:%d ||  profondeur:%d \n",fichier.width, fichier.height , fichier.depth);

  return 0;
}
