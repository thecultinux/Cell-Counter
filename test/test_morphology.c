#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_morphology <mode> <image1.pgm> \n modes : \"e\" Erode || \"d\" dilatation\n");
    return -1;
  }

  if (!strcmp( argv[1], "er" ) ||
      !strcmp( argv[1], "ER" ) ) {
    image fichier,eroded;
    fichier=readPgm(argv[2]);
    erode(fichier);
    eroded=erode_(fichier);
    writePgm(fichier,"eroded.pgm");
    writePgm(eroded,"eroded_.pgm");
    freeImage(fichier);
    freeImage(eroded);
    printf("Erosion done\n");
    return 0;
  }

if (!strcmp( argv[1], "ex" ) ||
    !strcmp( argv[1], "EX" ) ) {
      image fichier,expansed;
      fichier=readPgm(argv[2]);
      expanse(fichier);
      expansed=expanse_(fichier);
      writePgm(fichier,"expansed.pgm");
      writePgm(expansed,"expansed_.pgm");
      freeImage(fichier);
      freeImage(expansed);
      printf("Expansion done\n");
      return 0;
  }
}
