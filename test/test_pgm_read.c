#include "pgm.h"

int main(int argc, char** argv){
  int i,j;
  if (argc!=2) {
    printf("Utilisation : test_pgm_read <image.pgm>\n");
    return -1;
  }
  image fichier;
  fichier=readPgm(argv[1]);
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
