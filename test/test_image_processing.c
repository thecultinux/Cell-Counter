#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_image_processing <mode> <image1.pgm> \n modes : \"b\" remove border cells || \"h\" remplissage des trous\n");
    return -1;
  }

  if (!strcmp( argv[1], "b" ) ||
      !strcmp( argv[1], "B" ) ) {
    image fichier;
    fichier=readPgm(argv[2]);
    fichier=erode(fichier);
    writePgm(fichier,"border_cells_removed.pgm");
    freeImage(fichier);
    printf("Border cells removed\n");
    return 0;
  }
  else{
      printf("Nothing to be done\n");
    }
  }
