#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_morphology <mode> <image1.pgm> \n modes : \"e\" Erode || \"d\" dilatation\n");
    return -1;
  }

  if (!strcmp( argv[1], "er" ) ||
      !strcmp( argv[1], "ER" ) ) {
    image fichier,output;
    fichier=readPgm(argv[2]);
    output=fichier;
    output=allocate(output);
    erode(fichier,output);
    writePgm(output,"eroded.pgm");
    freeImage(fichier);
    freeImage(output);
    printf("Erosion done\n");
    return 0;
  }

if (!strcmp( argv[1], "ex" ) ||
    !strcmp( argv[1], "EX" ) ) {
      image fichier,output;
      fichier=readPgm(argv[2]);
      output=fichier;
      output=allocate(output);
      expanse(fichier,output);
      writePgm(output,"expansed.pgm");
      freeImage(output);
      printf("Expansion done\n");
      return 0;
  }


if (!strcmp( argv[1], "re" ) ||
    !strcmp( argv[1], "re" ) ) {
      image fichier,seed,output;
      fichier=readPgm(argv[2]);
      seed=readPgm(argv[3]);
      output=fichier;
      output=allocate(output);
      reconstruct(fichier,seed,output);
      writePgm(output,"reconstructed.pgm");
      freeImage(output);
      printf("Reconstruction done\n");
      return 0;
    }
else{
    printf("Nothing to be done\n");
  }
}
