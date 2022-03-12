#include "pgm.h"

int main(){
  image fichier;
  fichier=readPgm("image.pgm");
  if (fichier.width == 0) {
    printf("error: file not found \n");
    return 1 ;
  }
  printf("la longueur:%d , la largeur:%d , la profondeur:%d \n",fichier.width, fichier.height , fichier.depth);
  int i,j;
  for (i = 0; i < (int)fichier.width; i++) {
    for (j = 0; j < (int)fichier.height; j++) {
      printf("%d",fichier.data[i][j]);
    }
    printf("\n");
  }

  return 0;
}
