#include "library.h"

int main(int argc, char** argv){

  if (argc<2) {
    printf("utilisation : test_image_processing <mode> <image1.pgm> \n modes : \"b\" remove border cells || \"h\" remplissage des trous || \"mer\" erosion manuelle || \"genseed\" generateur de seed\n");
    return -1;
  }

  if (!strcmp( argv[1], "b" ) ||
      !strcmp( argv[1], "B" ) ) {
        image fichier;
        fichier=readPgm(argv[2]);
        image output=fichier;
        output=allocate(output);
        output=delete_edge_cell(fichier,output);
        writePgm(output,"border_cells_removed.pgm");
        freeImage(fichier);
        freeImage(output);
        printf("Border cells removed\n");
        return 0;
  }

  if (!strcmp( argv[1], "h" ) ||
      !strcmp( argv[1], "H" ) ) {
        image fichier,result;
        fichier=readPgm(argv[2]);
        result=fichier;
        result=allocate(result);
        result=hole_plugging(fichier,result);
        writePgm(result,"holes_plugged.pgm");
        freeImage(fichier);
        freeImage(result);
        printf("Holes plugged\n");
        return 0;
  }

  if (!strcmp( argv[1], "mer" ) ||
      !strcmp( argv[1], "MER" ) ) {
        image fichier;
        int rep=atoi(argv[3]);
        fichier=readPgm(argv[2]);
        fichier=manual_erosion(fichier,rep);
        writePgm(fichier,"man_eroded.pgm");
        freeImage(fichier);
        printf("Manual erosion done\n");
        return 0;
  }
  if (!strcmp( argv[1], "genseed" ) ||
      !strcmp( argv[1], "GENSEED" ) ) {
        image fichier,seed;
        fichier=readPgm(argv[2]);
        seed=fichier;
        seed=allocate(seed);
        seed=generate_frame_seed(fichier.width,fichier.height,seed);
        writePgm(fichier,"generated_seed.pgm");
        freeImage(fichier);
        freeImage(seed);
        printf("seed generated\n");
        return 0;
  }
  else{
    printf("Nothing to be done\n");
    return 0;
  }
}
