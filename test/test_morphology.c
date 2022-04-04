#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_morphology <mode> <image1.pgm> \n modes : \"er\" Erode || \"ex\" dilatation || \"re\" reconstruction\n");
    return -1;
  }

  if (!strcmp( argv[1], "er" ) ||
      !strcmp( argv[1], "ER" ) ) {
        image fichier;
        fichier=readPgm(argv[2]);
        fichier=erode(fichier);
        writePgm(fichier,"eroded.pgm");
        freeImage(fichier);
        printf("Erosion done\n");
        return 0;
  }

  if (!strcmp( argv[1], "ex" ) ||
      !strcmp( argv[1], "EX" ) ) {
        image fichier;
        fichier=readPgm(argv[2]);
        fichier=expanse(fichier);
        writePgm(fichier,"expansed.pgm");
        freeImage(fichier);
        printf("Expansion done\n");
        return 0;
  }


  if (!strcmp( argv[1], "re" ) ||
      !strcmp( argv[1], "re" ) ) {
        image fichier,seed;
        fichier=readPgm(argv[2]);
        seed=readPgm(argv[3]);
        fichier=reconstruct(fichier,seed);
        writePgm(fichier,"reconstructed.pgm");
        freeImage(fichier);
        printf("Reconstruction done\n");
        return 0;
  }
  else{
    printf("Nothing to be done\n");
  }
}
