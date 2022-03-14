#include "pgm.h"

int main(){
  int i,j;

  image fichier;
  fichier=readPgm("image.pgm");
  if (fichier.width == 0) {
    printf("error: file not found \n");
    return 1 ;
  }
  printf("longueur:%d ||  largeur:%d ||  profondeur:%d \n",fichier.width, fichier.height , fichier.depth);
  for (i = 0; i < fichier.height; i++) {
    for (j = 0; j < fichier.width; j++) {
      printf("%d ", fichier.data[i][j]);
    }
    printf("\n");
  }
  freeImage(fichier);
  return 0;
}
