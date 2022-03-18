#include "pgm.h"

int main(int argc,char** argv) { //arg 1 nom image || arg2 seuil

  if(!argv[1]||!argv[2]||atoi(argv[2])<0||argc!=3){
    printf("Utilisation du programme : test_pgm_threshold <file.pgm> <threshold>\n");
    return -1;
  }
// Test seuil manuel
  int threshold=atoi(argv[2]);
  image fichier = readPgm(argv[1]);
  manual_threshold(fichier,threshold);
  writePgm(fichier, "manual_threshold.pgm");
  freeImage(fichier);
//Test seuil auto
  int calulated_threshold=0;
  image fichier2 = readPgm(argv[1]);
  calulated_threshold=auto_threshold(fichier2);
  printf("Calculated threshold = %d\n",calulated_threshold);
  writePgm(fichier2,"auto_threshold.pgm");
  freeImage(fichier2);
  return 0;
}
