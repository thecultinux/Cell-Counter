#include "pgm.h"

int main(){
  image fichier;
  fichier=readPgm("image.pgm");
  printf("la longueur:%d , la largeur:%d , la profondeur:%d \n",fichier.width, fichier.height , fichier.depth);
  return 0;
}
