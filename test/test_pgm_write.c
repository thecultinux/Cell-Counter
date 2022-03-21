#include "library.h"

int main(int argc, char** argv){
  int i,j;
  if(argc!=3){
    printf("Utilisation : test_pgm_write <image.pgm> <nom de la copie.pgm>\n");
    return -1;
  }
  image fichier;
  fichier=readPgm(argv[1]);
  char* name=argv[2];
  printf("%s\n",name );
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
  if (!writePgm(fichier,name)) {
    printf("Succesfully copied file to %s\n",name);
  }
  freeImage(fichier);
  return 0;
}
