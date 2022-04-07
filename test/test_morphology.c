#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_morphology <mode> <image1.pgm> \n modes : \"er\" Erode || \"ex\" dilatation || \"re\" reconstruction\n");
    return -1;
  }

  if (!strcmp( argv[1], "er" ) ||
      !strcmp( argv[1], "ER" ) ) {
        image fichier,output;
        fichier=readPgm(argv[2]);
        output=fichier;
        output=allocate(output);
        output=erode(fichier,output);
        writePgm(fichier,"eroded.pgm");
        freeImage(fichier);
        freeImage(output);
        printf("Erosion done\n");
        return 0;
  }

  if (!strcmp( argv[1], "ex" ) ||
      !strcmp( argv[1], "EX" ) ) {
        image fichier,expansed;
        fichier=readPgm(argv[2]);
        expansed=fichier;
        expansed=allocate(expansed);
        expansed=expanse(fichier,expansed);
        writePgm(fichier,"expansed.pgm");
        freeImage(fichier);
        freeImage(expansed);
        printf("Expansion done\n");
        return 0;
  }


  if (!strcmp( argv[1], "re" ) ||
      !strcmp( argv[1], "re" ) ) {
        image fichier,seed;
        fichier=readPgm(argv[2]);
        seed=readPgm(argv[3]);
        image output={fichier.width,fichier.height,fichier.depth,0};
        output=reconstruct(fichier,seed,output);
        writePgm(output,"reconstructed.pgm");
        printf("Reconstruction done\n");
        freeImage(fichier);
        freeImage(output);
        freeImage(seed);
        return 0;
  }

  if (!strcmp( argv[1], "uer" ) ||
      !strcmp( argv[1], "UER" ) ) {
        image fichier, eroded;
        fichier=readPgm(argv[2]);
        eroded=fichier;
        eroded=allocate(eroded);
        eroded=ultimate_erode(fichier, eroded);
        writePgm(eroded,"utlimate_eroded.pgm");
        freeImage(fichier);
        freeImage(eroded);
        printf("Ultimate Erosion done\n");
        return 0;
  }
  else{
    printf("Nothing to be done\n");
  }
}
