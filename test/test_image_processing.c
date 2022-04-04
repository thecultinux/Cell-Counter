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
        fichier=delete_edge_cell(fichier);
        writePgm(fichier,"border_cells_removed.pgm");
        freeImage(fichier);
        printf("Border cells removed\n");
        return 0;
  }

  if (!strcmp( argv[1], "h" ) ||
      !strcmp( argv[1], "H" ) ) {
        image fichier;
        fichier=readPgm(argv[2]);
        fichier=hole_plugging(fichier);
        writePgm(fichier,"holes_plugged.pgm");
        freeImage(fichier);
        printf("Holes plugged\n");
        return 0;
  }

  if (!strcmp( argv[1], "mer" ) ||
      !strcmp( argv[1], "MER" ) ) {
        image fichier;
        int rep;
        fichier=readPgm(argv[2]);
        printf("Donner le nombre d'érosions\n" );
        scanf("%d\n", &rep );
        fichier=manual_erosion(fichier,rep);
        writePgm(fichier,"man_eroded.pgm");
        freeImage(fichier);
        printf("Manual erosion done\n");
        return 0;
  }
  if (!strcmp( argv[1], "genseed" ) ||
      !strcmp( argv[1], "GENSEED" ) ) {
        image fichier;
        fichier=readPgm(argv[2]);
        fichier=generate_frame_seed(fichier.width,fichier.height);
        writePgm(fichier,"generated_seed.pgm");
        freeImage(fichier);
        printf("seed generated\n");
        return 0;
  }
  else{
    printf("Nothing to be done\n");
    return 0;
  }
}
